using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Windows.Forms;

namespace hwtestForm
{
    public partial class Form1 : Form
    {
        private SerialPort port;
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            port = new SerialPort("COM3", 9600);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            port.Open();
            port.Write("0");
            port.Close();
        }        
        private void button2_Click_1(object sender, EventArgs e)
        {
            port.Open();
            port.Write("1");
            port.Close();
        }
        private void button3_Click_1(object sender, EventArgs e)
        {
            port.Open();
            port.Write("2");
            port.Close();
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            port.Open();
            port.Write("3");
            port.Close();

        }
    }
}
