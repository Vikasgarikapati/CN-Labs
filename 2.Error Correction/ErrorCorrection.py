
def redundantBitsPosition(data,r) :
	j = 0
	k = 1
	m = len(data)
	res = ''
	for i in range(1, m + r+1):
		if(i == 2**j):
			res = res + '0'
			j += 1
		else:
			res = res + data[-1 * k]
			k += 1
	return res[::-1]


def calculateParityBits(arr,r) : 
	n = len(arr)
	for i in range(r):
		val = 0
		for j in range(1, n + 1):
			if(j & (2**i) == (2**i)):
				val = val ^ int(arr[-1 * j])
		arr = arr[:n-(2**i)] + str(val) + arr[n-(2**i)+1:]
	return arr

def detectError(arr,nr) : 
	n = len(arr)
	res = 0
	for i in range(nr):
		val = 0
		for j in range(1, n + 1):
			if(j & (2**i) == (2**i)):
				val = val ^ int(arr[-1 * j])
		res = res + val*(10**i)
	return int(str(res), 2)


if __name__ == "__main__" : 
	data = input("Enter the data : ")
	m = len(data)
	r = 0
	for i in range(len(data)) : 
		if 2**i >= m+i+1 : 
			r = i 
			break
	
	arr = redundantBitsPosition(data,r)
	arr = calculateParityBits(arr,r)
	print("The Data that is being transferred is : ",arr)
	
	arr = input("Enter the message Received : ")
	err = detectError(arr,r)
	print("The error position is : " ,str(err))