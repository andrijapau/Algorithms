import stackLib

def bc(string):
        checker = stackLib.stack()
        for i in range(0,len(string)):
                if string[i] == '(':
                        checker.push(')')
                if string[i] == '{':
                        checker.push('}')
                if string[i] == '[':
                        checker.push(']')

                if string[i] == ')' or string[i] == '}' or string[i] == ']':

                        if checker.isEmpty() == True:
                                return [False, i]
                        if checker.check() != string[i]:
                                return [False, i]
                        if checker.check() == string[i]:
                                checker.pop()

        if checker.isEmpty() == False:
                return [False, len(string)-1]
        if checker.isEmpty() == True:
                return [True, 0]
                
class stack:

        def __init__(self):
                self.l = []

        def push(self, value):
                self.l += [value]

        def pop(self):
                new = []
                for i in range(0,len(self.l)-1):
                        new += [self.l[i]]
                self.l = new
        def check(self):
                return self.l[len(self.l)-1]
        def isEmpty(self):
                if (self.l) == []:
                        return True
                else:
                        return False
