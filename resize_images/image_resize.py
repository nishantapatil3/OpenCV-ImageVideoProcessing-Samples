import os, sys
from PIL import Image

def resize(item):
    foo = Image.open("sample/" + item)
    print foo.size
    foo = foo.resize((396,264),Image.ANTIALIAS)
    w, h = foo.size
    foo = foo.crop((30, 0, w-30, h))
    foo.save("sample/samplesresized/" + item ,optimize=True,quality=95)

path = ("sample/")
for item in os.listdir(path):
    if os.path.isfile("sample/" + item):
        resize(item)
