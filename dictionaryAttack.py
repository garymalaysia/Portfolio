
# Use command line : head -n 400000 /usr/share/dict/words>> AllEng.txt

from array import *

file = open('AllEng.txt', 'r')
s=file.read()
k=s.split()

hex_dig2="310ad168068d5238e800eacebf53b791adfd272fadbe8327c0271b3bdaf77f26c17439049b3e109a39ded40b7b12b27c114bf950efa1dfb566ad497a8a2efb99"

#print s
for line in k:
    #line=[s]
    #print line
    
    import hashlib
    hash_object = hashlib.sha512(line)
    hex_dig = hash_object.hexdigest()
    if hex_dig == hex_dig2:
        print line
        print hex_dig
# Project
