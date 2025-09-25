# IDebugClient3::GetIdentity

## Description

The **GetIdentity** method returns a string describing the computer and user this client represents.

## Parameters

### `Buffer` [out, optional]

Specifies the buffer to receive the string. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size of the buffer *Buffer*.

### `IdentitySize` [out, optional]

Receives the size of the string. If *IdentitySize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful |
| **S_FALSE** | The size of the string was greater than the size of the buffer, so it was truncated to fit into the buffer. |

## Remarks

The specific content of the string varies with the operating system. If the client is remotely connected, some network information may also be present.

For more information about client objects, see [Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects).

## See also

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[OutputIdentity](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-outputidentity)