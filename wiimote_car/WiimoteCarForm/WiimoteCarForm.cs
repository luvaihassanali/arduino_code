using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.IO.Ports;
using WiimoteLib;

namespace WiimoteCarForm {

    public partial class WiimoteCarForm : Form {

        Wiimote wm;
        SerialPort serialPort;
        bool flag; //wii movement not sent to bluetooth module if flag = false
        bool isMoving; //booleans to prevent flooding of commands
        bool Forward;
        bool Reverse;
        char[] charArr; // 40 unique recieve values corresponding to 40 servo positions for front wheel turning 
        double[] floatArr;
        Dictionary<double, char> dict;

        public WiimoteCarForm() {
            InitializeComponent();
            wm = new Wiimote();
            if (serialPort == null) {
                serialPort = new SerialPort("COM7", 9600);
                serialPort.Open();
            }
            //car always set to turn on in auto, use flag to intiate back/forth between manual control
            flag = false;
            isMoving = false;
            Forward = false;
            Reverse = false;
            //used to map the max range of angle values front wheels can turn to char values for serial communication 
            floatArr = new double[] { -1, -0.95, -0.9, -0.85, -0.8, -0.75, -0.7, -0.65, -0.6, -0.55, -0.5, -0.45, -0.4, -0.35, -0.3, -0.25, -0.2, -0.15, -0.1, -0.05, 0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1 };
            charArr = "abcdefghijklmnopqrstuvqxyzABCDEFGHIJKLMNO".ToCharArray();
            dict = new Dictionary<double, char>();
            for(int i=0; i<41; i++) {
                dict.Add(floatArr[i], charArr[i]);
            }
        }

        private void Form1_Load(object sender, EventArgs e) {
            wiimoteInfo1.Wiimote = wm;
            wm.WiimoteChanged += wm_WiimoteChanged;
            wm.Connect();
            wm.SetReportType(InputReport.IRAccel, true); //needed for accel values
            wm.SetLEDs(true, false, false, false);
            TextBoxWriter writer = new TextBoxWriter(richTextBox1);
            Console.SetOut(writer); //Console.Write statements redirected to text box on form
        }

        private void wm_WiimoteChanged(object sender, WiimoteChangedEventArgs args) {
            wiimoteInfo1.UpdateState(args);
            //button 1 changes to manual control and 2 for back to automatic
            if (wm.WiimoteState.ButtonState.One) { flag = true; serialPort.Write("3"); }
            if (wm.WiimoteState.ButtonState.Two) { flag = false; serialPort.Write("4"); }
            if (flag) {
                //this block can be used to control car using wii motion but is set to A/B right now
                /*if (wm.WiimoteState.AccelState.Values.X >= 0.6 && wm.WiimoteState.AccelState.Values.X >= 0.4) {
                    if (!Forward) {
                        Console.WriteLine("Forward: " + wm.WiimoteState.AccelState.Values.X);
                        serialPort.Write("0");
                        isMoving = true;
                        Forward = true;
                    }
                }
                if (wm.WiimoteState.AccelState.Values.X >= -0.6 && wm.WiimoteState.AccelState.Values.X <= -0.4) {
                    if (!Reverse) {
                        Console.WriteLine("Reverse: " + wm.WiimoteState.AccelState.Values.X);
                        serialPort.Write("1");
                        isMoving = true;
                        Reverse = true;
                    }
                }*/
                //comment if statements for A/B to switch to motion forward/backward controls & uncomment block underneath
                if (wm.WiimoteState.ButtonState.A) {
                    if (!Forward) {
                        Console.WriteLine("Forward: " + wm.WiimoteState.AccelState.Values.X);
                        serialPort.Write("0");
                        isMoving = true;
                        Forward = true;
                    }
                } 
                if (wm.WiimoteState.ButtonState.B) {
                    if (!Reverse) {
                        Console.WriteLine("Reverse: " + wm.WiimoteState.AccelState.Values.X);
                        serialPort.Write("1");
                        isMoving = true;
                        Reverse = true;
                    }
                }
                if (!wm.WiimoteState.ButtonState.B && !wm.WiimoteState.ButtonState.A) {
                    if (isMoving) {
                        Console.WriteLine("Stop: " + wm.WiimoteState.AccelState.Values.X);
                        serialPort.Write("2");
                        isMoving = false;
                        Forward = false;
                        Reverse = false;
                    }
                }
                //uncomment this block if using motion forward/reverse control
                /*if (wm.WiimoteState.AccelState.Values.X > -0.2 && wm.WiimoteState.AccelState.Values.X < 0.2) {
                    if (isMoving) {
                        Console.WriteLine("Stop: " + wm.WiimoteState.AccelState.Values.X);
                        serialPort.Write("2");
                        isMoving = false;
                        Forward = false;
                        Reverse = false;
                    }
                }*/
                //controls front wheel direction using wii remote orientation
                if(wm.WiimoteState.AccelState.Values.Y <= 1 && wm.WiimoteState.AccelState.Values.Y >= -1) {
                    //Console.WriteLine("Servo: " + (Math.Round(wm.WiimoteState.AccelState.Values.Y*20)/20));
                    char key = dict[(Math.Round(wm.WiimoteState.AccelState.Values.Y * 20) / 20)];
                    serialPort.Write(key.ToString());
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e) {
            wm.Disconnect();
            if(serialPort != null && serialPort.IsOpen) serialPort.Close();
        }

        private void button1_Click(object sender, EventArgs e) {
            //not used - for testing purposes
        }

        private void button2_Click(object sender, EventArgs e) {
            //not used
        }
        //mirrors console onto form for better view of control statements while running application
        private void richTextBox1_TextChanged(object sender, EventArgs e) {
            richTextBox1.SelectionStart = richTextBox1.Text.Length;
            richTextBox1.ScrollToCaret();
        }
    }
}
