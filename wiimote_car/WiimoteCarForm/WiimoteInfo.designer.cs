namespace WiimoteCarForm
{
	partial class WiimoteInfo
	{
		/// <summary> 
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary> 
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Component Designer generated code

		/// <summary> 
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.clbButtons = new System.Windows.Forms.CheckedListBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.pbBattery = new System.Windows.Forms.ProgressBar();
            this.lblBattery = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.chkLED2 = new System.Windows.Forms.CheckBox();
            this.chkLED4 = new System.Windows.Forms.CheckBox();
            this.chkLED3 = new System.Windows.Forms.CheckBox();
            this.chkLED1 = new System.Windows.Forms.CheckBox();
            this.chkRumble = new System.Windows.Forms.CheckBox();
            this.chkZ = new System.Windows.Forms.CheckBox();
            this.chkC = new System.Windows.Forms.CheckBox();
            this.lblChuk = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.lblChukJoy = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lblAccel = new System.Windows.Forms.Label();
            this.groupBox8.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox8
            // 
            this.groupBox8.Controls.Add(this.clbButtons);
            this.groupBox8.Location = new System.Drawing.Point(0, 0);
            this.groupBox8.Name = "groupBox8";
            this.groupBox8.Size = new System.Drawing.Size(72, 220);
            this.groupBox8.TabIndex = 37;
            this.groupBox8.TabStop = false;
            this.groupBox8.Text = "Wiimote";
            // 
            // clbButtons
            // 
            this.clbButtons.FormattingEnabled = true;
            this.clbButtons.Items.AddRange(new object[] {
            "A",
            "B",
            "-",
            "Home",
            "+",
            "1",
            "2",
            "Up",
            "Down",
            "Left",
            "Right"});
            this.clbButtons.Location = new System.Drawing.Point(8, 16);
            this.clbButtons.Name = "clbButtons";
            this.clbButtons.Size = new System.Drawing.Size(56, 184);
            this.clbButtons.TabIndex = 1;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.pbBattery);
            this.groupBox4.Controls.Add(this.lblBattery);
            this.groupBox4.Location = new System.Drawing.Point(0, 494);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(104, 52);
            this.groupBox4.TabIndex = 33;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Battery:";
            // 
            // pbBattery
            // 
            this.pbBattery.Location = new System.Drawing.Point(8, 20);
            this.pbBattery.Maximum = 200;
            this.pbBattery.Name = "pbBattery";
            this.pbBattery.Size = new System.Drawing.Size(90, 23);
            this.pbBattery.Step = 1;
            this.pbBattery.TabIndex = 6;
            // 
            // lblBattery
            // 
            this.lblBattery.AutoSize = true;
            this.lblBattery.Location = new System.Drawing.Point(52, 0);
            this.lblBattery.Name = "lblBattery";
            this.lblBattery.Size = new System.Drawing.Size(35, 13);
            this.lblBattery.TabIndex = 9;
            this.lblBattery.Text = "label1";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.chkLED2);
            this.groupBox3.Controls.Add(this.chkLED4);
            this.groupBox3.Controls.Add(this.chkLED3);
            this.groupBox3.Controls.Add(this.chkLED1);
            this.groupBox3.Controls.Add(this.chkRumble);
            this.groupBox3.Location = new System.Drawing.Point(0, 368);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(96, 120);
            this.groupBox3.TabIndex = 32;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Outputs";
            // 
            // chkLED2
            // 
            this.chkLED2.AutoCheck = false;
            this.chkLED2.AutoSize = true;
            this.chkLED2.Location = new System.Drawing.Point(8, 36);
            this.chkLED2.Name = "chkLED2";
            this.chkLED2.Size = new System.Drawing.Size(53, 17);
            this.chkLED2.TabIndex = 3;
            this.chkLED2.Text = "LED2";
            this.chkLED2.UseVisualStyleBackColor = true;
            this.chkLED2.CheckedChanged += new System.EventHandler(this.chkLED_CheckedChanged);
            // 
            // chkLED4
            // 
            this.chkLED4.AutoCheck = false;
            this.chkLED4.AutoSize = true;
            this.chkLED4.Location = new System.Drawing.Point(8, 76);
            this.chkLED4.Name = "chkLED4";
            this.chkLED4.Size = new System.Drawing.Size(53, 17);
            this.chkLED4.TabIndex = 3;
            this.chkLED4.Text = "LED4";
            this.chkLED4.UseVisualStyleBackColor = true;
            this.chkLED4.CheckedChanged += new System.EventHandler(this.chkLED_CheckedChanged);
            // 
            // chkLED3
            // 
            this.chkLED3.AutoCheck = false;
            this.chkLED3.AutoSize = true;
            this.chkLED3.Location = new System.Drawing.Point(8, 56);
            this.chkLED3.Name = "chkLED3";
            this.chkLED3.Size = new System.Drawing.Size(53, 17);
            this.chkLED3.TabIndex = 3;
            this.chkLED3.Text = "LED3";
            this.chkLED3.UseVisualStyleBackColor = true;
            this.chkLED3.CheckedChanged += new System.EventHandler(this.chkLED_CheckedChanged);
            // 
            // chkLED1
            // 
            this.chkLED1.AutoCheck = false;
            this.chkLED1.AutoSize = true;
            this.chkLED1.Location = new System.Drawing.Point(8, 16);
            this.chkLED1.Name = "chkLED1";
            this.chkLED1.Size = new System.Drawing.Size(53, 17);
            this.chkLED1.TabIndex = 3;
            this.chkLED1.Text = "LED1";
            this.chkLED1.UseVisualStyleBackColor = true;
            this.chkLED1.CheckedChanged += new System.EventHandler(this.chkLED_CheckedChanged);
            // 
            // chkRumble
            // 
            this.chkRumble.AutoCheck = false;
            this.chkRumble.AutoSize = true;
            this.chkRumble.Location = new System.Drawing.Point(8, 96);
            this.chkRumble.Name = "chkRumble";
            this.chkRumble.Size = new System.Drawing.Size(62, 17);
            this.chkRumble.TabIndex = 4;
            this.chkRumble.Text = "Rumble";
            this.chkRumble.UseVisualStyleBackColor = true;
            this.chkRumble.CheckedChanged += new System.EventHandler(this.chkRumble_CheckedChanged);
            // 
            // chkZ
            // 
            this.chkZ.AutoCheck = false;
            this.chkZ.AutoSize = true;
            this.chkZ.Location = new System.Drawing.Point(8, 112);
            this.chkZ.Name = "chkZ";
            this.chkZ.Size = new System.Drawing.Size(33, 17);
            this.chkZ.TabIndex = 17;
            this.chkZ.Text = "Z";
            this.chkZ.UseVisualStyleBackColor = true;
            // 
            // chkC
            // 
            this.chkC.AutoCheck = false;
            this.chkC.AutoSize = true;
            this.chkC.Location = new System.Drawing.Point(8, 92);
            this.chkC.Name = "chkC";
            this.chkC.Size = new System.Drawing.Size(33, 17);
            this.chkC.TabIndex = 17;
            this.chkC.Text = "C";
            this.chkC.UseVisualStyleBackColor = true;
            // 
            // lblChuk
            // 
            this.lblChuk.Location = new System.Drawing.Point(8, 20);
            this.lblChuk.Name = "lblChuk";
            this.lblChuk.Size = new System.Drawing.Size(92, 40);
            this.lblChuk.TabIndex = 13;
            this.lblChuk.Text = "Accel Values";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.chkZ);
            this.groupBox2.Controls.Add(this.chkC);
            this.groupBox2.Controls.Add(this.lblChuk);
            this.groupBox2.Controls.Add(this.lblChukJoy);
            this.groupBox2.Location = new System.Drawing.Point(0, 226);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(104, 136);
            this.groupBox2.TabIndex = 31;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Nunchuk";
            // 
            // lblChukJoy
            // 
            this.lblChukJoy.Location = new System.Drawing.Point(8, 64);
            this.lblChukJoy.Name = "lblChukJoy";
            this.lblChukJoy.Size = new System.Drawing.Size(92, 28);
            this.lblChukJoy.TabIndex = 16;
            this.lblChukJoy.Text = "Joystick Values";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lblAccel);
            this.groupBox1.Location = new System.Drawing.Point(82, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(237, 224);
            this.groupBox1.TabIndex = 30;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Wiimote Accel";
            // 
            // lblAccel
            // 
            this.lblAccel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAccel.Location = new System.Drawing.Point(6, 20);
            this.lblAccel.Name = "lblAccel";
            this.lblAccel.Size = new System.Drawing.Size(225, 204);
            this.lblAccel.TabIndex = 2;
            this.lblAccel.Text = "Accel Values";
            // 
            // WiimoteInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox8);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "WiimoteInfo";
            this.Size = new System.Drawing.Size(333, 617);
            this.groupBox8.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);

		}

		#endregion

		public System.Windows.Forms.GroupBox groupBox8;
		public System.Windows.Forms.CheckedListBox clbButtons;
		public System.Windows.Forms.GroupBox groupBox4;
		public System.Windows.Forms.ProgressBar pbBattery;
		public System.Windows.Forms.Label lblBattery;
		public System.Windows.Forms.GroupBox groupBox3;
		public System.Windows.Forms.CheckBox chkLED2;
		public System.Windows.Forms.CheckBox chkLED4;
		public System.Windows.Forms.CheckBox chkLED3;
		public System.Windows.Forms.CheckBox chkLED1;
		public System.Windows.Forms.CheckBox chkRumble;
		public System.Windows.Forms.CheckBox chkZ;
		public System.Windows.Forms.CheckBox chkC;
		public System.Windows.Forms.Label lblChuk;
		public System.Windows.Forms.GroupBox groupBox2;
		public System.Windows.Forms.Label lblChukJoy;
		public System.Windows.Forms.GroupBox groupBox1;
		public System.Windows.Forms.Label lblAccel;
    }
}
