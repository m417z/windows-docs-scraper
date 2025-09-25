# SymGetOmaps function

## Description

Retrieves the omap tables within a loaded module.

## Parameters

### `hProcess` [in]

A handle to a process. This handle must have been previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function.

### `BaseOfDll` [in]

The base address of the module.

### `OmapTo` [out]

An array of address map entries to the new image layout taken from the original layout. For details on the map entries, see the [OMAP](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-omap) structure.

### `cOmapTo` [out]

The number of entries in the *OmapTo* array.

### `OmapFrom` [out]

An array of address map entries from the new image layout to the original layout (as described by the debug symbols). For details on the map entries, see the [OMAP](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-omap) structure.

### `cOmapFrom` [out]

The number of entries in the *OmapFrom* array.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails (the omap is not found), the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[OMAP](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-omap)