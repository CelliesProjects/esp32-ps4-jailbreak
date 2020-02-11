# esp32-ps4-jailbreak

This is a minimal implementation of the PS4 hack by qwertyoruiopz.

It only contains the 'PS4HEN v2.1.2'.

You will need an ESP32 board with 4MB flash memory and a PS4 on fw 5.05 to use the software.

## How to flash your ESP32:

#### Using Arduino IDE:

1. Download [AsyncTCP](https://github.com/me-no-dev/AsyncTCP) and [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer) and install these libraries in the Arduino libraries folder. 
<br>Restart the Arduino IDE after this step.

2. Unpack the  [latest release](https://github.com/CelliesProjects/esp32-ps4-jailbreak/releases/latest) zipfile.

3. Flash the compiled software to your ESP32.

#### Using pre-compiled binaries:

1. Flash the pre-compiled `esp32-ps4-jailbreak.ino.esp32.bin` file to 0x00010000.

2. Use this command (Linux) to flash the binary to an esp32 with a default partition table:<br>
`~/Arduino/hardware/espressif/esp32/tools/esptool.py  --chip esp32 --port /dev/ttyUSB0 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 80m 0x10000 esp32-ps4-jailbreak.ino.esp32.bin`
<br>( you might have to adjust some things for your particular board )

### How to connect and install PS4HEN:

1. The ESP32 will start an accesspoint named `ESP32 5.05 jailbreak server`. 

2. Connect to this AP with your PS4 and browse to `http://192.168.4.1/` to enable PS4HEN on your PS4.

#### Credits:
Specter, IDC, qwertyoruiopz, Flatz, CTurt, Mistawes, XVortex, Al-Azif
