# IRpcChannelBuffer::IsConnected

## Description

Determines whether the RPC channel is connected.

## Return value

If the RPC channel knows that the server object has been disconnected,
the return value is **S_FALSE**. Otherwise, it is **S_OK**.

## Remarks

Channel implementations typically report server connectedness based on their
local state and are not expected to test transport-level connections or make
any calls to the server to prove connectedness.
It is possible for this method to return **S_OK**
even when the server object has been disconnected.

## See also

[IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer)