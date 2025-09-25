## Description

Stores a file in the specified supplement to a symbol store. The file is typically associated with a file in the symbol server.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `SrvPath` [in, optional]

The path to the symbol store.

### `Node` [in]

The symbol file associated with the supplemental file.

### `File` [in]

The name of the file.

### `Flags` [in]

If this parameter is **SYMSTOREOPT_COMPRESS**, the file is compressed in the symbol store. Currently, there are no other supported values.

## Return value

If the function succeeds, the return value is the fully qualified path for the supplemental file.

If the function fails, the return value is **NULL**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An important use for this function is to store delta files. For more information, see [SymSrvDeltaName](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsrvdeltaname).

This function returns a pointer to a buffer that may be reused by another function. Therefore, be sure to copy the data returned to another buffer immediately.

The symbol server stores supplemental files with the same extension in a common directory. For example, Sup1.xml would be stored in the following directory: *SymPath*\supplement\*Node*\xml.

The administrator of a store can prevent users from writing supplemental files by creating a read-only file in the root of the store named Supplement. Alternatively, the administrator can create the supplement directory and use ACLs to control access.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[SymSrvGetSupplement](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-symsrvgetsupplement)