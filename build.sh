RUNQEMU=true

nasm -f elf32 src/boot.asm -o build/boot.o
gcc -m32 -ffreestanding -c src/kernel.c -o build/kernel.o
gcc -m32 -T src/linker.ld -o bin/kernel.bin -ffreestanding -O2 -nostdlib -lgcc build/boot.o build/kernel.o
cp bin/kernel.bin bin/cos.img

if [ "$RUNQEMU" = true ]; then
    qemu-system-i386 -kernel bin/kernel.bin
fi

read a