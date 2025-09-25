# FreeLibraryAndExitThread function

## Description

Decrements the reference count of a loaded dynamic-link library (DLL) by one, then calls
[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) to terminate the calling thread. The function does not return.

## Parameters

### `hLibModule` [in]

A handle to the DLL module whose reference count the function decrements. The
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) or
[GetModuleHandleEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandleexa) function returns this handle.

Do not call this function with a handle returned by either the **GetModuleHandleEx** function (with the GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT flag) or the [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function, as they do not maintain a reference count for the module.

### `dwExitCode` [in]

The exit code for the calling thread.

## Remarks

The
**FreeLibraryAndExitThread** function allows threads that are executing within a DLL to safely free the DLL in which they are executing and terminate themselves. If they were to call
[FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary) and
[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) separately, a race condition would exist. The library could be unloaded before
**ExitThread** is called.

## See also

[DisableThreadLibraryCalls](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-disablethreadlibrarycalls)

[Dynamic-Link Library Functions](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-functions)

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary)

[Run-Time Dynamic Linking](https://learn.microsoft.com/windows/desktop/Dlls/run-time-dynamic-linking)