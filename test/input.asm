# Ejemplo de instrucciones tipo R: add, sub, xor...
add x1, x2, x3
sub x4, x5, x6
xor x7, x8, x9
# Ejemplo de instrucciones tipo S: sw, sh, sb...
sw x10, 20(x11)    # Guarda el contenido de x10 en la dirección de memoria calculada por x11 + 20
sh x12, -4(x13)    # Guarda los 16 bits menos significativos de x12 en la dirección de memoria calculada por x13 - 4
sb x14, 100(x15)   # Guarda el byte menos significativo de x14 en la dirección de memoria calculada por x15 + 100
# Ejemplo de instrucciones tipo B: beq, bne, blt...
beq x16, x17, 50   # Salta a la etiqueta 50 si el contenido de x16 es igual al contenido de x17
bne x18, x19, 100  # Sa|lta a la etiqueta 100 si el contenido de x18 no es igual al contenido de x19
blt x20, x21, 200  # Salta a la etiqueta 200 si el contenido de x20 es menor que el contenido de x21
# Ejemplo de instrucciones tipo U: lui, auipc...
lui x22, 1000      # Carga la constante 1000 en los bits más significativos de x22
auipc x23, 200     # Carga la dirección actual más la constante 200 en los bits más significativos de x23
# Ejemplo de instrucción tipo J: jal
jal x24, 500       # Salta a la etiqueta 500 y guarda la dirección de retorno en x24
# Ejemplo de instrucción nop
nop                # No realiza ninguna operación