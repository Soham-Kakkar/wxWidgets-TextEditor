# MyWxApp - Text Editor

[![wxWidgets](https://img.shields.io/badge/wxWidgets-3.2-blue.svg)](https://www.wxwidgets.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A simple, lightweight text editor built with **wxWidgets** using **XRC** (XML Resource) for declarative UI design. Supports opening, editing, and saving plain text (.txt) and Markdown (.md) files.

## ✨ Features

- **File Operations**: Open (Ctrl+O), Save (Ctrl+S), Exit (Ctrl+Q) with confirmation dialog
- **Edit Operations**: Cut (Ctrl+X), Copy (Ctrl+C), Paste (Ctrl+V)
- **File Format Support**: .txt, .md, and all files (*.*)
- **Hot-reload UI**: XRC-based UI supports reloading without rebuild
- **Keyboard Shortcuts**: Standard editor shortcuts throughout

## 🛠️ Prerequisites

- **wxWidgets 3.2+** (on Linux)
- **C++17 compiler** (g++ recommended)
- **make**
- Linux/macOS (Windows via MSYS2 or vcpkg)

### Build Instructions:

1. **Get Dependencies**:
   
```bash
   ./get_deps.sh
```

2. **Generate UI Resources**:
   
```bash
   ./wxrc.sh  # Processes src/resources/UI.xrc → UI.hpp
```

**Release** (generates/compiles UI.hpp for embedded resources):
```bash
   make clean && make
```

4. **Run**:
   
```bash
   ./build/MyWxApp
```

## 🐛 Troubleshooting

- **Missing libs in build/**: Run `./get_deps.sh` again
- **UI not loading (debug)**: Check src/resources/UI.xrc exists
- **UI not loading (release)**: Run `./wxrc.sh` (check UI.hpp generated)
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
