# IDebugControl::OutputVersionInformation

## Description

The **OutputVersionInformation** method prints version information about the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) to the debugger console.

## Parameters

### `OutputControl` [in]

Specifies where to send the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

## Return value

This method may also return other error values, including error values caused by the engine being busy. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The information that is sent to the output can include the mode of the debugger, the path and version of the debugger DLLs, the extension DLL search path, the extension DLL chain, and the version of the operating system that is running on the host computer.

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).