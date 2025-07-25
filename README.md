# Equine Refectory
Temporary name decided by a group of idiots over a late night voice call. This repository is going to be an experiment in building and optimizing a 3D game using the OpenGL API. This game will be a tower defense game strongly based off of Bloons Tower Defense 6 with P2P multiplayer features.

Not sure if this is going to be published anywhere or anything yet but I will be uploading stable Linux and Windows releases to this repository for anyone who wants to give this project a try.
## Building
This is my first time integrating **CMake** into a project so I've left myself some instructions for building this project. A couple of notes:
 - Instead of generating GLAD header files offline I write some code in `CMakeLists.txt` to generate header files at configure time

#### Building for Linux
For CMake configuration to work because GLAD headers are generated at configure time make sure you have a Python interpreter and that you install the `Jinja2` python package (`pip install Jinja2` or whatever package manager you use for Python).

Then you can just run `cmake --build build` from the project root directory.

#### Building for Windows
I used MSVC as the generator for this project with CMake and it seemed to work off the bat. Just like Linux make sure you have the `Jinja2` python package installed

Just run `cmake --build build` from the project root directory.

## Running
If you've manually built this project using CMake you will need to either
1. Run the project executable in the command line from the project root directory
2. Move the project executable to the project root directory
The executable needs to access the `res` folder in the project root directory. When shipping this project I will bundle both the resource directory and the project executable together for this purpose (or come up with some better way to find the project resource directory).

