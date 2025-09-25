# IDebugSymbols3::OutputTypedDataPhysical

## Description

The **OutputTypedDataPhysical** method formats the contents of a variable in the target computer's physical memory, and then sends this to the [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## Parameters

### `OutputControl` [in]

Specifies the output control used to determine which output callbacks can receive the output. See [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx) for possible values.

### `Offset` [in]

Specifies the physical address in the target computer's memory of the variable.

### `Module` [in]

Specifies the base address of the module containing the type of the variable.

### `TypeId` [in]

Specifies the type ID of the type of the variable.

### `Flags` [in]

Specifies the bit-set containing the formatting options. See [DEBUG_TYPEOPTS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-typeopts-xxx) for possible values.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is only available in kernel mode debugging.

The output produced by this method is the same as for the debugger command **DT**. See [dt (Display Type)](https://learn.microsoft.com/windows-hardware/drivers/debugger/dt--display-type-).

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types). For information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).