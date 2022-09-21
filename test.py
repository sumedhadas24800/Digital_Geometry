def allow_vertex(v):
    x1=v[0]
    y1=v[1]
    z1=v[2]
    f=0
    
    #vertex sharing voxel 1
    x2=x1-1
    y2=y1-1
    z2=z1-1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False
        
    #vertex sharing voxel 2
    x2=x1-1
    y2=y1-1
    z2=z1+1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False
    
    #vertex sharing voxel 3
    x2=x1-1
    y2=y1+1
    z2=z1-1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False

    #vertex sharing voxel 4
    x2=x1-1
    y2=y1+1
    z2=z1+1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False
        
    #vertex sharing voxel 5
    x2=x1+1
    y2=y1-1
    z2=z1-1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False
    
    #vertex sharing voxel 6
    x2=x1+1
    y2=y1-1
    z2=z1+1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False
    
    #vertex sharing voxel 7
    x2=x1+1
    y2=y1+1
    z2=z1-1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False
    
    #vertex sharing voxel 8
    x2=x1+1
    y2=y1+1
    z2=z1+1
    if [x2,y2,z2] in store:
        f=1
        if [x1,y2,z2] not in store and [x2,y1,z2] not in store and [x2,y2,z1] not in store and [x2,y1,z1] not in store and [x1,y2,z1] not in store and [x1,y1,z2] not in store:
            return False
        
    
    return True

def allow_edge(v):
    x1=v[0]
    y1=v[1]
    z1=v[2]
    
    #edge sharing voxel 1
    x2=x1+0
    y2=y1-1
    z2=z1-1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x1,y2,z1] not in store:
            return False
    
    #edge sharing voxel 2
    x2=x1+0
    y2=y1-1
    z2=z1+1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x1,y2,z1] not in store:
            return False
    
    #edge sharing voxel 3
    x2=x1+0
    y2=y1+1
    z2=z1-1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x1,y2,z1] not in store:
            return False
    
    #edge sharing voxel 4
    x2=x1+0
    y2=y1+1
    z2=z1+1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x1,y2,z1] not in store:
            return False
    
    #edge sharing voxel 5
    x2=x1-1
    y2=y1+0
    z2=z1-1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x2,y1,z1] not in store:
            return False
    
    #edge sharing voxel 6
    x2=x1-1
    y2=y1+0
    z2=z1+1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x2,y1,z1] not in store:
            return False
    
    #edge sharing voxel 7
    x2=x1+1
    y2=y1+0
    z2=z1-1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x2,y1,z1] not in store:
            return False
    
    #edge sharing voxel 8
    x2=x1+1
    y2=y1+0
    z2=z1+1
    if [x2,y2,z2] in store:
        if [x1,y1,z2] not in store and [x2,y1,z1] not in store:
            return False
    
    #edge sharing voxel 9
    x2=x1-1
    y2=y1-1
    z2=z1+0
    if [x2,y2,z2] in store:
        if [x1,y2,z1] not in store and [x2,y1,z1] not in store:
            return False
    
    #edge sharing voxel 10
    x2=x1-1
    y2=y1+1
    z2=z1+0
    if [x2,y2,z2] in store:
        if [x1,y2,z1] not in store and [x2,y1,z1] not in store:
            return False
    
    #edge sharing voxel 11
    x2=x1+1
    y2=y1-1
    z2=z1+0
    if [x2,y2,z2] in store:
        if [x1,y2,z1] not in store and [x2,y1,z1] not in store:
            return False
    
    #edge sharing voxel 12
    x2=x1+1
    y2=y1+1
    z2=z1+0
    if [x2,y2,z2] in store:
        if [x1,y2,z1] not in store and [x2,y1,z1] not in store:
            return False
    
    return True
    
#%matplotlib notebook 
import matplotlib.pyplot as plt
import numpy as np
import random
from mpl_toolkits.mplot3d import Axes3D
N=50 #Number of voxels to be plotted
limit=40
x,y,z=int(limit/2),int(limit/2),int(limit/2)
#print(x,y,z)
k=[x,y,z]
store=[]
store.append(k)
c=0
while c<N:
    l=[]
    
    #choosing Random voxel
    rand_ref=random.choice(store)
    x=rand_ref[0]
    y=rand_ref[1]
    z=rand_ref[2]
    
    v0=[x+1,y,z]
    v1=[x,y+1,z]
    v2=[x,y,z+1]
    v3=[x-1,y,z]
    v4=[x,y-1,z]
    v5=[x,y,z-1]
    
    l.append(v0)
    l.append(v1)
    l.append(v2)
    l.append(v3)
    l.append(v4)
    l.append(v5)
    
    #print(l,"r")
    #Choosing random face of Chosen voxel
    rand=random.choice(l)
    
    #print(rand)
    if rand not in store and allow_vertex(rand) and allow_edge(rand):
        store.append(rand)
        x=rand[0]
        y=rand[1]
        z=rand[2]
        c+=1
#File Handling and storing the dataset in .txt file
f=open('voxel_dataset.txt','w+')
for i in range(len(store)):
    f.write("%d " %store[i][0])
    f.write("%d " %store[i][1])
    f.write("%d " %store[i][2])
    f.write("\n")
f.truncate()

print(store)

#plotting the points
X,Y,Z=np.indices((limit,limit,limit))
vi=(X==store[0][0])&(Y==store[0][1])&(Z==store[0][2])
v=(X==x)&(Y==y)&(Z==z)
#print(x,y,z)
#print(v)
#print("k")
for i in range(len(store)):
    x1,y1,z1=store[i][0],store[i][1],store[i][2]
    v[x1,y1,z1]=True
#print(v)
vf=(X==x1)&(Y==y1)&(Z==z1)
ax = plt.figure().add_subplot(projection='3d')
ax.voxels(v, facecolors='red', edgecolor='black')
ax.voxels(vf, facecolors='red', edgecolor='black')
ax.voxels(vi, facecolors='red', edgecolor='black')
# ax.text(store[0][0],store[0][1],store[0][2],"Start Voxel",zdir='x',color='k')
# ax.text(x1,y1,z1,"End Voxel",zdir='x',color='k')

#setting the limits
ax.set_xlim(0,limit)
ax.set_ylim(0,limit)
ax.set_zlim(0,limit)
# ax.set_xlabel("X-axis")
# ax.set_ylabel("Y-axis")
# ax.set_zlabel("Z-axis")
plt.axis('off')
ax.can_zoom()
ax.can_pan()
plt.savefig('voxel.pdf',dpi=300,bbox_inches='tight')
plt.show()