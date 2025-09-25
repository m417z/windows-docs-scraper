# IDebugRegisters::GetStackOffset

## Description

The **GetStackOffset** method returns the current thread's current stack location.

## Parameters

### `Offset` [out]

Receives the location in the process's virtual address space of the current thread's current stack location.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The meaning of value returned by this method is architecture specific.

The method [GetStackOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getstackoffset2) performs the same task as this method but also allows the register source to be specified.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetStackOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getstackoffset2)

[IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)