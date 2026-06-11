escola = int(input())
supermercado = int(input())
lojinha = int(input())

lista = [escola, supermercado, lojinha]
lista.sort()
distancia = abs(lista[0] - lista[2]) * 2

print(distancia)
    
