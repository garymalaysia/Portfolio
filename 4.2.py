import hashlib
from array import *
import re


file = open('/Users/garytsai/Desktop/SecLists/Passwords/10_million_password_list_top_20000000.txt', 'r')
#words = re.findall('\w+', open('/Users/garytsai/Desktop/SecLists/Passwords/rockyou.txt', encoding='latin-1').read().lower())
s=file.read()
k=s.split()

#hashes you are looking for

#hashes=['9ed7c7b0369c6c4578071494af4b67f1','827ccb0eea8a706c4c34a16891f84e7b','74b0328a08e7d9e213b1ea77ba32198d','6f0bd5945fbd8754c1c164b7ef12df47','58812d3bf4fe604bbf2073c03f477148','9c5e221dda6e892d55524e100a3daec4']
hashes1=['ee38347c99d9903d34cbc74b2ed21d3d6b927941', '1e1e3244cfd63d1233ce9b7a098acadbab64836f','7b7a8d8e9435d1064967f8ba2a43eee1f7804f5e','835bef07a75eb9b6ad98dcc2df9e505d119df46f','1b1a52fb9b0791e0211c2af0d3155b80ac40405b']
#hashes=['58812d3bf4fe604bbf2073c03f477148']
#k= hashlib.md5(b"TimeTest").hexdigest()
#print (k)

#md5 hash
def hashed_md5(z):
	hashed= hashlib.md5(b"%s" % z).hexdigest()
	print(hashed)

#look for md5 text
def md5hash(x):
	for i in range(len(x)):
		for Hash in k:
			m = hashlib.md5(Hash.encode('utf-8')).hexdigest()
			if m == x[i]:
				print (Hash)

#look for sha1 text
def sha_1hash(x):
	for i in range(len(x)):
		for Hash in k:
			m = hashlib.sha1(Hash.encode('utf-8')).hexdigest()
			if m == x[i]:
				print (Hash)
#look for SHA224 text
def sha_224hash(x):
	for i in range(len(x)):
		for Hash in k:
			m = hashlib.sha224(Hash.encode('utf-8')).hexdigest()
			if m == x[i]:
				print (Hash)
#look for SHA256
def sha_256hash(x):
	for i in range(len(x)):
		for Hash in k:
			m = hashlib.sha256(Hash.encode('utf-8')).hexdigest()
			if m == x[i]:
				print (Hash)

#look for SHA384
def sha_384hash(x):
	for i in range(len(x)):
		for Hash in k:
			m = hashlib.sha384(Hash.encode('utf-8')).hexdigest()
			if m == x[i]:
				print (Hash)
#look for SHA512
def sha_512hash(x):
	for i in range(len(x)):
		for Hash in k:
			m = hashlib.sha512(Hash.encode('utf-8')).hexdigest()
			if m == x[i]:
				print (Hash)
#look for openssl
def openssl(x):
	for i in range(len(x)):
		for Hash in k:
			hash_object=hashlib.new('DSA')
			m = hash_object.update(Hash.encode('utf-8')).hexdigest()
			if m == x[i]:
				print (Hash)

def arr(y):
	for i in range(len(y)):
		print (hashes[i])

def count(texts):
	for Hash in texts:
		m = hashlib.md5(Hash.encode('utf-8')).hexdigest()
		count+=1
	print (count)

#md5hash(hashes)
sha_1hash(hashes1)
#sha_224hash(hashes)
#sha_256hash(hashes)
#sha_384hash(hashes)
#sha_512hash(hashes)
#openssl(hashes)

