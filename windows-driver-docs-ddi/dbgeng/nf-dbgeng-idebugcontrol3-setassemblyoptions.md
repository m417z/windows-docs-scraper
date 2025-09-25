# IDebugControl3::SetAssemblyOptions

## Description

The **SetAssemblyOptions** method sets the assembly and disassembly options that affect how the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) assembles and disassembles processor instructions for the target.

## Parameters

### `Options` [in]

Specifies the new assembly and disassembly options to be used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction). *Options* is a bit-set; it will replace the existing assembly and disassembly options. For possible values, see Remarks. DEBUG_ASMOPT_DEFAULT can be used to set the default options.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about using assembly with the debugger engine API, see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

The assembly and disassembly options affect how the debugger engine assembles and disassembles processor instructions for the target.

The options are represented by a bitset with the following bit flags.

| Constant | Description |
| --- | --- |
| **DEBUG_ASMOPT_VERBOSE** | When this bit is set, additional information is included in the disassembly.<br><br>This is equivalent to the **verbose** option in the **.asm** command. |
| **DEBUG_ASMOPT_NO_CODE_BYTES** | When this bit is set, the raw bytes for an instruction are not included in the disassembly.<br><br>This is equivalent to the **no_code_bytes** option in the **.asm** command. |
| **DEBUG_ASMOPT_IGNORE_OUTPUT_WIDTH** | When this bit is set, the debugger ignores the width of the output display when formatting instructions during disassembly.<br><br>This is equivalent to the **ignore_output_width** option in the **.asm** command. |
| **DEBUG_ASMOPT_SOURCE_LINE_NUMBER** | When this bit is set, each line of the disassembly output is prefixed with the line number of the source code provided by symbol information.<br><br>This is equivalent to the **source_line** option in the **.asm** command. |

Additionally, the value DEBUG_ASMOPT_DEFAULT represents the default set of assembly and disassembly options. This means that all the options in the preceding table are turned off.

## See also

[.asm (Change Disassembly Options)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-asm--change-disassembly-options-)

[AddAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addassemblyoptions)

[Assemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-assemble)

[Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble)

[GetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getassemblyoptions)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[RemoveAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removeassemblyoptions)