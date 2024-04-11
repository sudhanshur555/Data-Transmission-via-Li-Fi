# Light-Based Data Transmission using Arduino

This project demonstrates a proof-of-concept for an optical wireless communication system capable of transmitting and receiving text data using visible light. The transmitter module encodes text data into a serial bit stream by blinking an LED, while the receiver module decodes the light signal using a solar cell and reconstructs the original text data.

## Components Used

- 2 x Arduino Uno boards
- 2 x Solderless Breadboard
- 1 x 5mm White LED
- 1 x Solar Cell (or Photo-resistor)
- 1 x 16x2 LCD Display with I2C interface
- Jumper wires
- Power Supply
- (Optional) Resistors, capacitors for solar cell amplifier circuit

## Circuit Diagram

![Screenshot (719)](https://github.com/sudhanshur555/Li-Fi/assets/49424288/736bd7b7-54f8-41cc-b116-85dd4007d772)

The transmitter circuit consists of an Arduino Uno board with a white LED connected to one of its digital output pins. The receiver circuit includes an Arduino Uno board, a solar cell (or photo-resistor) connected to an analog input pin, and an I2C LCD display.

## Working Principle

### Transmitter

1. The transmitter Arduino reads a predefined text string stored in its flash memory.
2. Each character in the string is converted into its 8-bit binary representation (ASCII encoding).
3. The LED is turned on and off rapidly to transmit each bit serially, with a small delay between bits to maintain the desired baud rate.
4. A start bit (LED off) and a stop bit (LED on) are added to each transmitted byte for synchronization purposes.
5. The entire text string is transmitted repeatedly in a loop.
6. Baud Rate = 1 / (SAMPLING_TIME * 2) = 1 / (0.005 * 2) = 100 bits/second = 1200 baud.

### Receiver

1. The solar cell generates a varying analog voltage proportional to the received light intensity from the transmitter LED.
2. The receiver Arduino monitors this analog voltage using its Analog-to-Digital Converter (ADC).
3. The voltage levels are sampled at the specified baud rate, determined by the transmitter's delay between bits.
4. The sampled bits are reconstructed into bytes by detecting the start and stop bit patterns.
5. The received bytes are interpreted as ASCII characters and displayed on the LCD screen.
6. Any invalid or corrupted bytes are discarded.
7. Sampling Rate = 1 / SAMPLING_TIME = 1 / 0.005 = 200 samples/second.

## Video Demonstration

[Youtube Link](https://youtu.be/QjGDJaWciqk)

## Installation and Usage

1. Connect the components as per the circuit diagram, ensuring correct wiring between the Arduino boards, LED, solar cell, and LCD display.
2. Upload the respective code (`transmitter.ino` and `receiver.ino`) to the transmitter and receiver Arduino boards.
3. Open the Serial Monitor on the receiver side to view the received data for debugging purposes.
4. The transmitted text should be displayed on the LCD screen in real-time as it is received.

Note: Ensure that the transmitter LED is adequately visible to the receiver solar cell and that there is minimal ambient light interference for proper data transmission.

## Limitations and Challenges

- Limited range: The effective transmission range is relatively short due to the limited brightness of the LED and sensitivity of the solar cell.
- Ambient light interference: Ambient light sources (e.g., sunlight, fluorescent lamps) can introduce noise and potentially corrupt the received data.
- Baud rate limitations: The achievable baud rate (data transmission speed) is constrained by the switching speed of the LED and the sampling rate of the receiver.
- Unidirectional communication: The current implementation only supports one-way data transmission from the transmitter to the receiver.

## Future Improvements

- Implement error detection and correction mechanisms (e.g., parity bits, checksums, or more advanced coding techniques) to improve reliability.
- Add support for transmitting larger strings or files by implementing buffering and packet-based transmission.
- Experiment with different light sources (e.g., lasers) and detectors (e.g., photodiodes) for improved range and data rates.
- Explore different modulation techniques (e.g., amplitude, frequency, or phase modulation) for more efficient data encoding.
- Implement bi-directional communication for a full-duplex optical link by adding additional transmitter and receiver components.
- Enhance the user interface by allowing user input for the text to be transmitted.
- Implement automatic baud rate detection and synchronization between the transmitter and receiver.

## Contributors


 - [Sudhanshu Ranjan](https://github.com/sudhanshur555)

 - [Vinay Kumar](https://github.com/Kumarvinay710)

 - [Sarthak Kumar](https://github.com/sk20215089)

  - [Ujjwal Kumar](https://github.com/ujjwal13818)

## Credits

This project was developed by [Sudhanshu Ranjan](https://github.com/sudhanshur555), [Vinay Kumar](https://github.com/Kumarvinay710) ,[Sarthak Kumar](https://github.com/sk20215089), [Ujjwal Kumar](https://github.com/ujjwal13818) as part of Department Project for 5th semester of Communication Lab. The code is based on examples from the Arduino community and various online resources, including:

- [Arduino Serial Communication Tutorial](https://www.arduino.cc/en/Tutorial/SerialCommunication)
- [Arduino Blink Example](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink)
- [LiquidCrystal_I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)
