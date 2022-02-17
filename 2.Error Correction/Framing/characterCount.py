


if __name__ == "__main__" :
    n = int(input("Enter Number of frames  :"))
    msg = []
    for i in range(n) :
        m = input(f"Enter the message {i+1} : ")
        msg.append(str(len(m))+m)
    print("The message transmitted is : ")
    for i in range(n) :
        print(msg[i],end="  ")