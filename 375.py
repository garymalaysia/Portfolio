import _thread
import random
import threading
import queue # using queue to perform FIFO

b = []
arrResult=queue.Queue()
class myThread (threading.Thread):
    def __init__(self, x,y,_in,_out):
        threading.Thread.__init__(self)
        self.x= x
        self.y = y 
        self._in = _in
        self._out = _out
        

    def run(self):
    	producer(self.x,self.y,self._in,self._out)

class myThread2(threading.Thread):
	def __init__(self,buff_size,_out):
		threading.Thread.__init__(self)
		self.size=buff_size
		self.count=_out
	def run(self):
		consumer(self.size,self.count)

def producer(x,y,_in,_out):#putting item into buffer
	while y<=x :
		while (_in +1)%int(x) <_out:
			print ("Buffer is FULL!!")
			break
		rand=random.randrange(0,100)
		arrResult.put(rand)
		y = int(y)+1
		_in = (_in +1)% int(x)
	

def consumer (buff_size,_out):# taking item out of buffer
	count=buff_size
	while _out<count:
		b.append(arrResult.get())
		_out+=1# this is the incrementing the count
	print ("Buffer is empty")
	b.sort()
	print(b)


buffer_size=int(input("Please input a Buffer Size: "))
count= int(input("Please input a counter: "))
_in = 0
_out = 0


# Create new threads
thread1 = myThread(buffer_size, count,_in,_out)# running first thread
thread2 = myThread2(buffer_size,count)# running Second Thread

# Start new Threads
thread1.start()
thread2.start()
thread1.join()
thread2.join()
print ("Exiting Main Thread")