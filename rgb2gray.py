#\usr\bin\python
import Image
import sys

try:
    filename = sys.argv[1]
    outfile = sys.argv[2]
except IndexError:
    print "missing parameter"
    exit()
    

img=Image.open(filename,'r')
size = img.size
nimg=Image.new('L',size)

for i in range(size[0]):
    for j in range(size[1]):
        a = img.getpixel((i,j))
        tmp = a[0]*0.299+0.587*a[1]+0.114*a[2]
        tmp = int(tmp)
        nimg.putpixel((i,j),tmp)

nimg.save(outfile)
