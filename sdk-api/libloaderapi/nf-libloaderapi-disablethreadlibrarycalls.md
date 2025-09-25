# DisableThreadLibraryCalls function

## Description

Disables the DLL_THREAD_ATTACH and DLL_THREAD_DETACH notifications for the specified dynamic-link library (DLL). This can reduce the size of the working set for some applications.

## Parameters

### `hLibModule` [in]

A handle to the DLL module for which the DLL_THREAD_ATTACH and DLL_THREAD_DETACH notifications are to be disabled. The [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya), [LoadLibraryEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa), or [GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function returns this handle. Note that you cannot call **GetModuleHandle** with `NULL` because this returns the base address of the executable image, not the DLL image.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. The **DisableThreadLibraryCalls** function fails if the DLL specified by *hModule* has active static thread local storage, or if *hModule* is an invalid module handle. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **DisableThreadLibraryCalls** function lets a DLL disable the DLL_THREAD_ATTACH and DLL_THREAD_DETACH notification calls. This can be a useful optimization for multithreaded applications that have many DLLs, frequently create and delete threads, and whose DLLs do not need these thread-level notifications of attachment/detachment. A remote procedure call (RPC) server application is an example of such an application. In these sorts of applications, DLL initialization routines often remain in memory to service DLL_THREAD_ATTACH and DLL_THREAD_DETACH notifications. By disabling the notifications, the DLL initialization code is not paged in because a thread is created or deleted, thus reducing the size of the application's working code set. To implement the optimization, modify a DLL's DLL_PROCESS_ATTACH code to call **DisableThreadLibraryCalls**.

Do not call this function from a DLL that is linked to the static C run-time library (CRT). The static CRT requires DLL_THREAD_ATTACH and DLL_THREAD_DETATCH notifications to function properly.

This function does not perform any optimizations if static [Thread Local Storage (TLS)](https://learn.microsoft.com/windows/win32/procthread/thread-local-storage) is enabled. Static TLS is enabled when using **thread_local** variables, **__declspec( thread )** variables, or function-local **static**.

## See also

[Dynamic-Link Library Entry-Point Function](https://learn.microsoft.com/windows/win32/Dlls/dynamic-link-library-entry-point-function)

[Dynamic-Link Library Functions](https://learn.microsoft.com/windows/win32/Dlls/dynamic-link-library-functions)

[FreeLibraryAndExitThread](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibraryandexitthread)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)