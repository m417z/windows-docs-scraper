# IDebugControl::OutputDisassembly

## Description

The **OutputDisassembly** method disassembles a processor instruction and sends the disassembly to the [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## Parameters

### `OutputControl` [in]

Specifies the output control that determines which client's output callbacks receive the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx). For more information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

### `Offset` [in]

Specifies the location in the target's memory of the instruction to disassemble.

### `Flags` [in]

Specifies the bit-flags that affect the behavior of this method. The following table lists the bits that can be set.

| Bit-Flag | Effect when set |
| --- | --- |
| DEBUG_DISASM_EFFECTIVE_ADDRESS | Compute the effective address from the current register information and display it. |
| DEBUG_DISASM_MATCHING_SYMBOLS | If the address of the instruction has an exact symbol match, output the symbol. |
| DEBUG_DISASM_SOURCE_LINE_NUMBER | Include the source line number of the instruction in the output. |
| DEBUG_DISASM_SOURCE_FILE_NAME | Include the source file name in the output. |

### `EndOffset` [out]

Receives the location in the target's memory of the instruction that follows the disassembled instruction.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The assembly language depends on the effective processor type of the target system. For information about the assembly language, see the processor documentation.

For an overview of using assembly in debugger applications, see [Debugging in Assembly Mode](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-in-assembly-mode). For more information about using assembly with the debugger engine API, see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

## See also

[Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OutputDisassemblyLines](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputdisassemblylines)