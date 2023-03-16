## Description

- PixTerm is a 2D or 3D graphical library for terminal rendering using ascii characters

## Usage 

### Build

```
git clone https://github.com/Jastcher/PixTerm
```

- Navigate to the PixTerm directory and set **runner.sh** as executable
```
cd PixTerm
chmod +x runner.sh
```

- Run **runner.sh** to build, any argument to build and run
```
./runner.sh [optional argument (any char) to build and run]
```

### Installation

- Copy PixTerm/Build/libPixTerm.a and PixTerm/include folder to you project files
```
cp -r include [your project path]
cp Build/libPixTerm.a [your project path/include/lib]
```

- Compile your project  with `-lPixTerm -Linclude/lib -Iinclude` 

## Inspiration

- I took inspiration from OpenGL and glfw, making use of buffers and glm
