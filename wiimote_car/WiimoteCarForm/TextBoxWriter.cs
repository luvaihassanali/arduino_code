using System.Text;
using System.IO;
using System.Windows.Forms;
using System;

namespace WiimoteCarForm {
    public class TextBoxWriter : TextWriter {
        //https://stackoverflow.com/questions/18726852/redirecting-console-writeline-to-textbox
        private Control control;
        public TextBoxWriter(Control c) {
            control = c;
        }
        //https://stackoverflow.com/questions/142003/cross-thread-operation-not-valid-control-accessed-from-a-thread-other-than-the
        public override void Write(char value) {
            control.Invoke(new Action(() => control.Text += value));
        }

        public override void Write(string value) {
            control.Invoke(new Action(() => control.Text += value));
        }

        public override Encoding Encoding {
            get { return Encoding.Unicode; }
        }
    }
}
