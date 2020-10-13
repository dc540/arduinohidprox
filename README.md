# arduinohidprox
Interfacing an Arduino with a HID ProxPro 5355AGK00 (and likely others)

I acquired a HID ProxPro reader, and was interested in using it with Arduino. 

I chose the Arduino UNO, because it can be powered with 12V via the power jack, 
and I it can externally power the reader via its VIN pin. Not all models can do
this -- I believe some of the ESP models prevent outward power flow on the VIN
pins. But for the UNO, it's fine.

I found several sources online for interfacing the RFID readers with Arduino. I
settled on Daniel Smith's project from 2012 on Pagemac.com, because it's the most
straightforward. Daniel didn't include any license data in the published code,
so I'm assuming it's open and public domain, and I'm crediting his work here just
because it's the right thing to do.

http://www.pagemac.com/projects/rfid/arduino_wiegand

As I said, I'm using a ProxPro reader, but it seems like as long as they support 
Weigand data over the standard DATA0 and DATA1 outputs, they'll probably work.

Tie DATA0 to PIN2, and DATA1 to PIN3, and let her rip.  Debugging data available
in serial monitor. Will be adding basic display configuration back in as time
permits.

NOTE: If you can't get the green LED to fire, it probably means you are
powering the reader independently from the Arduino and forgot to connect a
ground line from between them. If you're powering it from the Arduino you will
have a ground line.

The good news is that you can connect via USB while the power is still attached
to the DC jack on the board. I wouldn't try it if you're powering by the pins. My
understanding is that there is circuitry to protect the board if you power it via
the DC jack, but not by the pins.  So powering by the USB and the pins simultaneously
is likely to burn out your board.

So I was able to make changes while it was still powered by the 12V and powering
the reader.

Wiring:

Reader     | Arduino
-----------|--------
DATA0      | 2
DATA1      | 3
LED_RED    | 10
LED_GREEN  | 11
DC +       | VIN
DC -       | GND (any)

SSD_1306   | Arduino
-----------+--------
GND        | GND
VCC        | 5V
SCL        | A5
SDA        | A4

MFRC522:

I happened to have a MFRC522 RFID module leftover from a Hackerbox from a year
or two ago, so I decided to port this functionality to that as well.  It's a work
in progress, and I will update when it's fully working. 

RFID-RC522 Wiring:

RFID-RC522 | Arduino
-----------+--------
RST        | 9
SDA        | 10
MOSI       | 11
MISO       | 12
SCK        | 13
