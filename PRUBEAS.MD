# Ejemplo de instrucciones tipo R: add, sub, xor...
add x1, x2, x3     # x1 = x2 + x3
sub x4, x5, x6     # x4 = x5 - x6
xor x7, x8, x9     # x7 = x8 ^ x9

# Ejemplo de instrucciones tipo I: addi, lw...
addi x10, zero, 10  # x10 = x11 + 10
lw x12, 100(x13)   # Carga el contenido de la memoria en la dirección x13 + 100 en x12

# Ejemplo de instrucciones tipo S: sw# Ejemplo de instrucciones tipo R: add, sub, xor...
add x1, x2, x3     # x1 = x2 + x3
sub x4, x5, x6     # x4 = x5 - x6
xor x7, x8, x9     # x7 = x8 ^ x9

# Ejemplo de instrucciones tipo I: addi, lw...
addi x10, x11, 10  # x10 = x11 + 10
lw x12, 100(x13)   # Carga el contenido de la memoria en la dirección x13 + 100 en x12

# Ejemplo de instrucciones tipo S: sw, sh, sb...
sw x14, 20(x15) 

beq x20, x21, label50    # Guarda el contenido de x14 en la dirección de memoria calculada por x15 + 20
sh x16, -4(x17)    # Guarda los 16 bits menos significativos de x16 en la dirección de memoria calculada por x17 - 4
sb x18, 100(x19)   # Guarda el byte menos significativo de x18 en la dirección de memoria calculada por x19 + 100

# Direcciones asignadas a etiquetas para instrucciones tipo B
# Suponiendo que cada instrucción ocupa 4 bytes
# Dirección inicial = 0x100
# add, sub, xor, addi, lw, sw, sh, sb ocupan 8 instrucciones antes de la primera etiqueta = 32 bytes
label50:    
add x1, x2, x3
sub x4, x5, x6   # Dirección 0x120
 # Salta a la etiqueta label50 si el contenido de x20 es igual al contenido de x21

label100:
sub x4, x5, x6        # Dirección 0x124
bne x22, x23, label100 # Salta a la etiqueta label100 si el contenido de x22 no es igual al contenido de x23

label200:          # Dirección 0x128
blt x24, x25, label200 # Salta a la etiqueta label200 si el contenido de x24 es menor que el contenido de x25

# Ejemplo de instrucciones tipo U: lui, auipc...
lui x26, 1000      # Carga la constante 1000 en los bits más significativos de x26
auipc x27, 200     # Carga la dirección actual más la constante 200 en los bits más significativos de x27

# Ejemplo de instrucción tipo J: jal
label500:          # Dirección 0x12C

# Ejemplo de instrucción nop
nop                # No realiza ninguna operación, sh, sb...
sw x14, 20(x15) 

beq x20, x21, label50    # Guarda el contenido de x14 en la dirección de memoria calculada por x15 + 20
sh x16, -4(x17)    # Guarda los 16 bits menos significativos de x16 en la dirección de memoria calculada por x17 - 4
sb x18, 100(x19)   # Guarda el byte menos significativo de x18 en la dirección de memoria calculada por x19 + 100

# Direcciones asignadas a etiquetas para instrucciones tipo B
# Suponiendo que cada instrucción ocupa 4 bytes
# Dirección inicial = 0x100
# add, sub, xor, addi, lw, sw, sh, sb ocupan 8 instrucciones antes de la primera etiqueta = 32 bytes
label50:    
add x1, x2, x3
sub x4, x5, x6   # Dirección 0x120
 # Salta a la etiqueta label50 si el contenido de x20 es igual al contenido de x21

label100:
sub x4, x5, x6        # Dirección 0x124
bne x22, x23, label100 # Salta a la etiqueta label100 si el contenido de x22 no es igual al contenido de x23

label200:          # Dirección 0x128
blt x24, x25, label200 # Salta a la etiqueta label200 si el contenido de x24 es menor que el contenido de x25

# Ejemplo de instrucciones tipo U: lui, auipc...
lui x26, 1000      # Carga la constante 1000 en los bits más significativos de x26
auipc x27, 200     # Carga la dirección actual más la constante 200 en los bits más significativos de x27

# Ejemplo de instrucción tipo J: jal
label500:          # Dirección 0x12C

# Ejemplo de instrucción nop
nop                # No realiza ninguna operación