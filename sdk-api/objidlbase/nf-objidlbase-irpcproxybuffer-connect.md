# IRpcProxyBuffer::Connect

## Description

Initializes a client proxy, binding it to the specified RPC channel.

## Parameters

### `pRpcChannelBuffer` [in]

A pointer to the [IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer) interface that the proxy uses to marshal data.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IRpcProxyBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcproxybuffer)