package main

import (
	"encoding/csv"
	"log"
	"os"

	"github.com/PuerkitoBio/goquery"
	"github.com/geziyor/geziyor"
	"github.com/geziyor/geziyor/client"
)

func main() {

	csvdata := [][]string{
		{"net_worth", "age", "country/territory", "Sorce"},
	}
	geziyor.NewGeziyor(&geziyor.Options{
		StartRequestsFunc: func(g *geziyor.Geziyor) {
			g.GetRendered("https://www.forbes.com/real-time-billionaires/", g.Opt.ParseFunc)
		},
		ParseFunc: func(g *geziyor.Geziyor, r *client.Response) {
			r.HTMLDoc.Find("tr.base.ng-scope").Each(func(i int, s *goquery.Selection) {
				if i < 10 {
					csvdata = append(csvdata, []string{s.Find("td.Net.Worth").Text(), s.Find("td.age").Text(), s.Find("td.Country\\/Territory").Text(), s.Find("td.source").Text()})
				}
			})
		},
	}).Start()

	csvFile, err := os.Create("data.csv")
	if err != nil {
		log.Fatalf("failed creating file: %s", err)
	}
	csvwriter := csv.NewWriter(csvFile)
	for _, entry := range csvdata {
		_ = csvwriter.Write(entry)
	}
	csvwriter.Flush()
	csvFile.Close()
}
