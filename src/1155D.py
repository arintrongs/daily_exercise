
n, m = input().split(' ')
n = int(n)
m = int(m)
arr = input().split(' ')
arr = [0]+[int(x) for x in arr]
dp = [[0] * (len(arr)+1) for i in range(3)]
ans = 0
for i in range(1, len(arr)):
    dp[0][i] = max(0, dp[0][i-1]) + arr[i]
    dp[1][i] = max(dp[0][i-1], max(0, dp[1][i-1])) + arr[i]*m
    dp[2][i] = max(max(dp[0][i-1], dp[1][i-1]), max(0, dp[2][i-1])) + arr[i]
    ans = max(max(max(dp[0][i], dp[1][i]), dp[2][i]), ans)
print(ans)
# print(dp)
