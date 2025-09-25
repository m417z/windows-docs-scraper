# IDebugClient::OutputIdentity

## Description

The **OutputIdentity** method formats and outputs a string describing the computer and user this client represents.

## Parameters

### `OutputControl` [in]

Specifies where to send the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Flags` [in]

Set to zero.

### `Format` [in]

Specifies a format string similar to the **printf** format string. However, this format string must only contain one formatting directive, **%s**, which will be replaced by a description of the computer and user this client represents.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The specific content of the string varies with the operating system. If the client is remotely connected, some network information may also be present.

For more information about client objects, see [Client Objects](https://learn.microsoft.com/windows-hardware/drivers/debugger/client-objects).

## See also

[GetIdentity](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getidentity)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)