import logging
import os

#logger to make debugging easier
log = logging.getLogger(__name__)
#set last arg to "INFO", "WARNING", "ERROR", "DEBUG", or whatever
logging.basicConfig(level=os.environ.get("LOGLEVEL","INFO"))


class matrix():
    def __init__(self, a, b, c, d):
        log.info("Initializing matrix")
        self.a = a
        self.b = b
        self.c = c
        self.d = d

    def print_matrix(self):
        print("|{} {}|\n|{} {}|".format(self.a, self.b, self.c, self.d))

    def product(self, matrix):
        return matrix(self.a*matrix.a + self.b*matrix.c, self.a*matrix.b + self.b*matrix.d, self.c*matrix.a + self.d*matrix.c, self.c*matrix.b + self.d*matrix.d)

    def trace(self):
        return self.a+self.d
    
    def square(self):
        self = self.product(self)


matrix(1, 5, 2, 9).print_matrix()
