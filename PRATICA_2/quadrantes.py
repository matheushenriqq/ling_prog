from ctypes import windll, Structure, c_long, byref
import time
import msvcrt

class Point(Structure):
    _fields_ = [("x", c_long), ("y", c_long)]

def query_mouse_position():
    pt = Point()
    windll.user32.GetCursorPos(byref(pt))
    return {"x": pt.x, "y": pt.y}

# Definições das variáveis da tela, de resolução 1920x1080p
quadrante_altura = 540
quadrante_comprimento = 960

while True:
    pos = query_mouse_position()
    x = pos["x"]
    y = pos["y"]

    # Verifica em qual quadrante o mouse se encontra
    if x < quadrante_comprimento:
        if y < quadrante_altura:
            quadrante = 'A'
        else:
            quadrante = 'C'
    else:
        if y < quadrante_altura:
            quadrante = 'B'
        else:
            quadrante = 'D'

    print("O mouse está no quadrante:", quadrante)

    time.sleep(0.1)  # Ajuste o atraso conforme necessário

    # Verifica se a tecla 'c' foi pressionada para encerrar o programa
    if msvcrt.kbhit():
        if msvcrt.getch() == b'c':
            break
