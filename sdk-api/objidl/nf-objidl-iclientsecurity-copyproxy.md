# IClientSecurity::CopyProxy

## Description

Makes a private copy of the proxy for the specified interface.

## Parameters

### `pProxy` [in]

A pointer to the interface whose proxy is to be copied. This parameter cannot be **NULL**.

### `ppCopy` [out]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer that receives the copy of the proxy. This parameter cannot be **NULL**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more arguments are not valid. |

## Remarks

**CopyProxy** is called by the client to make a private copy of the proxy for the specified interface. The proxy copy has default values for the authentication information. Its authentication information can be changed through a call to [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket) without affecting any other clients of the original proxy. The copy has one reference, and the caller of **CopyProxy** must ensure that the proxy copy gets freed.

Local interfaces, such as [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) and [IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity), cannot be copied. You cannot duplicate a proxy manager using **CopyProxy**.

Copies of the same proxy have a special relationship with respect to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). Given a proxy, a, of the IA interface of a remote object, suppose a copy of a is created, called b. In this case, calling **QueryInterface** from the b proxy for IID_IA will not retrieve the IA interface on b, but the one on a, the original proxy.

Notice that anyone can query for a proxy and change security on it using [SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket). However, when you have made a copy of a proxy, no one can get the copy unless you give it to them. Only people who have the copy can set security on it.

The helper function [CoCopyProxy](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocopyproxy) encapsulates a [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) call for a pointer to IClientSecurity, a call to **CopyProxy** with the [IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity) pointer, and the release of the **IClientSecurity** pointer.

## See also

[CoCopyProxy](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocopyproxy)

[IClientSecurity](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclientsecurity)