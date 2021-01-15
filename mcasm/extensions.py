import re

reg_re = "r(\d|1[0-5])$"
float_re = "-?(0\.\d+|[1-9][0-9]*\.\d+)$"
int_re = "(0|[1-9][0-9]*|0x[0-9a-f]+)$"
label_re = "([a-z]\w*)$"

def data(data, l):
	if data[1] != "," or not re.match(int_re, data[2]):
		raise Exception
	n = int(data[2])
	result = []
	if re.match(float_re, data[0]):
		x = IEEE754(float(data[0]))
		to_bytes(result, x, 0)
		return bytes(result * n)
	elif re.match(int_re, data[0]):
		x = int(data[0], 16 if "x" in data[0] else 10)
	else:
		raise Exception
	while True:
		result.insert(0, x % 256)
		x //= 256
		if x == 0:
			break
	return bytes(result * n)

def db(data, l):
	result = []
	while(data):
		if not data[1] != ',' or not re.match(int_re, data[0]):
			raise Exception
		n = int(data.pop(0))
		if n > 255:
			raise Exception("Wrong type!")
		result.append(n)
		data.pop(0)
	return bytes(result)
