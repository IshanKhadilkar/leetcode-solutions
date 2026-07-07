class Solution(object):
    def subtractProductAndSum(self, n):
        total_sum = 0
        total_product = 1
        
        while n > 0:
            digit = n % 10          # 1. consider the last digit
            
            total_sum += digit       # 2. Add  to the running sum
            total_product *= digit   # 3. Multiply to the running product
            
            n = n // 10              # 4. eliminate the last digit
            
        return total_product - total_sum