

#gotta take 2^1000 and sum the digits
#or 1048576^25


target = 256

print(target**125)
target = target**125



sum = 0
for x in str(target):
    #print(x)
    sum += int(x)

print(sum)
