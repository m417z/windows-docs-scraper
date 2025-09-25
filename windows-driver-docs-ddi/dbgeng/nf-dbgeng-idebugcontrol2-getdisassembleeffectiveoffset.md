# IDebugControl2::GetDisassembleEffectiveOffset

## Description

The **GetDisassembleEffectiveOffset** method returns the address of the last instruction disassembled using [Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble).

## Parameters

### `Offset` [out]

Receives the address in the target's memory of the effective offset from the last instruction disassembled.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The effective offset is the memory location used by an instruction. For example, if the last instruction to be disassembled is `move ax, [ebp+4]`, the effective address is the value of `ebp+4`. This corresponds to the **$ea** pseudo-register.

For more information about using assembly with the debugger engine API, see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

## See also

[Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)