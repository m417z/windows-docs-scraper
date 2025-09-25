# CoGetPSClsid function

## Description

Returns the CLSID of the DLL that implements the proxy and stub for the specified interface.

## Parameters

### `riid` [in]

The interface whose proxy/stub CLSID is to be returned.

### `pClsid` [out]

Specifies where to store the proxy/stub CLSID for the interface specified by *riid*.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The proxy/stub CLSID was successfully returned. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete this operation. |

## Remarks

The **CoGetPSClsid** function looks at the **HKEY_CLASSES_ROOT**\**Interfaces**\*{string form of riid}*\**ProxyStubClsid32** key in the registry to determine the CLSID of the DLL to load in order to create the proxy and stub for the interface specified by *riid*. This function also returns the CLSID for any interface IID registered by [CoRegisterPSClsid](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterpsclsid) within the current process.

## See also

[CoRegisterPSClsid](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterpsclsid)