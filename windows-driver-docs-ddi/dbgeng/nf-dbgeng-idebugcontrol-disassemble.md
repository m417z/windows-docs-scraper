# IDebugControl::Disassemble

## Description

The **Disassemble** method disassembles a processor instruction in the target's memory.

## Parameters

### `Offset` [in]

Specifies the location in the target's memory of the instruction to disassemble.

### `Flags` [in]

Specifies the bit-flags that affect the behavior of this method. Currently the only flag that can be set is DEBUG_DISASM_EFFECTIVE_ADDRESS; when set, the engine will compute the effective address from the current register information and display it.

### `Buffer` [out, optional]

Receives the disassembled instruction. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `DisassemblySize` [out, optional]

Receives the size, in characters, of the disassembled instruction. If *DisassemblySize* is **NULL**, this information is not returned.

### `EndOffset` [out]

Receives the location in the target's memory of the instruction following the disassembled instruction.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, *Buffer* was too small to hold the disassembled instruction and the instruction was truncated to fit. |

## Remarks

The assembly language depends on the effective processor type of the target system. For information about the assembly language, see the processor documentation.

The disassembly options--returned by [GetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getassemblyoptions)--affect the operation of this method.

For an overview of using assembly in debugger applications, see [Debugging in Assembly Mode](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-in-assembly-mode). For more information about using assembly with the debugger engine API, see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

## See also

[Assemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-assemble)

[GetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getassemblyoptions)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[u (Unassemble)](https://learn.microsoft.com/windows-hardware/drivers/debugger/u--unassemble-)