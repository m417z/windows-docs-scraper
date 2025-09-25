# IDebugControl::OutputCurrentState

## Description

The **OutputCurrentState** method prints the current state of the current target to the debugger console.

## Parameters

### `OutputControl` [in]

Specifies which clients to send the output to. For possible values see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Flags` [in]

Specifies the bit set that determines the information to print to the debugger console. *Flags* can be any combination of values from the following table.

| Flag | Description |
| --- | --- |
| DEBUG_CURRENT_SYMBOL | Symbol string for the address of the current instruction. |
| DEBUG_CURRENT_DISASM | Disassembly of the current instruction. |
| DEBUG_CURRENT_REGISTERS | Current register values. |
| DEBUG_CURRENT_SOURCE_LINE | File name and line number of the source corresponding to the current instruction. |

Alternatively, *Flags* can be set to DEBUG_CURRENT_DEFAULT. This value includes all of the above flags.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Setting the flags contained in *Flags* merely allows the information to be printed. The information will not always be printed (for example, it will not be printed if it is not available).

This is the same status information that is printed when breaking into the debugger.

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).