#/usr/bin/python

import Image
import sys
import ImageDraw
import ImageFont
filename = sys.argv[1]
fontpath = "/home/longxin/.fonts/Myuppy.ttf"
sans16 = ImageFont.truetype(fontpath,16)

img = Image.open(filename,'r')
size = img.size
draw = ImageDraw.Draw(img)
draw.text((size[0]-120,size[1]-20),"By longxin CAS",font=sans16)
img.show()
