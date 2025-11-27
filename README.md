# Beautiful UI Dashboard

A modern, beautifully styled Qt6 dashboard application with an elegant user interface.

![Qt6](https://img.shields.io/badge/Qt-6.4+-green.svg)
![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

## Features

- ✨ Modern gradient sidebar with smooth navigation
- 🎨 Beautiful card-based dashboard layout
- 📊 Styled progress bars and statistics
- 🌈 Custom themed buttons with hover effects
- 📱 Multiple pages (Dashboard, Settings, Profile)
- 🎯 Clean and intuitive user interface

## Screenshots

The application features:
- A purple gradient sidebar for navigation
- Card-based statistics display
- Styled progress indicators
- Primary and secondary action buttons
- Recent activity list view
- Settings and Profile pages

## Prerequisites

- CMake 3.16 or higher
- Qt 6.4 or higher
- C++17 compatible compiler

## Building

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build
make

# Run the application
./BeautifulUI
```

## Project Structure

```
├── CMakeLists.txt          # CMake configuration
├── src/
│   ├── main.cpp            # Application entry point
│   ├── mainwindow.h        # Main window header
│   └── mainwindow.cpp      # Main window implementation
└── resources/
    └── resources.qrc       # Qt resource file
```

## Customization

The UI uses Qt stylesheets for styling. You can easily customize:
- Color scheme (currently purple gradient theme)
- Font sizes and weights
- Border radius and padding
- Hover and active states

## License

MIT License