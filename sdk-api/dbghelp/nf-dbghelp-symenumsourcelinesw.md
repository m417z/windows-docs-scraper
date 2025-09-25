# SymEnumSourceLinesW function

## Description

Enumerates all source lines in a module.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `Base` [in]

The base address of the module.

### `Obj` [in, optional]

The name of an .obj file within the module. The scope of the enumeration is limited to this file. If this parameter is **NULL** or an empty string, all .obj files are searched.

### `File` [in, optional]

A wildcard expression that indicates the names of the source files to be searched. If this parameter is **NULL** or an empty string, all files are searched.

### `Line` [in, optional]

The line number of a line within the module. The scope of the enumeration is limited to this line. If this parameter is 0, all lines are searched.

### `Flags` [in]

If this parameter is ESLFLAG_FULLPATH, the function matches the full path in the *File* parameter.

### `EnumLinesCallback` [in]

A
[SymEnumLinesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumlines_callback) callback function that receives the line information.

### `UserContext` [in, optional]

A user-defined value that is passed to the callback function, or **NULL**. This parameter is typically used by an application to pass a pointer to a data structure that provides context for the callback function.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

> [!NOTE]
> The dbghelp.h header defines SymEnumSourceLines as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymEnumLinesProc](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-psym_enumlines_callback)

[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize)