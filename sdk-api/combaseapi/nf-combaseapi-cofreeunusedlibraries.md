# CoFreeUnusedLibraries function

## Description

Unloads any DLLs that are no longer in use, probably because the DLL no longer has any instantiated COM objects outstanding.

**Note** This function is provided for compatibility with 16-bit Windows.

## Remarks

Applications can call **CoFreeUnusedLibraries** periodically to free resources. It is most efficient to call it either at the top of a message loop or in some idle-time task. **CoFreeUnusedLibraries** internally calls [DllCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow) for DLLs that implement and export that function.

## See also

[CoFreeAllLibraries](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreealllibraries)

[CoFreeLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreelibrary)

[CoFreeUnusedLibrariesEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibrariesex)

[CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary)