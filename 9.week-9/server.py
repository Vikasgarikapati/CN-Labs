import socket

s = socket.socket()
s.bind(('localhost', 9999))
print('Server Created')

s.listen(1)
print('Server is Listening.....')
while True:
    c, addr = s.accept()
    print('Connected to : ', addr)
    while True:
        data = c.recv(1024)
        if not data:
            break
        msg = data.decode()
        msg = msg.split('\n')[0]
        print(msg)
        lines = len(msg.split('.'))
        chars = len(msg)
        words = len(msg.split())
        clientMsg = 'Lines: {}\nChars: {}\nWords: {}'.format(
            lines, chars, words)
        c.send(clientMsg.encode())
        break
