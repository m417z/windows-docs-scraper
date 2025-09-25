# QueryOptionalDelayLoadedAPI function

## Description

Determines whether the specified function in a delay-loaded DLL is available on the system.

## Parameters

### `hParentModule` [in]

A handle to the calling module. Desktop applications can use the [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) or [GetModuleHandleEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandleexa) function to get this handle. Windows Store apps should set this parameter to `static_cast<HMODULE>(&__ImageBase)`.

### `lpDllName` [in]

The file name of the delay-loaded DLL that exports the specified function. This parameter is case-insensitive.

Windows Store apps should specify API sets, rather than monolithic DLLs. For example, api-ms-win-core-memory-l1-1-1.dll, rather than kernel32.dll.

### `lpProcName` [in]

The name of the function to query. This parameter is case-sensitive.

### `Reserved`

This parameter is reserved and must be zero (0).

## Return value

TRUE if the specified function is available on the system. If the specified function is not available on the system, this function returns FALSE. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A delay-loaded DLL is statically linked but not actually loaded into memory until the running application references a symbol exported by that DLL. Applications often delay load DLLs that contain functions the application might call only rarely or not at all, because the DLL is only loaded when it is needed instead of being loaded at application startup like other statically linked DLLs. This helps improve application performance, especially during initialization. A delay-load DLL is specified at link time with the [/DELAYLOAD (Delay Load Import)](https://learn.microsoft.com/cpp/build/reference/delayload-delay-load-import) linker option.

Applications that target multiple versions of Windows or multiple Windows device families also rely on delay-loaded DLLs to make visible extra features when they are available.

A desktop application can use delayed loading as an alternative to runtime dynamic linking that uses [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) or [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) to load a DLL and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to get a pointer to a function. A Windows Store app cannot use **LoadLibrary** or **LoadLibraryEx**, so to get the benefits to runtime dynamic linking, a Windows Store app must use the delayed loading mechanism.

To check whether a function in a delay-loaded DLL is available on the system, the application calls **QueryOptionalDelayLoadedAPI** with the specified function. If **QueryOptionalDelayLoadedAPI** succeeds, the application can safely call the specified function.

#### Examples

The following example shows how to use **QueryOptionalDelayLoadedAPI** to determine whether the [MkParseDisplayName](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-mkparsedisplayname) function is available on the system.

```cpp
#include <windows.h>
#include <libloaderapi2.h>

// For this example, you need to pass
// /delayload: ext-ms-win-com-ole32-l1-1-1.dll to link.exe.

EXTERN_C IMAGE_DOS_HEADER __ImageBase;

BOOL
AreMonikersSupported ()
{

    BOOL isApiAvailable;

    // Check if MkParseDisplayName is available on the system. It is only
    // available on desktop computers, and not on mobile devices or Xbox.

    isApiAvailable =
        QueryOptionalDelayLoadedAPI(static_cast<HMODULE>(&__ImageBase),
                                    "ext-ms-win-com-ole32-l1-1-1.dll",
                                    "MkParseDisplayName",
                                    0);

    return isApiAvailable;
}

```

## See also

[LoadPackagedLibrary](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-loadpackagedlibrary)

[Run-Time Dynamic Linking](https://learn.microsoft.com/windows/desktop/Dlls/run-time-dynamic-linking)