# IDebugSymbols::OutputTypedDataVirtual

## Description

The **OutputTypedDataVirtual** method formats the contents of a variable in the target's virtual memory, and then sends this to the [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## Parameters

### `OutputControl` [in]

Specifies the output control used to determine which output callbacks can receive the output. See [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx) for possible values.

### `Offset` [in]

Specifies the location in the target's virtual address space of the variable.

### `Module` [in]

Specifies the base address of the module containing the type.

### `TypeId` [in]

Specifies the type ID of the type.

### `Flags` [in]

Specifies the formatting flags. See [DEBUG_TYPEOPTS_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-typeopts-xxx) for possible values.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The output produced by this method is the same as for the debugger command **DT**. See [dt (Display Type)](https://learn.microsoft.com/windows-hardware/drivers/debugger/dt--display-type-).

For more information about types, see [Types](https://learn.microsoft.com/windows-hardware/drivers/debugger/types). For more information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).