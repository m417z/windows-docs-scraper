# SymGetFileLineOffsets64 function

## Description

Locates line information for the specified module and file name.

## Parameters

### `hProcess` [in]

A handle to the process that was originally passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `ModuleName` [in, optional]

The name of the module in which lines are to be located. If this parameter is **NULL**, the function searches all modules.

### `FileName` [in]

The name of the file in which lines are to be located.

### `Buffer` [out]

An array of offsets for each line. The offset for the line n is stored in element n-1. Array elements for lines that do not have line information are left unchanged.

### `BufferLines` [in]

The size of the *Buffer* array, in elements.

## Return value

If the function succeeds, the return value is the highest line number found.
This value is zero if no line information was found.

If the function fails, the return value is LINE_ERROR. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)