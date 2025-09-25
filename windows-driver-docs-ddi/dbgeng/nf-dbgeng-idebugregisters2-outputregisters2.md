# IDebugRegisters2::OutputRegisters2

## Description

The **OutputRegisters2** method formats and outputs the target's [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## Parameters

### `OutputControl` [in]

Specifies which clients should be sent the output of the formatted registers. See [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx) for possible values.

### `Source` [in]

Specifies the register source to query.

The possible values are listed in the following table.

| Value | Register source |
| --- | --- |
| DEBUG_REGSRC_DEBUGGEE | Fetch register information from the target. |
| DEBUG_REGSRC_EXPLICIT | Fetch register information from the current explicit [register context](https://learn.microsoft.com/windows-hardware/drivers/debugger/changing-contexts). |
| DEBUG_REGSRC_FRAME | Fetch register information from the current scope's register context.<br><br>**Note** Stack unwinding does not guarantee accurate updating of the register context, so the scope frame's register context might not be accurate in all cases. |

### `Flags` [in]

Specifies which register sets to print. This can either be DEBUG_REGISTERS_DEFAULT to print commonly used registers, DEBUG_REGISTERS_ALL to print all of the register sets, or a combination of the values listed in the following table.

| Value | Description |
| --- | --- |
| DEBUG_REGISTERS_INT32 | Print the 32-bit register set. |
| DEBUG_REGISTERS_INT64 | Print the 64-bit register set. |
| DEBUG_REGISTERS_FLOAT | Print the floating-point register set. |

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The registers are formatted in a way that is specific to the target architecture's register set.

The method [OutputRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-outputregisters) performs the same task as this method but always uses the target as the register source.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)

[OutputRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-outputregisters)