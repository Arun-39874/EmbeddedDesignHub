This contains the steps to install the requuired libraries for FPGA:
1. Install the **fpga.zip** file provided in this directory onto **Desktop**
2. And extract the zip file in Desktop.
3. Now open the terminal and type command **cd Desktop/fpga**.
5. Type **chmod +x setup.sh**
6. the above command used for makes the scrips and programs of setup.sh file executable.
7. Now type the command **sudo bash setup.sh**.
8. The above command takes some time to execute and install all the required files and libraries.
9. After successfully completing the installation got to **Other Locations --> Computer --> root**
10. Copy the **Symbiflow, Pygmy-dev** and **arch.tar.gz** and paste them in **"Desktop/fpga"**.
11. or you can download the arch.tar.gz from the given below link:
12. <pre>https://iith-my.sharepoint.com/:u:/g/personal/gadepall_ee_iith_ac_in/Ebot5QHEYXBAo-7n4hnvJu0B8vMrTIdj_COHJC2cmDY1ww?e=bqDxHI</pre>
13. Make sure that /desktop/fpga contains pygmy-dev, setup.sh and symbiflow and zip file arch.tar.gz
14. Next:
At Home:
<pre>
sudo apt update -y <br>
sudo apt upgrade -y<br>
sudo apt install openssh-server sshpass build-essential libssl-dev libffi-dev python3-dev bison flex git tcl-dev tcl tcl-tclreadline libreadline-dev  autoconf libtool make automake texinfo pkg-config libusb-1.0-0 libusb-1.0-0-dev gcc-arm-none-eabi libnewlib-arm-none-eabi telnet python3 apt-utils libxslt-dev cmake curl python3-pip python3-venv -y<br>
pip3 install gdown lxml simplejson<br>
sudo apt install openssh-server sshpass<br>
sudo apt install build-essential libssl-dev libffi-dev python3-dev bison flex git tcl-dev tcl tcl-tclreadline libreadline-dev  autoconf libtool make automake texinfo pkg-config libusb-1.0-0 libusb-1.0-0-dev gcc-arm-none-eabi libnewlib-arm-none-eabi telnet python3 apt-utils libxslt-dev python3-lxml python3-simplejson cmake curl  python3-setuptools python3-pip<br>
cp arch.tar.gz /home/arun/Desktop/fpga/arch.tar.gz<br>
export INSTALL_DIR=/home/arun/Desktop/fpga/symbiflow<br>
tar -C $INSTALL_DIR  -xvf /home/arun/Desktop/fpga/arch.tar.gz<br>
export PATH="$INSTALL_DIR/quicklogic-arch-defs/bin:$INSTALL_DIR/quicklogic-arch-defs/bin/python3:$PATH"<br>
cd /home/arun/Desktop/fpga/pygmy-dev/tools/quicklogic-fasm<br>
nvim requirements.txt<br>
   Replace contents with these lines:
      -e git+https://github.com/symbiflow/fasm.git#egg=fasm
      -e git+https://github.com/antmicro/quicklogic-fasm-utils.git#egg=fasm-utils<br>
   
python3 -m venv venv<br>
source venv/bin/activate<br>
pip3 install -r requirements.txt<br>
sudo python3 setup.py install<br>
cd /home/arun/Desktop/fpga/pygmy-dev/tools/quicklogic-yosys<br>
make config-gcc<br>
make -j4 install PREFIX=$INSTALL_DIR<br>
cd /home/arun/Desktop/fpga/pygmy-dev/tools/yosys-symbiflow-plugins<br>
export PATH=$INSTALL_DIR/bin:$PATH<br>
make -j4 install<br>
cd /home/arun/Desktop/fpga/pygmy-dev/tools/vtr-verilog-to-routing<br>
make -j4<br>
nvim ~/.bashrc<br>
#paste the following 3 lines at the end of the file
export  INSTALL_DIR=/home/arun/Desktop/fpga/symbiflow
export PATH="$INSTALL_DIR/quicklogic-arch-defs/bin:$INSTALL_DIR/quicklogic-arch-defs/bin/python3:$PATH"
export PATH=/home/arun/Desktop/fpga/symbiflow/bin:$PATH
    
source ~/.bashrc<br>
vpr -h<br>
yosys -h<br>
qlfasm -h<br>
ql_symbiflow -h<br>
cd $INSTALL_DIR/quicklogic-arch-defs/tests/counter_16bit<br>
ls<br>
ql_symbiflow -compile -d ql-eos-s3 -P pd64 -v counter_16bit.v -t top -p chandalar.pcf -dump binary<br>
pip3 install gdown lxml simplejson<br>
ql_symbiflow -compile -d ql-eos-s3 -P pd64 -v counter_16bit.v -t top -p chandalar.pcf -dump binary<br>
ls<br>
cd /home/arun/Desktop/fpga<br>
ls<br>
mkdir fpga-examples<br>
cd fpga-examples<br>
svn co https://github.com/gadepall/vaman/trunk/fpga/setup/codes/blink<br>
cd blink<br>
ls<br>
 
<b>Command to compile code:
    
ql_symbiflow -compile -src /home/arun/Desktop/fpga/fpga-examples/blink -d ql-eos-s3 -P PU64 -v helloworldfpga.v -t helloworldfpga -p quickfeather.pcf -dump binary</b><br>
 
ls<br>
nvim helloworldfpga.v --> This file contains the code<br> 
nvim quickfeather.pcf --> This file contains pin configurations<br>
<b>Make sure to compile the file after modifying .v or .pcf file </b><br>
 
<b>Command to upload code to vaman:</b><br> 
#Make sure that vaman is in upload mode(i.e Green Light)<br>
#After Compiling the code make sure to copy the bin file and paste it in home and perform the upload command <br>
<b>sudo python3 /home/arun/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0 --appfpga /home/arun/helloworldfpga.bin --mode fpga</b>
</pre>