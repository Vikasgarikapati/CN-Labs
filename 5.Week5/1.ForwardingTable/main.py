

class NetWork:
    def __init__(self) -> None:
        self.hosts = self.nets = self.netId = self.start = None


if __name__ == "__main__":

    A = NetWork()
    A.nets = 126
    A.host = 16777214
    netId = 8
    start = '0'

    B = NetWork()
    B.nets = 16382
    B.hosts = 65534
    netId = 2
    start = '10'

    C = NetWork()
    C.nets = 2097150
    C.hosts = 254
    netId = 3
    start = '11'

    nets = input("Enter Number of Networks : ")
    hosts = input("Enter Number of Hosts/end devices : ")

    clses = [A, B, C]
    res = []
    for cs in clses : 
        

