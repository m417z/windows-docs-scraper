# IDebugControl3::GetAssemblyOptions

## Description

The **GetAssemblyOptions** method returns the assembly and disassembly options that affect how the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) assembles and disassembles processor instructions for the target.

## Parameters

### `Options` [out]

Receives a bit-set that contains the assembly and disassembly options. For a description of these options, see [DEBUG_ASMOPT_XXX](https://learn.microsoft.com/previous-versions/ff541443(v=vs.85)).

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about using assembly with the debugger engine API, see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

## See also

[.asm (Change Disassembly Options)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-asm--change-disassembly-options-)

[AddAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addassemblyoptions)

[Assemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-assemble)

[DEBUG_ASMOPT_XXX](https://learn.microsoft.com/previous-versions/ff541443(v=vs.85))

[Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[RemoveAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removeassemblyoptions)

[SetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setassemblyoptions)