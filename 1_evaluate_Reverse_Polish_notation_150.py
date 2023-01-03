class Solution(object):
    def evalRPN(self, t):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for i in range(len(t)) :
            if(t[i]=='+'):
                stack.append(stack.pop() + stack.pop())
            elif(t[i]=='-'):
                a, b = stack.pop(), stack.pop()
                stack.append(b-a)
            elif(t[i]=='*'):
                stack.append(stack.pop() * stack.pop())
            elif(t[i]=='/'):
                a,b = stack.pop(), stack.pop()
                stack.append(int(float(b)/a))
            else:
                stack.append(int(t[i]))
        return stack[0]
            
        