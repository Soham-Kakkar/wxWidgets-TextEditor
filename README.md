# MyWxApp - XRC-Based Text Editor (C++ / wxWidgets)

[![wxWidgets](https://img.shields.io/badge/wxWidgets-3.2-blue.svg)](https://www.wxwidgets.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A simple, lightweight text editor built with **wxWidgets** using **XRC** (XML Resource) for declarative UI design, focusing on clean separation between UI and application logic. Supports opening, editing, and saving plain text (.txt) and Markdown (.md) files.

## ✨ Features

- **File Operations**: Open (Ctrl+O), Save (Ctrl+S), Exit (Ctrl+Q) with confirmation dialog
- **Edit Operations**: Cut, Copy, Paste with standard shortcuts
- **File Support**: .txt, .md, and generic file loading
- **XRC-Based UI**: Declarative UI with runtime reload support (debug mode)
- **Keyboard Shortcuts**: Familiar editor bindings

## 🛠️ Prerequisites

- **wxWidgets 3.2+** (on Linux)
- **C++17 compiler** (g++ recommended)
- **make**
- Linux/macOS (Windows via MSYS2 or vcpkg)

## Build Instructions:

### Make sure WxWidgets is installed:
```bash
# Ubuntu/Debian
sudo apt install libwxgtk3.2-dev

# Fedora
sudo dnf install wxGTK-devel

# Arch
sudo pacman -S wxwidgets
```

### Debug Build (hot reloadable by editing the XRC file and restarting the application):
Compile:
```bash
make
```

Run:
```bash
./build/debug/MyWxApp
```

### Release Build (generates/compiles UI.hpp for embedded resources):
Compile:
```bash
make release
```

Run:   
```bash
./build/release/MyWxApp
```

## 🐛 Troubleshooting

- **Missing libs**: Make sure wxWidgets is installed. [Installation Guide](https://docs.wxwidgets.org/3.2/overview_install.html)
- **UI not loading**: Check UI.xrc exists and is correctly linked to in MyApp.cpp. Use Absolute Path.
- **GTK errors**: Install `libgtk-3-dev` and wxGTK3 deps
- **Hot reload**: Use `make debug`, edit src/resources/UI.xrc, restart

## 🚀 Future Enhancements

- Font size control
- Proper file saving (currently saveAs only)
- Syntax highlighting
- Find/Replace dialog
- Multiple tabs/documents
- Preferences/Settings
- Recent files list
- Theme support
- Cross Platform Support

## 📝 License

This project is MIT licensed. See [LICENSE](LICENSE) for details.

---

**Built with ❤️ using wxWidgets** | Contributions welcome!
