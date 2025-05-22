KVERSION := `uname -r`
KDIR := /lib/modules/${KVERSION}/build

default: clean
	$(MAKE) -C $(KDIR) M=$$PWD

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

install: default
	$(MAKE) -C $(KDIR) M=$$PWD modules_install
	depmod -A

unload:
	rmmod hid_oddor_handbrake;

load:
	insmod hid_oddor_handbrake.ko