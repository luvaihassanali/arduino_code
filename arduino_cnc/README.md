# arduino_cnc
Code for arduino cnc plotter (.ino) &amp; processing sketch (.pde)

Built with Arduino Uno using 3 stepper motors:
  1. 28BYJ-48 stepper motor with ULN2003 driver
  2. PowerMac G4 DVD Drive stepper motor with L293D driver
  3. USB Slim 2.0 External DVD Drive stepper motor with L293D driver

Uses inkscape-unicorn (https://github.com/martymcguire/inkscape-unicorn) to produce gcode files using Inkscape (https://www.youtube.com/watch?v=bbe56S_O-uI)

axis_control - used to setup motor, various functions to test movement
cnc_uno - code which parses gcodes into axis movement
cnc_parser - processing sketch which feeds gcodes to arduino

*gcode examples have last pen up command removed; for my machine it worked easier
