# IDebugControl3::OutputDisassemblyLines

## Description

The **OutputDisassemblyLines** method disassembles several processor instructions and sends the resulting assembly instructions to the [output callbacks](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-input-and-output).

## Parameters

### `OutputControl` [in]

Specifies the output control that determines which client's output callbacks receive the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx). For more information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

### `PreviousLines` [in]

Specifies the number of lines of instructions before the instruction at *Offset* to include in the output. Typically, each instruction is output on a single line. However, some instructions can take up several lines of output; this can cause the number of lines output before the instruction at *Offset* to be greater than *PreviousLines*.

### `TotalLines` [in]

Specifies the total number of lines of instructions to include in the output. Typically, each instruction is output on a single line. However, some instructions can take up several lines of output; this can cause the number of lines output to be greater than *TotalLines*.

### `Offset` [in]

Specifies the location in the target's memory of the instructions to disassemble. The disassembly output will start *PreviousLines* lines before these processor instructions.

### `Flags` [in]

Specifies the bit-flags that affect the behavior of this method. The following table lists the bits that can be set.

| Bit-Flag | Effect when set |
| --- | --- |
| DEBUG_DISASM_EFFECTIVE_ADDRESS | Compute the effective address of each instruction from the current register information and output it. |
| DEBUG_DISASM_MATCHING_SYMBOLS | If the address of an instruction has an exact symbol match, output the symbol. |
| DEBUG_DISASM_SOURCE_LINE_NUMBER | Include the source line number of each instruction in the output. |
| DEBUG_DISASM_SOURCE_FILE_NAME | Include the source file name in the output. |

### `OffsetLine` [out, optional]

Receives the line number in the output that contains the instruction at *Offset*. If *OffsetLine* is **NULL**, this information is not returned.

### `StartOffset` [out, optional]

Receives the location in the target's memory of the first instruction included in the output. If *StartOffset* is **NULL**, this information is not returned.

### `EndOffset` [out, optional]

Receives the location in the target's memory of the instruction that follows the last disassembled instruction.

### `LineOffsets` [out, optional]

Receives the locations in the target's memory of the instructions included in the output starting with the instruction at *Offset*. *LineOffsets* is an array that contains *TotalLines* elements.

*Offset* is the value of first entry in this array unless there was an error disassembling the instructions before this instruction. In this case, the first entry will contain DEBUG_ANY_ID and *Offset* will be placed in the second entry in the array (index one).

If the output for an instruction spans multiple lines, the element in the array that corresponds to the first line of the instruction will contain the address of the instruction.

If *LineOffsets* is **NULL**, this information is not returned.

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

[OutputDisassembly](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputdisassembly)

[u (Unassemble)](https://learn.microsoft.com/windows-hardware/drivers/debugger/u--unassemble-)