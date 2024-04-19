# Pruebas básicas para operaciones tipo R

# Pruebas de operaciones aritméticas básicas
add x7, x1, x2    # x7 = x1 + x2
sub x8, x1, x2    # x8 = x1 - x2

# Pruebas de operaciones de desplazamiento
sll x9, x2, x1    # x9 = x2 << x1
srl x10, x3, x1   # x10 = x3 >> x1
sra x11, x4, x1   # x11 = x4 >> x1 (aritméticamente)

# Pruebas de operaciones de comparación
slt x12, x1, x2   # x12 = 1 si x1 < x2, sino 0
sltu x1, x2, x3  # x1 = 1 si x2 < x3 (sin signo), sino 0


# Pruebas de operaciones lógicas
xor x14, x1, x2   # x14 = x1 XOR x2
or x15, x1, x2    # x15 = x1 OR x2
and x16, x1, x2   # x16 = x1 AND x2

# Instrucciones después de las pruebas para verificar la secuencia de ejecución
nop                # No realiza ninguna operación
nop                # No realiza ninguna operación

# Definiciones de etiquetas al final para garantizar el espacio y la estructura del código
label_end:
nop # Final de las pruebas
