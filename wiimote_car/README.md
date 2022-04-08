Control Arduino powered RC car using Wiimote via this application.

Why? Wiimote uses bluetooth HID profile, so it won’t work with these HC-05 modules (bluetooth module for Arduino) since they use the serial profile (SPP).

WiimoteLib: https://github.com/BrianPeek/WiimoteLib
wiipair: https://github.com/jmandawg/wiipair