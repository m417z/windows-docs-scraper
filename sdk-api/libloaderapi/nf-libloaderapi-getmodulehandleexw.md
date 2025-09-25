# GetModuleHandleExW function

## Description

Retrieves a module handle for the specified module and increments the module's reference count unless GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT is specified. The module must have been loaded by the calling process.

## Parameters

### `dwFlags` [in]

This parameter can be zero or one or more of the following values. If the module's reference count is incremented, the caller must use the [FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) function to decrement the reference count when the module handle is no longer needed.

#### GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS (0x00000004)

The *lpModuleName* parameter is an address in the module.

#### GET_MODULE_HANDLE_EX_FLAG_PIN (0x00000001)

The module stays loaded until the process is terminated, no matter how many times [FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) is called.

This option cannot be used with GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT.

#### GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x00000002)

The reference count for the module is not incremented. This option is equivalent to the behavior of [GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew). Do not pass the retrieved module handle to the [FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) function; doing so can cause the DLL to be unmapped prematurely. For more information, see Remarks.

This option cannot be used with GET_MODULE_HANDLE_EX_FLAG_PIN.

### `lpModuleName` [in, optional]

The name of the loaded module (either a .dll or .exe file), or an address in the module (if *dwFlags* is GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS).

For a module name, if the file name extension is omitted, the default library extension .dll is appended. The file name string can include a trailing point character (.) to indicate that the module name has no extension. The string does not have to specify a path. When specifying a path, be sure to use backslashes (\\), not forward slashes (/). The name is compared (case independently) to the names of modules currently mapped into the address space of the calling process.

If this parameter is NULL, the function returns a handle to the file used to create the calling process (.exe file).

### `phModule` [out]

A handle to the specified module. If the function fails, this parameter is `NULL`.

The **GetModuleHandleEx** function does not retrieve handles for modules that were loaded using the **LOAD_LIBRARY_AS_DATAFILE** flag. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw).

##### - dwFlags.GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS (0x00000004)

The *lpModuleName* parameter is an address in the module.

##### - dwFlags.GET_MODULE_HANDLE_EX_FLAG_PIN (0x00000001)

The module stays loaded until the process is terminated, no matter how many times [FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) is called.

This option cannot be used with GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT.

##### - dwFlags.GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x00000002)

The reference count for the module is not incremented. This option is equivalent to the behavior of [GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew). Do not pass the retrieved module handle to the [FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) function; doing so can cause the DLL to be unmapped prematurely. For more information, see Remarks.

This option cannot be used with GET_MODULE_HANDLE_EX_FLAG_PIN.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, see [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The handle returned is not global or inheritable. It cannot be duplicated or used by another process.

If *lpModuleName* does not include a path and there is more than one loaded module with the same base name and extension, you cannot predict which module handle will be returned. To work around this problem, you could specify a path, use [side-by-side assemblies](https://learn.microsoft.com/windows/win32/Msi/side-by-side-assemblies), or specify a memory location rather than a DLL name in the *lpModuleName* parameter.

If *dwFlags* contains GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, the **GetModuleHandleEx** function returns a handle to a mapped module without incrementing its reference count. However, if this handle is passed to the [FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) function, the reference count of the mapped module will be decremented. Therefore, do not pass a handle returned by **GetModuleHandleEx** with GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT to the [FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) function. Doing so can cause a DLL module to be unmapped prematurely.

If *dwFlags* contains GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, this function must be used carefully in a multithreaded application. There is no guarantee that the module handle remains valid between the time this function returns the handle and the time it is used. For example, a thread retrieves a module handle, but before it uses the handle, a second thread frees the module. If the system loads another module, it could reuse the module handle that was recently freed. Therefore, first thread would have a handle to a module different than the one intended.

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/win32/WinProg/using-the-windows-headers).

> [!NOTE]
> The `libloaderapi.h` header defines **GetModuleHandleEx** as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Dynamic-Link Library Functions](https://learn.microsoft.com/windows/win32/Dlls/dynamic-link-library-functions)

[FreeLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary)

[GetModuleFileName](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew)

[LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw)

[LoadLibraryEx](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)