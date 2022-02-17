import math
def transmit(k,m) :
    msg = []
    print("Enter the Data : ")
    for i in range(k) : 
        msg.append(input())
    
    sum = 0 
    for ms in msg : 
        sum += int(ms,2)
    # print(sum)
    def onesComplement(n):
        number_of_bits = (int)(math.floor(math.log(n) /math.log(2))) + 1
        return ((1 << number_of_bits) - 1) ^ n
    sum = onesComplement(sum)
    # print(sum)
    print("The Data Transmitted is : ",end= " ")
    for ms in msg : 
        print(ms,end= "")
    print(bin(sum).replace("0b",""))
    rec = input("Enter the Received Data : ")
    msg = list(map(''.join, zip(*[iter(rec)]*m)))
    sum = 0
    for ms in msg :
        sum += int(ms,2)
    res = bin(sum).replace("0b","")
    for i in res : 
        if i == "0" :
            print("Error Detected")
            return 

    print("No Error Detected")


if __name__ == "__main__":
    k = int(input("Enter no.of Chunks : "))
    m = int(input("Enter number of bits in each Chunk : "))

    transmit(k,m)