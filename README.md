# Mult - cli application for testing knowledge of multiplication table.

## Version 2.2

## Usage

### Build and install:

```shell
mkdir build
cd build/
cmake ..
cmake --build .
```
For installation:
```shell
cmake --install .
```

For packages:
```shell
cpack --config CPackConfig.cmake # for .7z, .deb, .rpm and .tar.gz pacages
```

or

```shell
cpack --config CPackConfig.cmake -G GENERATOR # for desired package type 
```

### Usage installed:
```shell
mult
```

or

```shell
mult -h # for instruction
```
#### Instruction:
- mult version 2.2
- Usage: mult
- For help use flags   -h, --help
- For test start program without flags than press any key to start test or Q to quit.
- If you want to stop test press ^D.

## LICENSE:
[MIT](./LICENSE)