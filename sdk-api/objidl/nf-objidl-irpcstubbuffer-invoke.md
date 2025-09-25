# IRpcStubBuffer::Invoke

## Description

Invokes the interface that a stub represents.

## Parameters

### `_prpcmsg` [in, out]

A pointer to an [RPCOLEMESSAGE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-rpcolemessage) data structure containing the marshaled invocation arguments.

### `_pRpcChannelBuffer` [in]

A pointer to an [IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer) interface that controls an RPC marshaling channel.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer)