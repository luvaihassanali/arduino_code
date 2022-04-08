import java.awt.event.KeyEvent;
import processing.serial.*;

Serial port = null;
String portName = "COM3"; // "/dev/ttyUSB0"
boolean streaming = false;
float speed = 0.001; //0.01 0.1
String[] gcode;
int tracker = 0;

void setup() {
  size(500, 250);
  port = new Serial(this, portName, 9600);
  port.bufferUntil('\n');
}

void draw() {
  background(1);  
  fill(255);
  textSize(20);
  text("--- Arduino CNC Plotter ---\n\n\n\n\n", 5, 25);
  textSize(18);
  text("Enter corresponding letter command:", 5, 50);
  textSize(16);
  text("s - [s]tream a g-code file", 10, 75);
  text("p - sto[p] streaming g-code", 10, 90); 
  text("h - go to [h]ome position (press after p)", 10, 105); 
}

void keyPressed() {
  if (!streaming) {
    if (key == 'h') port.write("M300 S50\nG90\nG00 X0.000 Y0.000 Z0.000\n"); //pen up and x,y to (0,0)
  }
  if (!streaming && key == 's') {
    gcode = null; 
    tracker = 0;
    File file = null; 
    selectInput("Load file", "loadFile", file);
  }
  if (key == 'p') streaming = false;
}

void loadFile(File selection) {
  if (selection == null) {
    println("Aborted.");
  } else {
    gcode = loadStrings(selection.getAbsolutePath());
    if (gcode == null) return;
    streaming = true;
    stream();
  }
}

void serialEvent(Serial p) {
  String s = p.readStringUntil('\n');
  println(s.trim());
  if (s.trim().startsWith("200")) stream();
}

void stream() {
  if (!streaming) return;
  while (true) {
    if (tracker == gcode.length) {
      streaming = false;
      return;
    }
    if (gcode[tracker].trim().length() == 0) tracker++;
    else break;
  }
  println(gcode[tracker]);
  port.write(gcode[tracker] + '\n');
  tracker++;
}
