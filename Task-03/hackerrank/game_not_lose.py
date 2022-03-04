Num,Max=map(int,input().split())
list=[]
i=1
while i<=Max:
    list.append(i) 
    i=i+2
print(len(list))    
print(*list)        