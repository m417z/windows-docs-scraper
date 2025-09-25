# ISurrogate::LoadDllServer

## Description

Loads a DLL server into the implementing surrogate. COM calls this method when there is an activation request for the DLL server's class, if the class is registered as [DllSurrogate](https://learn.microsoft.com/windows/desktop/com/dllsurrogate).

## Parameters

### `Clsid` [in]

The CLSID of the DLL server to be loaded.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

Upon receiving a load request through **LoadDllServer**, the surrogate must perform the following steps:

1. Create a class factory object that supports [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory), and [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal).
2. Call [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) to register the new class factory object as the class factory for the requested CLSID.

This class factory's implementation of [IClassFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance) will create an instance of the requested CLSID method by calling [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) to get the class factory which creates an actual object for the given CLSID.

## See also

[CoRegisterSurrogate](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregistersurrogate)

[DllSurrogate](https://learn.microsoft.com/windows/desktop/com/dllsurrogate)

[ISurrogate](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isurrogate)

[Writing a Custom Surrogate](https://learn.microsoft.com/windows/desktop/com/writing-a-custom-surrogate)