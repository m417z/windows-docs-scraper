# ISurrogate::FreeSurrogate

## Description

Unloads a DLL server.

## Return value

This method can return the standard return values E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

COM calls **FreeSurrogate** when there are no more DLL servers running in the surrogate process. When **FreeSurrogate** is called, the method must properly revoke all of the class factories registered in the surrogate, and then cause the surrogate process to exit.

Surrogate processes must call the [CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries) function periodically to unload DLL servers that are no longer in use. The surrogate process assumes this responsibility, which would normally be the client's responsibility. **CoFreeUnusedLibraries** calls the [DllCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow) function on any loaded DLL servers. Because **CoFreeUnusedLibraries** depends on the existence and proper implementation of **DllCanUnloadNow** in DLL servers, it is not guaranteed to unload all DLL servers that should be unloaded --not every server implements **DllCanUnloadNow**, and this function is unreliable for free-threaded DLLs. Additionally, the surrogate has no way of being informed when all DLL servers are gone. COM, however, can determine when all DLL servers have been unloaded, and will then call the **FreeSurrogate** method.

## See also

[DllSurrogate](https://learn.microsoft.com/windows/desktop/com/dllsurrogate)

[ISurrogate](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogate)

[Writing a Custom Surrogate](https://learn.microsoft.com/windows/desktop/com/writing-a-custom-surrogate)