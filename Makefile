
all:
	(cd xv6-riscv && make)

test: all
	perl test.pl

clean:
	(cd xv6-riscv && make clean)

qemu: all
	(cd xv6-riscv && make qemu-nox)

.PHONY: all test clean qemu
