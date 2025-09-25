# SRCCODEINFOW structure

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

## Remarks

> [!NOTE]
> The dbghelp.h header defines SRCCODEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).