

ones = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
tens = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
digit2 = ["","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

def parse(x):
    x = str(x)
    phrase = ""
    if len(x) >= 2 and int(x[len(x)-2]) == 1:
        phrase += tens[int(x[len(x)-1])]
    else:
        phrase += ones[int(x[len(x)-1])]
        if len(x) >= 2:
            phrase = digit2[int(x[len(x)-2])] + phrase
    if len(x) == 3:
        if phrase != "":
            phrase = "and" + phrase
        phrase = ones[int(x[len(x)-3])] + "hundred" + phrase
    if int(x) == 1000:
        phrase = "onethousand"
        
    return phrase
        

count = 0
for x in range(0, 1001):
    word = parse(x)
    print(word)
    print(len(word))
    count += len(word) 
print(count)
