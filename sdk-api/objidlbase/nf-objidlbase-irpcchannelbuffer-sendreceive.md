# IRpcChannelBuffer::SendReceive

## Description

Sends a method invocation across an RPC channel to the server stub.

## Parameters

### `pMessage` [in, out]

A pointer to an [RPCOLEMESSAGE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-rpcolemessage) structure that has been populated with marshaled data.

### `pStatus` [out]

If not **NULL**, set to 0 on successful execution.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Before invoking this method, the [GetBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcchannelbuffer-getbuffer) method must have been invoked to allocate a channel buffer. Upon return, the **dataRepresentation** buffer of the [RPCOLEMESSAGE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-rpcolemessage) structure will have been modified to include the data returned by the method invoked on the server. If the invocation was successful, the RPC channel buffer has been freed; otherwise the caller must free it explicitly by calling [FreeBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcchannelbuffer-freebuffer).

## See also

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)