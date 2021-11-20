# DETAILED TERMINAL COMMANDS

    Step1:       mkdir Coordinates-Location
    Step2:       cd Coordinates-Location
    Step3:       mkdir North
    Step4:       cd North
    Step5:       touch NDegree.txt
    Step6:       gedit NDegree.txt
    Step7:       cat NDegree.txt
    Step8:       touch NMinutes.txt
    Step9:       gedit NMinutes.txt
    Step10:      cat NMinutes.txt
    Step11:      touch NSeconds.txt
    Step12:      gedit NSeconds.txt
    Step13:      cat NSeconds.txt
    Step14:      cat NDegree.txt NMinutes.txt cat NSeconds.txt > NorthCoordinate.txt
    Step15:      mv Northcoordinate.txt/Coordinates-Location ( I wanted to move the NorthCoordinate.txt into the Coordinates location but i didnt know the exact mv syntax so i manually moved it i m sorry)
    Step16:      mv Northcoordinate.txt North.txt(i renamed it to North.txt)
    Step17:      cd
    Step18:      cd Coordinates-Location
    Step19:      mkdir East
    Step20:      cd East
    Step21:      touch EDegree.txt
    Step22:      gedit EDegree.txt
    Step23:      cat EDegree.txt
    Step24:      touch EMinutes.txt
    Step25:      gedit EMinutes.txt
    Step26:      cat EMinutes.txt
    Step27:      touch ESeconds.txt
    Step28:      gedit ESeconds.txt
    Step29:      cat ESeconds.txt
    Step30:      cat EDegree.txt Eminutes.txt ESeconds.txt > EastCoordinate.txt (i moved the EastCoordinate.txt  to Coordinates-Location from East directory)
    Step31:      mv EastCoordinate.txt East.txt(I renamed it)
    Step32:      cat North.txt East.txt > Location-Coordinates.txt
    Step33:      touch finalcoordinate.txt (now i created a finalcoordinate.txt file to store the values of coordinates)
    
    
    
  ##GIT TERMINAL COMMANDS
     
     ** I haved already cloned my repo into my local machine and its in a directory Amfoss-task
       Step1: First i will move the Coordinate-Location directory into Amfoss-task directory 
       Step2: cd Amfoss-Task(I went to the local repo directory)
       Step3: git init(to initialize the repo)
       Step4: git add .(the '.' adds all the changes made to the local repo)
       Step5: git commit -m "first commit"(to commit changes)
       Step6: git status(to check my branch - my branch is master)
       Step7:git push -u origin master(pushes the local repo into my github repo) **
                     
