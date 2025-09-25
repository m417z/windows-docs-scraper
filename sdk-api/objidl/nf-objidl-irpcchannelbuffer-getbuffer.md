# IRpcChannelBuffer::GetBuffer

## Description

Retrieves a buffer into which data can be marshaled for transmission.

## Parameters

### `pMessage` [in, out]

A pointer to an [RPCOLEMESSAGE](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-rpcolemessage) data structure.

### `riid` [in]

A reference to the identifier of the interface to be marshaled.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)