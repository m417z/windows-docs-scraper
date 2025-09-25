# CoLoadLibrary function

## Description

Loads a specific DLL into the caller's process.

**CoLoadLibrary** is equivalent to [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa). **CoLoadLibrary** does not affect the lifetime of the library.

## Parameters

### `lpszLibName` [in]

The name of the library to be loaded.

### `bAutoFree` [in]

This parameter is maintained for compatibility with 16-bit applications, but is ignored.

## Return value

If the function succeeds, the return value is a handle to the loaded library; otherwise, it is **NULL**.

## Remarks

The [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) function does not call **CoLoadLibrary**. **CoLoadLibrary** loads a DLL specified by the *lpszLibName* parameter into the process that called **CoGetClassObject**. Containers should not call **CoLoadLibrary** directly.

Internally, a reference count is kept on the loaded DLL by using **CoLoadLibrary** to increment the count and the [CoFreeLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreelibrary) function to decrement it.

## See also

[CoFreeAllLibraries](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreealllibraries)

[CoFreeLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreelibrary)

[CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries)

[CoFreeUnusedLibrariesEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibrariesex)