# IDebugClient5::GetNumberOutputCallbacks

## Description

The **GetNumberOutputCallbacks** method returns the number of [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output) registered over all clients.

## Parameters

### `Count` [out]

Receives the number of output callbacks that have been registered.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Each client can have at most one output callback registered with it.

For more information about callbacks, see [Callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-callback-objects).

## See also

[GetNumberEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumbereventcallbacks)

[GetNumberInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getnumberinputcallbacks)

[GetOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getoutputcallbacks)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[IDebugOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugoutputcallbacks)

[SetOutputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-setoutputcallbacks)