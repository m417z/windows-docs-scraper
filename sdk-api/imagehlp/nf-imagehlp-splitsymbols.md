# SplitSymbols function

## Description

Strips symbols from the specified image.

## Parameters

### `ImageName` [in]

The name of the image from which to split symbols.

### `SymbolsPath` [in]

The subdirectory for storing symbols. This parameter is optional.

### `SymbolFilePath` [out]

The name of the generated symbol file. This file typically has a .dbg extension.

### `Flags` [in]

The information to be split from the image. This parameter can be zero or a combination of the following values.

| Value | Meaning |
| --- | --- |
| **SPLITSYM_EXTRACT_ALL**<br><br>0x00000002 | Usually, an image with the symbols split off will still contain a MISC debug directory with the name of the symbol file. Therefore, the debugger can still find the symbols. Using this flag removes this link. The end result is similar to using the **-debug:none** switch on the Microsoft linker. |
| **SPLITSYM_REMOVE_PRIVATE**<br><br>0x00000001 | This strips off the private CodeView symbolic information when generating the symbol file. |
| **SPLITSYM_SYMBOLPATH_IS_SRC**<br><br>0x00000004 | The symbol file path contains an alternate path to locate the .pdb file. |

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SplitSymbols** function should be used when stripping symbols from an image. It will create a symbol file that all compatible debuggers understand. The format is defined in WinNT.h and consists of an image header, followed by the array of section headers, the FPO information, and all debugging symbolic information from the image.

If the *SymbolsPath* parameter is **NULL**, the symbol file is stored in the directory where the image exists. Otherwise, it is stored in the subdirectory below *SymbolsPath* that matches the extension of the image. Using this method reduces the chances of symbol file collision. For example, the symbols for myapp.exe will be in the *SymbolsPath*\exe directory and the symbols for myapp.dll will be in the *SymbolsPath*\dll directory.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)