# IDebugControl::Input

## Description

The **Input** method requests an input string from the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction).

## Parameters

### `Buffer` [out]

Receives the input string from the engine.

### `BufferSize` [in]

Specifies the size, in characters, of the buffer that *Buffer* specifies. This size includes the space for the '\0' terminating character.

### `InputSize` [out, optional]

Receives the number of characters returned in *Buffer*. This size includes the space for the '\0' terminating character. If *InputSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not big enough to hold the whole input string and it was truncated. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

For an overview of input in the debugger engine, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

## See also

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[InputWide](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-inputwide)