# SymSrvGetFileIndexesW function

## Description

Retrieves the indexes for the specified .pdb, .dbg, or image file that would be used to store the file. The combination of these values uniquely identifies the file in the symbol server. They can be used when calling the [SymFindFileInPath](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symfindfileinpath) function to search for a file in a symbol store.

## Parameters

### `File` [in]

The name of the file.

### `Id` [out]

The first of three identifying parameters.

### `Val1` [out]

The second of three identifying parameters.

### `Val2` [out, optional]

The third of three identifying parameters.

### `Flags` [in]

This parameter is reserved for future use.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)