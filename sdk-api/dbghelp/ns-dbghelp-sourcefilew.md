# SOURCEFILEW structure

## Description

Contains source file information.

## Members

### `ModBase`

The base address of the module.

### `FileName`

The fully qualified source file name.

## See also

[SymEnumSourceFiles](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symenumsourcefiles)

## Remarks

> [!NOTE]
> The dbghelp.h header defines SOURCEFILE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).