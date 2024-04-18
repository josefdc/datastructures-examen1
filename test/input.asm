# Definición de etiquetas para puntos de salto
label_start:
nop

# Pruebas básicas para bltu y bgeu
bltu x1, x2, label_greater # Debería saltar si x1 es menor sin signo que x2
bgeu x3, x4, label_less     # Debería saltar si x3 es mayor o igual sin signo que x4

# Pruebas con valores límite
lui x1, 0xFFFFF     # Máximo valor posible para pruebas de límite superior
lui x2, 0x1         # Mínimo valor positivo mayor que cero
addi x3, x0, -1     # Mínimo valor posible (negativo en complemento a dos)
addi x4, x0, 0      # Valor cero para pruebas de igualdad

bltu x1, x0, label_mid # No debería saltar, x1 es mayor
bgeu x0, x4, label_mid # Debería saltar, x0 igual a x4 (ambos 0, sin signo)

label_greater:
# Punto de llegada si x1 < x2
nop

label_less:
# Punto de llegada si x3 >= x4
nop

label_mid:
# Punto de llegada alternativo
nop

# Asegúrate de tener instrucciones después de las pruebas para confirmar que los saltos funcionan correctamente
add x5, x1, x2
add x6, x3, x4

# Más pruebas si necesario
bltu x1, x3, label_end  # Pruebas adicionales de orden
bgeu x4, x2, label_start

label_end:
nop # Final de las pruebas
