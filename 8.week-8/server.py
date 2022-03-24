import socket
import time
s = socket.socket()
port = int(input('Port Number to start the server'))
s.bind(('',port))
print('socket bined to port :-',port)
s.listen(5)
print('Server started to listen')
while True : 
	c, addr = s.accept()
	print('Got connection from ', addr)
	data = '#' * 1500
	sendInterval = int(input('Send Interval : (in ms) : '))
	while True :
		print('At time ', time.time(), 'send 1500 bytes of data') 
		c.send(data.encode())
		time.sleep(sendInterval // 1000)
		
