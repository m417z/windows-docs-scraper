# IMAGE_COFF_SYMBOLS_HEADER structure

## Description

Represents the COFF symbols header.

## Members

### `NumberOfSymbols`

The number of symbols.

### `LvaToFirstSymbol`

The virtual address of the first symbol.

### `NumberOfLinenumbers`

The number of line-number entries.

### `LvaToFirstLinenumber`

The virtual address of the first line-number entry.

### `RvaToFirstByteOfCode`

The relative virtual address of the first byte of code.

### `RvaToLastByteOfCode`

The relative virtual address of the last byte of code.

### `RvaToFirstByteOfData`

The relative virtual address of the first byte of data.

### `RvaToLastByteOfData`

The relative virtual address of the last byte of data.

## See also

[ImageHlp Structures](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-structures)