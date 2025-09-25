# CoFreeAllLibraries function

## Description

Frees all the DLLs that have been loaded with the [CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary) function (called internally by [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)), regardless of whether they are currently in use.

## Remarks

To unload libraries, **CoFreeAllLibraries** uses a list of loaded DLLs for each process that the COM library maintains. The [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) and [OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize) functions call **CoFreeAllLibraries** internally, so applications usually have no need to call this function directly.

## See also

[CoFreeLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreelibrary)

[CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries)

[CoFreeUnusedLibrariesEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibrariesex)

[CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary)