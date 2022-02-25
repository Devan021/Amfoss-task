import argparse
import requests
import urllib.request

parser = argparse.ArgumentParser(description='Fetching image')
parser.add_argument('id',type=int,help='Enter id')
parser.add_argument('date',help='Enter date')
args = parser.parse_args()
id = args.id
date = str(args.date)
url = 'https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos?earth_date=2015-6-3&api_key=bCwf9dhDPfHkdlhCBEU60k5YA6EabDTtno2pvKgS'
r = requests.get(url)
data = r.json()
data = data['photos']
i = 0
while True:
    try:
        if data[i]['id'] == id:
            urllib.request.urlretrieve(data[i]['img_src'], "/home/devan/Downloads/cli/get-image.jpg")
            break
        i += 1
    except EOFError:
        break






