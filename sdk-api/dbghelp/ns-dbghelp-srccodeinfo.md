# SRCCODEINFO structure

## Description

Contains line information.

## Members

### `SizeOfStruct`

The size of the structure, in bytes.

### `Key`

This member is not used.

### `ModBase`

The base address of the module that contains the line.

### `Obj`

The name of the object file within the module that contains the line.

### `FileName`

The fully qualified source file name.

### `LineNumber`

The line number within the source file.

### `Address`

The virtual address of the first instruction of the line.

## See also

[SymEnumLinesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumlines_callback)