qtde = int(input())
# n colunas de mesma altura H compostas de 0 e 1
# H igual ao maior valor Xi da lista

votos = list(map(int, input().split()))
alt_max = max(votos)

for i in range(alt_max, 0, -1) :
    for v in votos:
        if v >= i:
            print(1, end=" ")
        else:
            print(0, end=" ")
    print()
