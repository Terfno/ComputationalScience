# ファイルパス
path = './o.txt'

# 戦歴
data0 = 'チーム\t1回目\t2回目\t3回目\t4回目\t合計'
data1 = '阪神\t1\t0\t1\t2\t4'
data2 = 'ロッテ\t10\t10\t10\t3\t33'

data = data0 + '\n' + data1 + '\n' + data2 + '\n'

# 書き込み
with open(path, mode='w') as f:
    f.write(data)

# 確認
with open(path) as f:
    print(f.read())
