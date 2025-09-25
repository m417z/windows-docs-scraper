# IDebugInputCallbacks::EndInput

## Description

The **EndInput** callback method is called by the engine to indicate that it is no longer waiting for input.

## Return value

This method's return value is ignored by the engine.

## Remarks

Even if the engine has not called [IDebugInputCallbacks::StartInput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebuginputcallbacks-startinput) for this [IDebugInputCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebuginputcallbacks) object, the engine will call **EndInput** if another IDebugInputCallbacks object returned an error from the **IDebugInputCallbacks::StartInput** method.

For more information about debugger engine input, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).