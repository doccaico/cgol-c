## Simple Conway's Game of Life

[Play](https://doccaico.github.io/cgol-c/)

### User guide
- [R] randomize
- [P] pause and unpause
- [W] speed up
- [S] speed down
- [A] change ALIVE color (Random)
- [D] change DEAD color (Random)

### Desktop Build (MSVC)
```sh
# debug build
$ build_desktop.bat --debug

# release build
$ build_desktop.bat --release

# run
$ build\bin\game_desktop.exe

# build and run in one line
$ call build_desktop.bat --debug && build\bin\game_desktop.exe
```

### Web Build
```sh
# debug build
$ build_web.bat --debug

# release build
$ build_web.bat --release

# go to localhost:8000 in your browser
$ python -m http.server
```
