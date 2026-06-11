vmin = int(input())
vmax = int(input())
capacidade = int(input())
dose = int(input())

possivel = False

# dose * x + leite (entre vmin e vmax) = capacidade
# a intenção é verificar se há um múltiplo de dose entre capacidade - leite

for i in range (vmin, vmax+1) :
    cafe_necessario = capacidade - leite
    
    if cafe_necessario >= 0 and cafe_necessario % dose == 0:
        possivel = True
        break

if possivel:
    print("S")
else:
    print("N")
