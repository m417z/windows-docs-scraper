# IDebugRegisters::GetInstructionOffset

## Description

The **GetInstructionOffset** method returns the location of the current thread's current instruction.

## Parameters

### `Offset` [out]

Receives the location in the target's virtual address space of the target's current instruction.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The meaning of the value returned by this method is architecture-dependent. In particular, for an Itanium processor, the virtual address returned can indicate an address within a bundle.

The method [GetInstructionOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getinstructionoffset2) performs the same task as this method but also allows the register source to be specified.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetInstructionOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getinstructionoffset2)

[IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)