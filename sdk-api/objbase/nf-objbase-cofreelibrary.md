# CoFreeLibrary function

## Description

Frees a library that, when loaded, was specified to be freed explicitly.

**Note** This function is provided for compatibility with 16-bit Windows.

## Parameters

### `hInst` [in]

A handle to the library module to be freed, as returned by the [CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary) function.

## Remarks

The **CoFreeLibrary** function should be called to free a library that is to be freed explicitly. This is established when the library is loaded with the *bAutoFree* parameter of [CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary) set to **FALSE**. It is illegal to free a library explicitly when the corresponding **CoLoadLibrary** call specifies that it be freed automatically (the *bAutoFree* parameter is set to **TRUE**).

## See also

[CoFreeAllLibraries](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreealllibraries)

[CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries)

[CoFreeUnusedLibrariesEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibrariesex)

[CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary)