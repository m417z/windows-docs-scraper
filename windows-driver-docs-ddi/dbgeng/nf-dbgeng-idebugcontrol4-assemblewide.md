# IDebugControl4::AssembleWide

## Description

The **AssembleWide** method assembles a single processor instruction. The assembled instruction is placed in the target's memory.

## Parameters

### `Offset` [in]

Specifies the location in the target's memory to place the assembled instruction.

### `Instr` [in]

Specifies the instruction to assemble. The instruction is assembled according to the target's effective processor type (returned by [SetEffectiveProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-seteffectiveprocessortype)).

### `EndOffset` [out]

Receives the location in the target's memory immediately following the assembled instruction. *EndOffset* can be used when assembling multiple instructions.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The assembly language depends on the effective processor type of the target machine. For information about the assembly language, see the processor documentation.

**Note**
The [Assemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-assemble) and **AssembleWide** methods are not supported on some architectures, and on some other architectures not all instructions are supported.

The assembly language options--returned by [GetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getassemblyoptions)--affect the operation of this method.

For an overview of using assembly in debugger applications, see [Debugging in Assembly Mode](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-in-assembly-mode). For more information about using assembly with the [debugger engine API](https://learn.microsoft.com/windows-hardware/drivers/debugger/d), see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

## See also

[Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble)

[GetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getassemblyoptions)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)