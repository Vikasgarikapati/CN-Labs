
def transmit(msg) :
    beg =  input("Enter the start Sequence :")
    header = input("Enter the header Sequence : ")
    CRC = input("Enter the Redundancy bits(CRC) :")
    end = input("Enter the End Sequnce    :")
    print("The frame that should be transmitted is  : ", end=" ")
    print(beg +" "+ header+ " " + msg +  " "+ CRC +" " + end)

    inner = header + msg + CRC
    if (beg in inner ) or (end in inner) :
        print("There is repeating sequence , so the bit stuffed frame that is transmitted is : ")
        inner.replace(beg,beg[:-1]+"0"+beg[-1])
        inner.replace(end,end[:-1]+"0"+end[-1])
        print(beg + inner + end)
    else : 
        print("No bit stuffing required")

if __name__ == "__main__" :
    m = input("Enter the Message to be transmitted : ")
    transmit(m)
