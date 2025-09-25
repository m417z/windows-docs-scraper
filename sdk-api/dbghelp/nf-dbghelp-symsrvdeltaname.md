# SymSrvDeltaName function

## Description

Generates the name for a file that describes the relationship between two different versions of the same symbol or image file.
Using this feature prevents applications from having to regenerate such information every time they analyze two files.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `SymPath` [in, optional]

The symbol path. The function uses only the symbol stores described in standard syntax for symbol stores. All other paths are ignored. If this parameter is **NULL**, the function uses the symbol path set using the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) or [SymSetSearchPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsetsearchpath) function.

### `Type` [in]

The extension for the generated file name.

### `File1` [in]

The path of the first version of the symbol or image file.

### `File2` [in]

The path of the second version of the symbol or image file.

## Return value

If the function succeeds, the return value is the resulting file name.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function opens the two specified files, reads the indexing information from the header, and passes this information to the symbol server so it can create the file name. If you specify the *Type* parameter as "xml", the name is the index of *File1*, followed by a dash, followed by the index of *File2*, followed by an .xml extension. For example:

3F3D5C755000-3F3D647621000.xml

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy the data returned to another buffer immediately.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)