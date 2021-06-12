git checkout -b main
git push origin main
git branch -D master
git branch -D MERGE
git pull
git checkout -b temp
git branch -D main
git fetch
git checkout -t origin/master
git branch
git branch -D temp
git branch master

git log 

hitsory


