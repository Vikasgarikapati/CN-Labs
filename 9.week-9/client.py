import socket
import time

c = socket.socket()
c.connect(('localhost', 9999))
while True:
    # c.send('Hello To the server '.encode())
    msg = ''
    with open('input.txt', 'r') as ip:
        msg = ip.read()
    msg += '\n'
    # print(msg)
    c.send(msg.encode())
    data = c.recv(1024)
    print(data.decode())
    time.sleep(1)
    # c.close()
    break
