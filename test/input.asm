# Ejemplo de instrucciones tipo R: add, sub, xor...
add x1, x2, x3     # x1 = x2 + x3
sub x4, x5, x6     # x4 = x5 - x6
xor x7, x8, x9     # x7 = x8 ^ x9

# Ejemplo de instrucciones tipo I: addi, lw...
addi x10, x11, 10  # x10 = x11 + 10
lw x12, 100(x13)   # Carga el contenido de la memoria en la dirección x13 + 100 en x12

# Ejemplo de instrucciones tipo S: sw, sh, sb...
sw x14, 20(x15)    # Guarda el contenido de x14 en la dirección de memoria calculada por x15 + 20
sh x16, -4(x17)    # Guarda los 16 bits menos significativos de x16 en la dirección de memoria calculada por x17 - 4
sb x18, 100(x19)   # Guarda el byte menos significativo de x18 en la dirección de memoria calculada por x19 + 100

# Ejemplo de instrucciones tipo B: beq, bne, blt...
beq x20, x21, 50   # Salta a la etiqueta 50 si el contenido de x20 es igual al contenido de x21
bne x22, x23, 100  # Salta a la etiqueta 100 si el contenido de x22 no es igual al contenido de x23
blt x24, x25, 200  # Salta a la etiqueta 200 si el contenido de x24 es menor que el contenido de x25

# Ejemplo de instrucciones tipo U: lui, auipc...
lui x26, 1000      # Carga la constante 1000 en los bits más significativos de x26
auipc x27, 200     # Carga la dirección actual más la constante 200 en los bits más significativos de x27

# Ejemplo de instrucción tipo J: jal
jal x28, 500       # Salta a la etiqueta 500 y guarda la dirección de retorno en x28

# Ejemplo de instrucción nop
nop                # No realiza ninguna operación
