cp /home/gustavo/kernel/arch/arm/configs/kernel_defconfig /home/gustavo/kernel/.config
make -j3 CONFIG_INITRAMFS_SOURCE="../initramfs3"
