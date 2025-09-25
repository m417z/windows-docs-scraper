# LoadPackagedLibrary function

## Description

Loads the specified packaged module and its dependencies into the address space of the calling process.

## Parameters

### `lpwLibFileName` [in]

The file name of the packaged module to load. The module can be a library module (a .dll file) or an executable module (an .exe file).

If this parameter specifies a module name without a path and the file name extension is omitted, the function appends the default library extension .dll to the module name. To prevent the function from appending .dll to the module name, include a trailing point character (.) in the module name string.

If this parameter specifies a path, the function searches that path for the module. The path cannot be an absolute path or a relative path that contains ".." in the path. When specifying a path, be sure to use backslashes (\\), not forward slashes (/). For more information about paths, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

If the specified module is already loaded in the process, the function returns a handle to the loaded module. The module must have been originally loaded from the package dependency graph of the process.

If loading the specified module causes the system to load other associated modules, the function first searches loaded modules, then it searches the package dependency graph of the process. For more information, see Remarks.

### `Reserved`

This parameter is reserved. It must be 0.

## Return value

If the function succeeds, the return value is a handle to the loaded module.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**LoadPackagedLibrary** function is a simplified version of [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa). Packaged apps can use **LoadPackagedLibrary** to load packaged modules. Unpackaged applications cannot use **LoadPackagedLibrary**; if a unpackaged application calls this function it fails with **APPMODEL_ERROR_NO_PACKAGE**.

**LoadPackagedLibrary** returns a handle to the specified module and increments its reference count. If the module is already loaded, the function returns a handle to the loaded module. The calling process can use the handle returned by **LoadPackagedLibrary** to identify the module in calls to the
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function. Use the [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary) function to free a loaded module and decrement its reference count.

If the function must search for the specified module or its dependencies, it searches only the package dependency graph of the process. This is the application's package plus any dependencies specified as `<PackageDependency>` in the `<Dependencies>` section of the application's package manifest. Dependencies are searched in the order they appear in the manifest. The package dependency graph is specified in the `<Dependencies>` section of the application's package manifest. Dependencies are searched in the order they appear in the manifest. The search proceeds as follows:

1. The function first searches modules that are already loaded. If the specified module was originally loaded from the package dependency graph of the process, the function returns a handle to the loaded module. If the specified module was not loaded from the package dependency graph of the process, the function returns **NULL**.
2. If the module is not already loaded, the function searches the package dependency graph of the process.
3. If the function cannot find the specified module or one of its dependencies, the function fails.

It is not safe to call
**LoadPackagedLibrary** from
[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain). For more information, see the Remarks section in
**DllMain**.

> [!NOTE]
On Windows Phone, **LoadPackagedLibrary** must be called from `PhoneAppModelHost.dll`. Using `Kernel32.dll` is not supported.

## See also

[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order)