
from types import ClassMethodDescriptorType


def evenParity(msg) :
    n = 0
    for i in msg:
        if i == "1":
            n += 1
    if n % 2 == 0:
        msg += "0"
    else : 
        msg += "1"
    return msg

def checkParity(msg) :
    n = 0
    for i in msg:
        if i == "1":
            n += 1
    if n % 2 == 0:
        return True
    return False


def transmit(rows,cols) :
    msg = []
    print("Enter the msg to be transmitted : ")
    for i in range(rows) :
        msg.append(evenParity(input()))
        if len(msg[-1]) != cols + 1 : 
            print("Not acceptable length")
            return 
    colParity = ""
    for i in range(cols+1) :
        n = 0 
        for j in range(rows) :
            if msg[j][i] == "1" :
                n += 1
        if n % 2 == 0 :
            colParity += "0"
        else : 
            colParity += "1"
    msg.append(colParity)

    print("The Transmitted Message is : ",end = " ")
    for i in range(rows+1):
        print(msg[i],end="")
    print("")
    rec = input("Enter the Receiced Message : ")

    if len(rec) != (cols+1) * (rows+1) :
        print("Invalid length!")
    msg = []
    j = 0
    for i in range(rows+1) :
        msg.append(rec[j*(cols+1): (j+1)*(cols+1)])
        j += 1
        
    #check the row parity 
    print(msg)
    for row in msg : 
        
        if not checkParity(row) : 
            print("Error Detected")
            return 
    for i in range(cols+1) :
        m = ""
        for j in range(rows+1) :
            m += msg[j][i]
        if not checkParity(m) : 
            print("Error Detected")
            return 

    print("No Error Detected")



if __name__ == "__main__" :
    rows = int(input("Enter the number of Chunks             : "))
    cols = int(input("Enter the number of Bits in Each Chunk :"))
    transmit(rows,cols)
