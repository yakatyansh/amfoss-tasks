# All the essential steps required for the completion of this task

## Linux

 1. mkdir coordinates-locations
 
 2. cd coordinates-locations
 
 3. mkdir North
 
 4. cd North
 
 4. touch NDegrees.txt
 
 5. used echo "9°" >> NDegrees.txt (this method is convenient for at max a single sentence text.Use text editors like nano for larger files).
  
 6. touch NMinutes.txt (this step and steop 4 can be avoided if you are using nano just write nano filename.txt )
 
 7. echo "5' ">> NMinutes.txt
 
 8. touch Nseconds.txt
 
 9. echo ' 2.1" '>> NSeconds.txt
 
 10. cat NDegrees.txt NMinutes.txt NSeconds.txt >> NorthCoordinate.txt
 
 11. mv NorthCoordinate.txt ../North.txt
 
 12. rm -r North
 
 13. mkdir East 
 
 14. touch EDegree.txt
 
 15. echo "76°" >> EDegree.txt
 
 16. touch EMinutes.txt
 
 17. echo "29' " >> EMinutes.txt
 
 18. touch ESeconds.txt
 
 19. echo ' 30.8" '
 
 20. cat EDegrees.txt EMinutes.txt ESeconds.txt >> EastCoordinate.txt
 
 21. mv EastCoordinate.txt ../East.txt
 
 22. rm -r East

23. cat North.txt >> Location-Coordinate.txt

24. cat East.txt >> Location-Coordinate.txt

## Git

1. cd ..

2. cd ..

3. git add Task-2

4. git commit -m "your commit message here"

5. git status

6. git push -u amfoss-tasks (or git push origin master by setting the origin as the repository link and pushing the files in the master branch)

7. git remote set-url origin git@github.com:User/UserRepo.git (this is how to set origin)
