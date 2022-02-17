def transmit(msg) :
    flag = input("Enter the start and end flag : ")
    while len(flag) != 8 :
        flag = input("Enter a valid 8 bit flag : ")
    esc = input("Enter the escape byte sequence : ")
    while len(esc)!= 8:
        esc = input("Enter a valid 8 bit escape : ")
    i = 0 
    while i < len(msg) :
        if msg[i] == flag or msg[i] == esc : 
            msg.insert(i,esc)
            i += 1
        i += 1
    
    print("The Transmitted frame is : ")
    print(flag,end="   ")
    for i in range(len(msg)) :
        print(msg[i],end=" ")
    print(" ",flag)


if __name__ == "__main__" :
    n = int(input("Enter the Number of bytes to be transmitted : "))
    msg = []
    i = 0 
    while i < n : 
        m = input(f"Enter the bit {i+1} :")
        if len(m) != 8 : 
            print("Size mismatch, Enter the byte agian,")
            continue
        msg.append(m)
        i += 1
    transmit(msg)
