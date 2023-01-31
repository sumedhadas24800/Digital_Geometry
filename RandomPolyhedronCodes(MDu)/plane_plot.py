import numpy as np
from mpl_toolkits.mplot3d import axes3d
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import matplotlib.pyplot as plt

f = open("file-1.txt", "r")
lines = f.readlines()
content = []
serialNos = set()
for line in lines:
	content.append(list(map(float, line.split())))
	serialNos.add(content[-1][0])

nSerials = len(serialNos)

coord = [[] for i in range(nSerials)]

for row in content:
	coord[int(row[0])].append(row[2:5])

for i in range(len(coord)):
	first_element=coord[i][0][:]
	coord[i].append(first_element)

fig = plt.figure(num=1, clear=True, edgecolor='black')
ax = fig.add_subplot(1,1,1, projection='3d')


xs=[[] for i in range(len(coord))]
ys=[[] for i in range(len(coord))]
zs=[[] for i in range(len(coord))]

for i in range(len(coord)):
	xs[i], ys[i], zs[i] = zip(*coord[i]) 

for i in range(len(coord)):
	plt.plot(xs[i],ys[i],zs[i]) 

verts=[[] for i in range(len(coord))]

for i in range(len(coord)):
	verts[i]=[list(zip(xs[i],ys[i],zs[i]))]

ax.set(xlabel='x', ylabel='y', zlabel='z')
ax.grid(False)
plt.axis('off')

ax.scatter3D([0,-1],[1,0],[-1,0],color='black',alpha = 1.0,marker='^')

for i in range(len(coord)):
	store = Poly3DCollection(verts[i], linewidths=1, edgecolors='black', alpha=0.7)
	store.set_facecolor('yellow')
	ax.add_collection3d(store) 

#x1=[1,0]
#y1=[-2,1]
#z1=[-2,0]
#ax.plot3D(x1,y1,z1)

plt.show()

