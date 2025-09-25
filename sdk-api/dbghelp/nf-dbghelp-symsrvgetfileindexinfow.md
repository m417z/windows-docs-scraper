# SymSrvGetFileIndexInfoW function

## Description

Retrieves the index information for the specified .pdb, .dbg, or image file.

## Parameters

### `File` [in]

The name of the file.

### `Info` [out]

A [SYMSRV_INDEX_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symsrv_index_info) structure that receives the index information.

### `Flags` [in]

This parameter is reserved for future use.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is not for general use. Those writing utilities for the management of files in symbol server stores may use to this function to predict the relative path the symbol server will look for a file. It is used by srctool.exe to actually populate symbol server stores. It may also be of use to those looking to find the parameters to feed the [SymFindFileInPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfindfileinpath) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

> [!NOTE]
> The dbghelp.h header defines SymSrvGetFileIndexInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SYMSRV_INDEX_INFO](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-symsrv_index_info)