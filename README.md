# arduinohidprox
Interfacing an Arduino with a HID ProxPro 5355AGK00 (and likely others)

I acquired a HID ProxPro reader, and was interested in using it with Arduino. 

I chose the Arduino UNO, because it can be powered with 12V via the power jack, 
and I believe it can externally power the reader via its VIN pin.

I found several sources online for interfacing the RFID readers with Arduino. I
settled on Daniel Smith's project from 2012 on Pagemac.com, because it's the most
straightforward. Daniel didn't include any license data in the published code,
so I'm assuming it's open and public domain, and I'm crediting his work here just
because it's the right thing to do.

http://www.pagemac.com/projects/rfid/arduino_wiegand

As I said, I'm using a ProxPro reader, but it seems like as long as they support 
Weigand data over the standard DATA0 and DATA1 outputs, they'll probably work.

Tie DATA0 to PIN2, and DATA1 to PIN3, and let her rip.  Debugging data available
in serial monitor. User feedback provided via 128x64 monochrome SSD_1306 display.
Adapt to your own display if you have something different. First draft was using
a QAPASS 1602 LCD.
