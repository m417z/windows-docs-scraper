# CoRegisterPSClsid function

## Description

Enables a downloaded DLL to register its custom interfaces within its running process so that the marshaling code will be able to marshal those interfaces.

## Parameters

### `riid` [in]

A pointer to the IID of the interface to be registered.

### `rclsid` [in]

A pointer to the CLSID of the DLL that contains the proxy/stub code for the custom interface specified by *riid*.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and S_OK.

## Remarks

Typically, the code responsible for marshaling an interface pointer into the current running process reads the **HKEY_CLASSES_ROOT\Interfaces** section of the registry to obtain the CLSID of the DLL containing the ProxyStub code to be loaded. To obtain the ProxyStub CLSIDs for an existing interface, the code calls the [CoGetPSClsid](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetpsclsid) function.

In some cases, however, it may be desirable or necessary for an in-process handler or in-process server to make its custom interfaces available without writing to the registry. A DLL downloaded across a network may not even have permission to access the local registry, and because the code originated on another computer, the user, for security purposes, may want to run it in a restricted environment. Or a DLL may have custom interfaces that it uses to talk to a remote server and may also include the ProxyStub code for those interfaces. In such cases, a DLL needs an alternative way to register its interfaces. **CoRegisterPSClsid**, used in conjunction with [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject), provides that alternative.

#### Examples

A DLL would typically call **CoRegisterPSClsid** as shown in the following code fragment.

```cpp
HRESULT RegisterMyCustomInterface(DWORD *pdwRegistrationKey)
{
    HRESULT hr = CoRegisterClassObject(CLSID_MyProxyStubClsid,
        pIPSFactoryBuffer,
        CLSCTX_INPROC_SERVER,
        REGCLS_MULTIPLEUSE
        pdwRegistrationKey);
    if(SUCCEEDED)(hr))
    {
        hr = CoRegisterPSClsid(IID_MyCustomInterface, CLSID_MyProxyStubClsid);
    }

    return hr;
}

```

## See also

[CoGetPSClsid](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetpsclsid)

[CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject)