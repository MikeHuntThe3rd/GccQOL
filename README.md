propper file layout for makefile:
```plaintext
project/
├── libs/          # All libraries go here 
│   ├── libglfw.a       # Linux/macOS static
│   ├── glfw3.lib       # Windows static
│   └── libglfw.dll.a   # MinGW import lib
├── include/        # Header files (.h)
│   └── header.h
├── src/            # Source files (.cpp)
│   └── source.cpp
├── main.cpp        # Main program
└── Makefile ```
