rm /home/gustavo/zips/*.zip
/home/gustavo/kernel/usr/build_scripts/build_kernel.sh
/home/gustavo/kernel/usr/build_scripts/makezip.sh
make -j3 zImage CONFIG_INITRAMFS_SOURCE="/home/gustavo/kernel/usr/initramfs/cm_initramfs.twrp.list"
/home/gustavo/kernel/usr/build_scripts/makezip.twrp.sh
make -j3 zImage CONFIG_INITRAMFS_SOURCE="/home/gustavo/kernel/usr/initramfs/omni_initramfs.list"
/home/gustavo/kernel/usr/build_scripts/makezip_omni.sh
make -j3 zImage CONFIG_INITRAMFS_SOURCE="/home/gustavo/kernel/usr/initramfs/omni_initramfs.twrp.list"
/home/gustavo/kernel/usr/build_scripts/makezip_omni.twrp.sh
make -j3 zImage CONFIG_INITRAMFS_SOURCE="/home/gustavo/kernel/usr/initramfs/slimkat_initramfs.list"
/home/gustavo/kernel/usr/build_scripts/makezip_slimkat.sh
make -j3 zImage CONFIG_INITRAMFS_SOURCE="/home/gustavo/kernel/usr/initramfs/slimkat_initramfs.twrp.list"
/home/gustavo/kernel/usr/build_scripts/makezip_slimkat.twrp.sh
