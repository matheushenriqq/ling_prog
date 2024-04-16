import math

opcao = input("Digite 'c' para calcular círculo ou 'r' para calcular retângulo: ")

if opcao == 'c':
    raio = float(input("Digite o raio do círculo: "))
    pi = 3.14
    circunferencia = 2 * pi * raio
    area = pi * raio ** 2
    print("O comprimento da circunferência é:", circunferencia)
    print("A área do círculo é:", area)

elif opcao == 'r':
    lado1 = float(input("Digite o valor do primeiro lado do retângulo: "))
    lado2 = float(input("Digite o valor do segundo lado do retângulo: "))
    perimetro = 2 * (lado1 + lado2)
    area = lado1 * lado2
    print("O perímetro do retângulo é:", perimetro)
    print("A área do retângulo é:", area)

else:
    print("Opção inválida!")