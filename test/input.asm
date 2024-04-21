  # Ejemplo de archivo input.asm para probar instrucciones

# Instrucciones tipo R
add x1, x2, x3
sub x4, x5, x6
sll x7, x8, x9
slt x10, x11, x12
sltu x13, x14, x15
xor x16, x17, x18
srl x19, x20, x21
sra x22, x23, x24
or x25, x26, x27
and x28, x29, x30

# Instrucciones tipo I
addi x1, x2, 10
lw x3, 100(x4)
lb x5, 50(x6)
lh x7, 75(x8)
lbu x9, 60(x10)
lhu x11, 45(x12)
slti x13, x14, -5
sltiu x15, x16, 20
xori x17, x18, 15
ori x19, x20, 25
andi x21, x22, 30

# Instrucciones tipo S
sw x31, 200(x1)
sb x30, 204(x2)
sh x29, 208(x3)

# Instrucciones tipo B
beq x4, x5, loop
bne x6, x7, end
blt x8, x9, somewhere
bge x10, x11, here
bltu x12, x13, there
bgeu x14, x15, nowhere

# Instrucciones tipo U
lui x18, 0xFFF
auipc x19, 0x1FF

# Instrucciones tipo J
jal x20, func

# Instrucciones de sistema
ecall
ebreak
nop

# Labels para instrucciones de salto
loop: 
end:
somewhere:
here:
there:
nowhere:
func:
