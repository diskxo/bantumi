<p align="center">
  <a href="" rel="noopener">
 <img src="https://www.ispazio.net/wp-content/uploads/2011/09/Screenshot-2011.09.20-10.49.11.png" alt="Project logo"></a>
</p>

<h3 align="center">Bantumi - diskxo Remake</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-developing-yellow)]()
[![GitHub Issues](https://img.shields.io/github/issues/diskxo/bantumi)](https://github.com/diskxo/bantumi)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/diskxo/bantumi)](https://img.shields.io/github/issues-pr/diskxo/bantumi)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Deployment](#deployment)
- [Usage](#usage)
- [Built Using](#built_using)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

A remake created by [@diskxo](https://twitter.com/diskxo_) of Bantumi/Kalah official game.

## 🏁 Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See [deployment](#deployment) for notes on how to deploy the project on a live system.

Clone this repository with web interface or via git command:

```bash
git clone https://github.com/diskxo/bantumi
```

and save it into your local workspace.

## Prerequisites

#### Windows

- [SFML 2.5.1 - GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip)
- [GCC 7.3.0 MinGW (DW2) 32-bit (for Windows)](https://downloads.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z?ts=gAAAAABiCPISZlK6KeJPFkS8_Njt5-hapDJK8HRnt_RnH-rFaZAX1xCODdbRhImYmibYQkervhYczQM9d5dzqgzLkXMObiYChg%3D%3D&r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fmingw-w64%2Ffiles%2FToolchains%2520targetting%2520Win32%2FPersonal%2520Builds%2Fmingw-builds%2F7.3.0%2Fthreads-posix%2Fdwarf%2Fi686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z%2Fdownload)
- [Git Bash (for Windows) ](https://git-scm.com/downloads)

#### MacOS

- [SFML 2.5.1 - Clang 64-bit](https://www.sfml-dev.org/files/SFML-2.5.1-macOS-clang.tar.gz)
- Command Line Tools / XCode (type "xcode-select --install" in terminal to trigger the installer)

#### Linux

- Get SFML 2.5.1 from your distro if it has it, or compile from source

#### All

- [Visual Studio Code](https://code.visualstudio.com/download)
- Extensions (install from Extensions panel):
  - [Official C/C++ Extension (0.21.0+)](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  - [Shader languages support for VS Code (Optional Syntax Highlighting)](https://marketplace.visualstudio.com/items?itemName=slevesque.shader)
  - [x86 and x86_64 Assembly (Optional Syntax Highlighting)](https://marketplace.visualstudio.com/items?itemName=13xforever.language-x86-64-assembly)
  - [Studio Icons (Optional Icon Theme)](https://marketplace.visualstudio.com/items?itemName=jtlowe.vscode-icon-theme)

---

## Installing

#### Windows

1. Download & Extract SFML to **C:/SFML-2.5.1/** where the bin/lib/include folders are contained within
2. Download & Extract MinGW to **C:/mingw32/** where the bin/lib/include folders are contained within

#### MacOS

1. Install "Command Line Tools" in MacOS if they're not already installed (type "xcode-select --install" in terminal)
2. Follow the "Installing SFML" directions here: https://www.sfml-dev.org/tutorials/2.5/start-osx.php#installing-sfml

#### Linux

1. Ensure the GCC Toolchain is installed

```bash
sudo apt install build-essential
```

or

```bash
sudo pacman -S base-devel
```

2. Install libsfml

```bash
sudo apt install libsfml-dev
```

or

```bash
sudo pacman -S sfml
```

The SFML version you got will vary depending on the distro. 2.5.1 is included in [Ubuntu 19.04 Disco Dingo](http://cdimage.ubuntu.com/daily-live/current/HEADER.html) for example.

#### All

1. Download & Install Visual Studio Code if you don't already have it.
2. Install the official **C/C++** Extension, reload the window & wait for the dependencies to install.
3. If on Windows, install **Git Bash**, and ensure the **"terminal.integrated.shell.windows"** property in the project's **settings.json** is set to **bash.exe**'s correct location (default: C:/Program Files/Git/bin/bash.exe). We'll be using this for the terminal in our workspace so that the Makefile can run in both Windows, Mac & Linux
4. In **settings.json** Ensure **Path** in the **terminal.integrated.env.windows** object is set to the correct location of the compiler's executable (example: C:\\mingw32\\bin) and the SFML directory is correct as well. Keep in mind Paths should be separated by a semi-colon with no spaces between.

**Note:** You can manage the "Path" environment variable from Windows if you'd like, but I've found sandboxing it in VS Code is better for tracking things like .dll dependencies.

---

## 🔧 Running the tests <a name = "tests"></a>

At this point, everything you need is installed

1. Open the **bantumi** folder in VS Code.

2. With Main.cpp (or any source file) open, check the lower-right to ensure "Win32/Mac/Linux" is the configuration set (this should be auto-selected by the C++ plugin). If it is not correct, hit **Ctrl+Shift+B** and select **C/Cpp: Select a configuration...** and choose the platform you're working on.

3. At this point you should be able to run a build task (**Ctrl+Shift+B** > **Build & Run**), but it'll be nicer to add keybindings for these tasks so you can build with 1 keypress.

4. Open the .vscode folder and click on the **\_keybindings.json** file. This is not an officially recognized file, but just contains the keybindings you can copy into the actual keybindings.json file.

5. Go into **File** > **Preferences** > **Keyboard Shortcuts** & click on the keybindings.json link at the top.

6. Copy the keybindings into this file. Feel free to change them if you don't like them later.

7. Hit the **F9** key to run the **Build & Run: Release** task. It should run the Makefile, find the compiler, build the Main.cpp into Main.o, and launch the sample SFML app. **Shift+F9** will launch the basic Debug build, and F8 will launch the actual Debugger alongside the Debug build.

### And coding style tests

Comments must be formatted by leaving a dedicated line within the code, and must be structured like this:

```c++
# this is an example.
```

## 🎈 Usage <a name="usage"></a>

--

## 🚀 Deployment <a name = "deployment"></a>

--

## ⛏️ Built Using <a name = "built_using"></a>

- [GCC](https://gcc.gnu.org/) - C++ compiler
- [SFML](https://www.sfml-dev.org) - Game Library
- [Visual Studio Code](https://code.visualstudio.com/) - Text Editor

## ✍️ Authors <a name = "authors"></a>

- [@diskxo](https://github.com/diskxo) - Initial work

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- Remake of the original game version into the Nokia 3310 phone
