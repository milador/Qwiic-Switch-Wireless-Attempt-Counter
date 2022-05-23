# Software

## Software requirements  

### Software or Libraries to Download

  1. [Arduino IDE](https://www.arduino.cc/en/software)
  2. [Main Code](./Code/)
  3. [SparkFun_Qwiic_GPIO Library library](https://github.com/sparkfun/SparkFun_Qwiic_GPIO_Library)
  4. [StopWatch Library](https://github.com/RobTillaart/Stopwatch_RT)
  5. [EasyMorse Library](https://github.com/milador/EasyMorse)
  6. [Adafruit_NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel)
  7. [FlashStorage Library](https://github.com/cmaglie/FlashStorage)
  8. ..
  9. ..


## Software Setup Process

### Debuggers and Compilers Setup Process

  1. Download the [Arduino IDE](https://www.arduino.cc/en/software) executable installation file suitable for your OS.
  2. Double click on the executable file to Install the **Arduino IDE**.
  3. Open and start the **Arduino IDE**.
  4. Go to **File > Preferences**.
  5. Add following link as a new line under **Additional Board Manager URLs** : https://www.adafruit.com/package_adafruit_index.json
  6. Restart the **Arduino IDE**
  7. Open the **Boards Manager** option from the **Tools > Board** menu and install **Adafruit SAMD Boards by Adafruit**
  8. Wait until the IDE finishes installing the cross-compiling toolchain and tools associated with Board Support Package. This may take few minutes.
  9. That’s it! The installation of **Arduino IDE** and the Board Support Packages is completed.

### Main Code Setup Process

  1. Visit the **SparkFun_Qwiic_GPIO** library github repository page.
  2. Click on **Code > Download Zip** to download **SparkFun_Qwiic_GPIO_Library**.
  3. Extract **SparkFun_Qwiic_GPIO_Library-master.zip** file
  4. Rename **SparkFun_Qwiic_GPIO_Library-master** folder to **SparkFun_Qwiic_GPIO_Library** folder under **SparkFun_Qwiic_GPIO_Library-master** subdirectory. 
  5. Copy or move **SparkFun_Qwiic_GPIO_Library** folder to Arduino installation library subdirectory. As an example: This is found under **C:\Program Files (x86)\Arduino\libraries in windows 10**.
  6. Visit the **StopWatch** library github repository page.
  7. Click on **Code > Download Zip** to download **StopWatch** library.
  8. Extract **Stopwatch_RT-master.zip** file
  9. Rename **Stopwatch_RT-master** folder to **Stopwatch** folder under **Stopwatch_RT-master** subdirectory. 
  10. Copy or move **Stopwatch** folder to Arduino installation library subdirectory. As an example: This is found under **C:\Program Files (x86)\Arduino\libraries in windows 10**.
  11. Visit the **EasyMorse** library github repository page.
  12. Click on **Code > Download Zip** to download **EasyMorse** library.
  13. Extract **EasyMorse-master.zip** file
  14. Rename **EasyMorse-master** folder to **EasyMorse** folder under **EasyMorse-master** subdirectory. 
  15. Copy or move **EasyMorse** folder to Arduino installation library subdirectory. As an example: This is found under **C:\Program Files (x86)\Arduino\libraries in windows 10**.
  16. Visit the **FlashStorage** library github repository page.
  17. Click on **Code > Download Zip** to download **FlashStorage** library.
  18. Extract **FlashStorage-master.zip** file
  19. Rename **FlashStorage-master** folder to **FlashStorage** folder under **FlashStorage-master** subdirectory. 
  20. Copy or move **FlashStorage** folder to Arduino installation library subdirectory. As an example: This is found under **C:\Program Files (x86)\Arduino\libraries in windows 10**.
  21. Visit the **Example_Software.ino** raw source code file under Code directory.
  22. Right click on the source code or any place on this page and select **Save Page As…**
  23. Select the directory you would like to save the software in your computer. 
  24. Change File name from **Example_Software** to **Example_Software.ino**
  25. Change **Save as type** to **All Files**.
  26. Click on **Save** button.
  27. Open the directory you selected in step 18.
  28. Double left click or open **Example_Software** file
  29. **Arduino IDE** will ask your permission to create a new sketch folder named **Example_Software** and move **Example_Software.ino** under this folder.
  30. Click on the **Ok** button. 
  31. **Arduino IDE** should now open the **Example_Software.ino** file automatically.
  32. Select the Board under **Tools > Board > Adafruit SAMD Boards** as **Adafruit QT PY (SAMD21)**
  33. Select the correct port number under **Tools > Port** which should show COM XX (Adafruit QT PY) 
  34. Press the **Verify** button to make sure there is no problem with the software and libraries. 
  35. Press **Upload** button 


