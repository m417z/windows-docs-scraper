# SymSrvIsStore function

## Description

Determines whether the specified path points to a symbol store.

## Parameters

### `hProcess` [in, optional]

The handle of a process that you previously passed to the
[SymInitialize](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-syminitialize) function. If this parameter is set to **NULL**, the function determines only whether the store exists; otherwise, the function determines whether the store exists and contains a process entry for the specified process handle.

### `path` [in]

The path to a symbol store. The path can specify the default symbol store (for example, SRV*), point to an HTTP or HTTPS symbol server, or specify a UNC, absolute, or relative path to the store.

## Return value

If the path specifies a symbol store, the function returns **TRUE**. Otherwise, it returns **FALSE**. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

If the path points to the default symbol store (for example, SRV*) or to an HTTP or HTTPS symbol server, the function assumes the store exists.

If there is a proxy computer between the client computer and the server, the version of the SymSrv.dll on the proxy cannot be less than the version that is on the client.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

To call the Unicode version of this function, define DBGHELP_TRANSLATE_TCHAR.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)