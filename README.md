# esp32-ps4-jailbreak

This is a minimal implementation of the PS4 hack by qwertyoruiopz. It just contains the HEN for the PS4 on fw 5.05.

You will need an ESP32 board with 4MB flash memory to use the software.

## How to flash your ESP32:

Download the [latest release](https://github.com/CelliesProjects/esp32-ps4-jailbreak/releases/latest).

#### Using Arduino IDE:
1. Unpack the zipfile.

2. Compile and flash the compiled software to your ESP32.

#### Using pre-compiled binaries:

Flash the pre-compiled `esp32-ps4-jailbreak.ino.esp32.bin` file to 0x00010000.

Use this command to flash the binary to an esp32 with a default partition table:

`~/Arduino/hardware/espressif/esp32/tools/esptool.py  --chip esp32 --port /dev/ttyUSB0 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m 0x10000 esp32-ps4-jailbreak.ino.esp32.bin`

( you might have to adjust some things for your particular board )

#### How to connect and install HEN:

The ESP32 will start an accesspoint named `ESP32 5.05 jailbreak server`. 

Connect to this AP with your PS4 and browse to `http://192.168.4.1/` to enable HEN on your PS4.

#### Credits:
Specter, IDC, qwertyoruiopz, Flatz, CTurt, Mistawes, XVortex, Al-Azif
