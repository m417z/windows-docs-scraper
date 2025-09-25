# _SYMBOL_INFO_EX structure

## Description

The SYMBOL_INFO_EX structure describes the extended line symbol information.

## Members

### `SizeOfStruct`

Set to sizeof(SYMBOL_INFO_EX).

### `TypeOfInfo`

Type of the symbol information stored. DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE is the only supported type.

### `Offset`

Address of the first line that does not correspond to compiler added glue line.

### `Line`

First line number that does not correspond to a compiler added glue line.

### `Displacement`

Line displacement: Offset between given address and the first instruction of the line.

### `Reserved[4]`

Reserved for future use. This parameter can be set to any value.

## Remarks

Glue lines are code lines added to the binary by the compiler/linker. Glue lines do not have corresponding lines in the original source code. They are added to bind together functionality inside of the PE generated binary, for example calling NET framework functions inside of a native binary.