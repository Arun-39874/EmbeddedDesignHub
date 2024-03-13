# This code is for utilizing vaman by uploading wifi code into it using the arduino.

1) Follow all the steps as given in **vaman/installation/termuxubuntu/termuxubuntu_esp32.txt**
2) Complete the arduino connections as shown in below figure ![Alt text](https://github.com/Arun-39874/EmbeddedDesignHub/blob/main/Esp32/circuit_diagram.png)

5) In the **setup** file, we will get **4 files** inside it. <br>
   namely: src, .pio, platformio.ini, README.md
6) Remember to change the main.cpp that is in src folder<br>
   #define STASSID "id" **// Add your network username<br>**
   #define STAPSK  "password" **// Add your network password<br>**
7) Connect the arduino and vaman together, connect arduino to phone via otg and then vaman to arduino as shown in the circuit diagram.
8) Now we have to be in the setup directory and run <b> pio run </b>.
9) Remember to remove enable pin <b>EN</b> as soon as it displays <b>Connecting...</b> and then remove <b>0</b> pin when it displays <b>writing 100%</b> and before           <b>Leaving...</b>
10) Once after succesfully uploading the code, we can upload new code using <b>pio run -t nobuild -t upload --upload-port 192.168.X.X </b>
