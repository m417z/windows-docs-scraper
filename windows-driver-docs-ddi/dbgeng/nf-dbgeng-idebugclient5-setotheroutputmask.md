# IDebugClient5::SetOtherOutputMask

## Description

The **SetOtherOutputMask** method sets the output mask for another client.

## Parameters

### `Client` [in]

Specifies the client whose output mask will be set.

### `Mask` [in]

Specifies the new output mask for the client. See [DEBUG_OUTPUT_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-output-xxx) for a description of the possible values for *Mask*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For an overview of output in the debugger engine, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

## See also

[GetOtherOutputMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getotheroutputmask)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)

[SetOutputMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-setoutputmask)