# AVR ATmega32 Calculator

This repository contains a simple calculator project developed for AVR ATmega32 microcontroller using Proteus 8.10 simulation. It includes drivers for a Keypad and an LCD, along with customized types and the application code for the calculator.

## Project Structure

The repository is organized into the following directories:

- **mcal (Microcontroller Abstraction Layer):**
  - This directory contains the Device Input/Output (DIO) driver.
  - The DIO driver provides an abstraction layer for configuring and controlling the microcontroller's GPIO pins.

- **hal (Hardware Abstraction Layer):**
  - This directory contains drivers for the LCD and Keypad components.
  - The LCD driver facilitates interfacing with the LCD display.
  - The Keypad driver allows for scanning and reading input from the Keypad.
  
- **lib (Library):**
  - This directory contains `STD_Types.h`, a header file containing customized types.
  - `BIT_Math.h` is also located in this directory, providing macros for bit manipulation operations.

- **simulation:**
  - This directory contains the Proteus simulation files for the project.
  - You can find the circuit connection diagram and simulation videos here.

- **root directory:**
  - `application.c`: This is the main source code file for the calculator application.
    - It includes the logic for the calculator, utilizing the HAL drivers to interact with the LCD and Keypad.

## Simulation

To visualize and simulate the project, follow these steps:

1. Set up Proteus 8.10 or your preferred simulation software.
2. Navigate to the `simulation` folder and open the Proteus project file.
3. You will find the circuit connection diagram in the `circuit.png` file within the `simulation` folder.
4. Run the simulation to observe the calculator in action.
5. Additionally, you can watch simulation videos located at the root of the repository.

**Note:** This project was created using Proteus 8.10, and the simulation files may not work on older versions of Proteus.

## Contributing

If you'd like to contribute to this project, feel free to fork the repository and submit pull requests with your improvements. Be sure to follow best practices for code quality and documentation.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to the AVR community for their valuable resources and support.

Feel free to add any additional sections or information that may be relevant to your project. This README.md provides an organized structure for your project, making it easy for others to understand and contribute to your embedded systems project.

```bash
git clone https://github.com/MennatAllahhxx/AVR-Calculator.git
