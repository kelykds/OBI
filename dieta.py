nrefeicoes, limcal = map(int, input().split())
total = 0

for i in range (nrefeicoes):
    protein, fat, carb = map (int, input().split())
    total += protein * 4 + fat * 9 + carb * 4
    
restante = limcal - total

print(restante)
