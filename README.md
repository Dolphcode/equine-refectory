# Equine Refectory
Temporary name decided by a group of idiots over a late night voice call. This repository is going to be an experiment in building and optimizing a 3D game using the OpenGL API. This game will be a tower defense game strongly based off of Bloons Tower Defense 6 with P2P multiplayer features.

Not sure if this is going to be published anywhere or anything yet but I will be uploading stable Linux and Windows releases to this repository for anyone who wants to give this project a try.
## Building
This is my first time integrating **CMake** into a project so I've left myself some instructions for building this project. A couple of notes:
 - Instead of generating GLAD header files offline I write some code in `CMakeLists.txt` to generate header files at configure time
 
#### Building for Windows
The way I did this was using the [Ninja](https://ninja-build.org/) build system for Windows. If you build this way (not using MSVC) make sure you have the Windows SDK installed (you can do this using the `winget` package manager or whatever Windows package manager of your choice).

When building with CMake specify `ninja` for the project file generator and simply run `ninja` in the build directory.

Alternatively you can run `cmake --build build` I think from the project root directory just like Linux (Note to self: Try this to see if it actaully works)

#### Building for Linux
For CMake configuration to work because GLAD headers are generated at configure time make sure you have a Python interpreter and that you install the `Jinja2` python module (`pip install Jinja2` or whatever package manager you use for Python).

Then you can just run `cmake --build build` from the project root directory.