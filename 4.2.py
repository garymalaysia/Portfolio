import hashlib
from array import *
import re
from cryptacular.bcrypt import BCRYPTPasswordManager


#file = open('/Users/garytsai/Desktop/SecLists/Passwords/10_million_password_list_top_20000000.txt', 'r')
#words = re.findall('\w+', open('/Users/garytsai/Desktop/SecLists/Passwords/rockyou.txt', encoding='latin-1').read().lower())
#s=file.read()
#k=s.split()

#hashes you are looking for

#hashes=['9ed7c7b0369c6c4578071494af4b67f1','827ccb0eea8a706c4c34a16891f84e7b','74b0328a08e7d9e213b1ea77ba32198d','6f0bd5945fbd8754c1c164b7ef12df47','58812d3bf4fe604bbf2073c03f477148','9c5e221dda6e892d55524e100a3daec4']
hashes1=['ee38347c99d9903d34cbc74b2ed21d3d6b927941', '1e1e3244cfd63d1233ce9b7a098acadbab64836f','7b7a8d8e9435d1064967f8ba2a43eee1f7804f5e','835bef07a75eb9b6ad98dcc2df9e505d119df46f','1b1a52fb9b0791e0211c2af0d3155b80ac40405b']
#hashes=['f573b7dd8369faa58368bb167539106ff0e1e027']
#hashes2=['0a4628c5ae0771b1d27ac71e2d2574dec4174f35fa0a6c5e7e0f98871fbcc657']
#hash4_4_2=['c658beb1c91a122b6e07ae85a8c39345']
hashed4_4_5=['90a9bb13cb598830e831c23d006a3f005c6db1651eefde3e79aff639cea957f2773e9406ea6df27b387568e6694cd8feefdd4b98362b6bb25ed17bc42585c27d']
hashed4_4_6=['$2y$05$rJ0NSweJUgBMks1U/15lu.2GGMpb94e3OFGqaZamb3vaT6Xsd4LQq']
#k= hashlib.md5(b"TimeTest").hexdigest()
#print (k)

#md5 hash
def hashed_md5(z):
	hashed= hashlib.md5(b"%s" % z).hexdigest()
	print(hashed)

def ripemd(x):
	p = hashlib.new('ripemd160', x.encode('utf-8')).hexdigest()
	print(p)

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

def ripemd160(x):
	for i in range(len(x)):
		for Hash in k:
			m = hashlib.new('ripemd160', Hash.encode('utf-8')).hexdigest()
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

def cryptacular():
	manager = BCRYPTPasswordManager()
	hashed = manager.encode('password')
	if manager.check(hashed, 'password'):
		print(hashed)


#md5hash(hash4_4_2)
#sha_1hash(hashes1)
#sha_224hash(hashes)
#sha_256hash(hashes2)
#sha_384hash(hashes)
#sha_512hash(hashed4_4_5)
#openssl(hashes)
#ripemd160(hashes)
#ripemd('')
#cryptacular()
