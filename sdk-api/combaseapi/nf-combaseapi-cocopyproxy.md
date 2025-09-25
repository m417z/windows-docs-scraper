# CoCopyProxy function

## Description

Makes a private copy of the specified proxy.

## Parameters

### `pProxy` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the proxy to be copied. This parameter cannot be **NULL**.

### `ppCopy` [out]

Address of the pointer variable that receives the interface pointer to the copy of the proxy. This parameter cannot be **NULL**.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **E_INVALIDARG** | One or more arguments are invalid. |

## Remarks

**CoCopyProxy** makes a private copy of the specified proxy. Typically, this function is called when a client needs to change the authentication information of its proxy through a call to either [CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket) or [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) without changing this information for other clients. **CoSetProxyBlanket** affects all the users of an instance of a proxy, so creating a private copy of the proxy through a call to **CoCopyProxy** and then calling **CoSetProxyBlanket** (or **IClientSecurity::SetBlanket**) using the copy eliminates the problem.

This helper function encapsulates the following sequence of common calls (error handling excluded):

``` syntax
    pProxy->QueryInterface(IID_IClientSecurity, (void**)&pcs);
    pcs->CopyProxy(punkProxy, ppunkCopy);
    pcs->Release();
```

Local interfaces may not be copied. [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) and [IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity) are examples of existing local interfaces.

Copies of the same proxy have a special relationship with respect to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). Given a proxy, a, of the IA interface of a remote object, suppose a copy of a is created, called b. In this case, calling **QueryInterface** from the b proxy for IID_IA will not retrieve the IA interface on b, but the one on a, the original proxy with the "default" security settings for the IA interface.

## See also

[CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket)

[IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket)

[Security in COM](https://learn.microsoft.com/windows/desktop/com/security-in-com)