import socket
import time
s = socket.socket()
port = 12345           
recInterval = int(input('Enter the receive Interval'))
s.connect(('127.0.0.1', port))
while True : 
	print('At', time.time() , '\nreceived ',s.recv(1500), 'data')
	time.sleep(recInterval // 1000)
