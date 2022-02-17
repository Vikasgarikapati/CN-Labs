
def transmit(msg) :
    n = 0 
    for i in msg : 
        if i == "1" :
            n += 1
    if n % 2 == 0 : 
        msg += "0"
    print("The Message Transmitted is : " , msg)


def VRC(msg) :
    n = 0
    for i in msg:
        if i == "1":
            n += 1
    if n % 2 == 0 :
        print("No Error Detected by Vertical Redundancy Check")
        return 
    print("Error Detected by Vertical Redundancy Check")
    


if __name__ == "__main__" :
    msg = input("Enter the Message : ")
    print("-------Following the Even Parity-------")
    transmit(msg)
    rec = input("Enter the received Message : ")
    VRC(rec)
