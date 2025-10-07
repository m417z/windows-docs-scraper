# CleanupCredentialCache function

The **CleanupCredentialCache** function is implemented by certain Security Support Providers (SSP) to flush the SSP credential cache.

## Parameters

This function has no parameters.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**.

## Remarks

The **CleanupCredentialCache** function is implemented by the following SSPs:

- MSNSSPC.dll
- MSAPSSPC.dll

The implementation of **CleanupCredentialCache** by these SSPs always returns **TRUE**.

Before attempting to obtain a module handle to export **CleanupCredentialCache**, the application must verify that the SSP that has been loaded is one of the known SSPs implementing the **CleanupCredentialCache** function.

In order to flush the SSP credential cache, the application must obtain a module handle for the SSP by calling the [**GetModuleHandle**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function. After obtaining the module, the application should export the **CleanupCredentialCache** function implemented by the SSP by calling the [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function, passing the module returned by **GetModuleHandle** and **CleanupCredentialCache** as input parameters.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

> [!Note]
> WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | MSNSSPC.dll;

MSAPSSPC.dll |