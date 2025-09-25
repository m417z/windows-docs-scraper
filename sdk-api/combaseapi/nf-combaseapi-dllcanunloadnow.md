# DllCanUnloadNow function

## Description

Determines whether the DLL that implements this function is in use. If not, the caller can unload the DLL from memory.

OLE does not provide this function. DLLs that support the OLE Component Object Model (COM) should implement and export **DllCanUnloadNow**.

## Return value

If the function succeeds, the return value is S_OK. Otherwise, it is S_FALSE.

## Remarks

A call to **DllCanUnloadNow** determines whether the DLL from which it is exported is still in use. A DLL is no longer in use when it is not managing any existing objects (the reference count on all of its objects is 0).

### Notes to Callers

You should not have to call **DllCanUnloadNow** directly. OLE calls it only through a call to the [CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries) function. When it returns S_OK, **CoFreeUnusedLibraries** frees the DLL.

### Notes to Implementers

You must implement **DllCanUnloadNow** in, and export it from, DLLs that are to be dynamically loaded through a call to the [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) function. (You also need to implement and export the [DllGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllgetclassobject) function in the same DLL).

If a DLL loaded through a call to [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) fails to export **DllCanUnloadNow**, the DLL will not be unloaded until the application calls the [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) function to release the OLE libraries.

**DllCanUnloadNow** should return S_FALSE if there are any existing references to objects that the DLL manages.

## See also

[DllGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllgetclassobject)