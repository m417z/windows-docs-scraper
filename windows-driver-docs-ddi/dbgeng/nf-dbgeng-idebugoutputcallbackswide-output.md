# IDebugOutputCallbacksWide::Output

## Description

The **Output** callback method is called by the engine to send output from the client to the **IDebugOutputCallbacksWide** object that is registered with the client.

## Parameters

### `Mask` [in]

Specifies the [DEBUG_OUTPUT_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-output-xxx) bit flags that indicate the nature of the output.

### `Text` [in]

Specifies the output that is being sent.

## Return value

The return value is ignored by the engine unless it indicates a remote procedure call error; in this case the client, with which this **IDebugEventCallbacksWide** object is registered, is disabled.

## Remarks

The engine calls this method only if the supplied value of *Mask* is allowed by the client's output control.

For more information about debugger engine output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).