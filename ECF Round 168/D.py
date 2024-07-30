r = int(input())
for i in range(r):#loop
    n = int(input())#vertices
    value = [int(j) for j in input().strip().split(' ')]#index to value
    parents = [int(j) for j in input().strip().split(' ')]#index to parent
    childs = {new_list: [] for new_list in range(1,n+1)}#parent to children
    layers = []
    print(parents)
    for j in range(2, n+1):
        childs[parents[j-2]].append(j)
    print(value,childs)

    layer = [[1]]
    