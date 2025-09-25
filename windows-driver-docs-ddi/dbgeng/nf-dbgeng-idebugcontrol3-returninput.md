# IDebugControl3::ReturnInput

## Description

The **ReturnInput** method is used by **IDebugInputCallbacks** objects to send an input string to the engine following a request for input.

## Parameters

### `Buffer` [in]

Specifies the input string being sent to the engine.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The engine had already received the input it requested. The input string in *Buffer* was not received by the engine. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

For an overview of input in the debugger engine, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).