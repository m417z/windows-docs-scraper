# FILEGROUPDESCRIPTORW structure

## Description

Defines the CF_FILEGROUPDESCRIPTOR clipboard format.

## Members

### `cItems`

Type: **UINT**

The number of elements in **fgd**.

### `fgd`

Type: **[FILEDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-filedescriptora)[1]**

An array of [FILEDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-filedescriptora) structures that contain the file information.

## Remarks

> [!NOTE]
> The shlobj_core.h header defines FILEGROUPDESCRIPTOR as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).