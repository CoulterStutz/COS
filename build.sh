RUNQEMU=true

mkdir -p build
mkdir -p bin

nasm -f elf32 src/boot.asm -o build/boot.o

# Compile C Scripts
gcc -m32 -ffreestanding -c src/kernel.c -o build/kernel.o
gcc -m32 -ffreestanding -c src/system.c -o build/system.o
gcc -m32 -ffreestanding -c src/math.c -o build/math.o
gcc -m32 -ffreestanding -c src/terminal.c -o build/terminal.o
gcc -m32 -ffreestanding -c src/screen.c -o build/screen.o

# Link em
gcc -m32 -T src/linker.ld -o bin/kernel.bin -ffreestanding -O2 -nostdlib -lgcc build/boot.o build/kernel.o build/system.o build/math.o build/terminal.o build/screen.o
cp bin/kernel.bin bin/cos.img

echo Building ISO
dd if=bin/cos.img of=bin/cos.iso bs=4M


if [ "$RUNQEMU" = true ]; then
    qemu-system-i386 -kernel bin/kernel.bin
fi

read a
