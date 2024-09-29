
# Thermal Distribution Simulation Program

This C++ program simulates the thermal distribution on a thin metal plate using dynamically created matrices. The user can create a 2D grid, define initial side temperatures, stimulate a specific point on the grid, and calculate the resulting thermal distribution. The results can be displayed as a grid or saved as an image file.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)


## Project Overview

The primary goal of this project is to simulate thermal distribution over a thin metal plate modeled as a grid of unknown dimensions. The program allows the user to interactively set up the grid, input initial conditions, apply heat stimulation to a point on the grid, and calculate how the heat spreads throughout the plate.

The software includes functionality for:
1. **Creating a dynamic 2D grid**.
2. **Setting boundary temperature values** for the grid's top, bottom, left, and right sides.
3. **Stimulating the grid at a specific point**, applying a specific temperature at that point.
4. **Simulating thermal distribution** and calculating the heat dissipation based on the initial conditions and the point of stimulation.
5. **Displaying the thermal grid** in the terminal.
6. **Saving the simulation results as an image** file (in `.bmp` format).

## Features

- **Dynamic Grid Creation**: Users can create a 2D grid with customizable dimensions.
- **Boundary Condition Settings**: Set the temperature values for all four sides of the grid.
- **Point Stimulation**: Apply heat to a specific point on the grid and observe how the temperature spreads.
- **Heat Distribution Calculation**: The software calculates the thermal distribution across the grid using an iterative method.
- **Display Grid**: View the current grid of temperatures in the console.
- **Save as Bitmap**: Export the final thermal distribution grid as a `.bmp` image for visualization.

## Installation

### Prerequisites

To run the program, you will need:
- A C++ compiler (e.g., GCC, Clang, or MSVC)
- C++11 or later
- Makefile (optional for automated builds)

### Installation Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/thermal-distribution-simulation.git
    cd thermal-distribution-simulation
    ```

2. Compile the program using the following command:
    ```bash
    g++ -o thermal_simulator main.cpp Bitmap_Helper.h Functions.h
    ```

3. Run the program:
    ```bash
    ./thermal_simulator
    ```

## Usage

Upon running the program, the user will be presented with an interactive menu that allows them to perform various operations on the thermal grid.

### Menu Options

- **Option 1**: Create a 2D grid by specifying the number of rows and columns.
- **Option 2**: Set the boundary temperatures (top, bottom, left, right).
- **Option 3**: Stimulate the grid at a specific point with a defined temperature.
- **Option 4**: Simulate the thermal distribution based on the set conditions and stimulation.
- **Option 5**: Print the current thermal grid to the console.
- **Option 6**: Exit the program.

### Example Workflow

Here is an example of how you might use the program:

1. **Create a 5x5 grid**:
    ```
    Choose 1 to create a 2D grid for your simulation
    ```
    Input:
    ```bash
    Enter the number of rows of the grid: 5
    Enter the number of columns of the grid: 5
    ```

2. **Set boundary temperatures**:
    ```
    Choose 2 to set the side temperatures for your grid
    ```
    Input:
    ```bash
    Enter the temperature of the top side: 100
    Enter the temperature of the bottom side: 50
    Enter the temperature of the left side: 75
    Enter the temperature of the right side: 25
    ```

3. **Stimulate the grid at a point**:
    ```
    Choose 3 to set the point you want to stimulate your simulation
    ```
    Input:
    ```bash
    Enter the row you want to stimulate: 2
    Enter the column you want to stimulate: 2
    Enter the stimulation temperature: 150
    ```

4. **Simulate the thermal distribution**:
    ```
    Choose 4 to calculate the thermal distribution
    ```
    Input:
    ```bash
    Enter the tolerance value for the simulation: 0.01
    ```

    The program will calculate the thermal distribution and save it to a bitmap image file named `ThermalDistribution.bmp`.

5. **View the thermal grid**:
    ```
    Choose 5 to view the thermal distribution simulation grid
    ```

6. **Exit the program**:
    ```
    Choose 6 to exit the program
    ```

## File Structure

- `main.cpp` — The main program file that handles user input and coordinates the simulation process.
- `Bitmap_Helper.h` — A helper file that contains functions for saving the thermal grid as a bitmap image.
- `Functions.h` — A file containing helper functions that manage grid creation, boundary condition setting, stimulation, and thermal dissipation.

## Contributing

Contributions are welcome! If you encounter any issues or have suggestions for improvement, feel free to open an issue or submit a pull request.

1. Fork the repository.
2. Create a new branch:
    ```bash
    git checkout -b feature-branch
    ```
3. Make your changes:
    ```bash
    git commit -am 'Add new feature'
    ```
4. Push the changes:
    ```bash
    git push origin feature-branch
    ```
5. Open a Pull Request.

