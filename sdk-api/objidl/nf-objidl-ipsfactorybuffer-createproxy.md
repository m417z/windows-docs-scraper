# IPSFactoryBuffer::CreateProxy

## Description

Creates a proxy for the specified remote interface.

## Parameters

### `pUnkOuter` [in]

A controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface; used for aggregation.

### `riid` [in]

The identifier of the interface to proxy.

### `ppProxy` [out]

A pointer to an [IRpcProxyBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcproxybuffer) interface to control marshaling.

### `ppv` [out]

A pointer to the interface specified by *riid*.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) implementation of the [IRpcProxyBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcproxybuffer) interface must not delegate to the outer controlling **IUnknown**.

## See also

[IPSFactoryBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipsfactorybuffer)

[IRpcProxyBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcproxybuffer)

[Proxy](https://learn.microsoft.com/windows/desktop/com/proxy)