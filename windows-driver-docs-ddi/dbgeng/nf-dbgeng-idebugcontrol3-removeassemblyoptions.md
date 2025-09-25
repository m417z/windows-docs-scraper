# IDebugControl3::RemoveAssemblyOptions

## Description

The **RemoveAssemblyOptions** method turns off some of the assembly and disassembly options.

## Parameters

### `Options` [in]

Specifies the assembly and disassembly options to turn off. *Options* is a bit-set; the new value of the engine's options will equal the bitwise NOT of *Options* combined with the old value by using the bitwise AND operator. For a description of the assembly and disassembly options, see [DEBUG_ASMOPT_XXX](https://learn.microsoft.com/previous-versions/ff541443(v=vs.85)).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

For more information about using assembly with the debugger engine API, see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

## See also

[.asm (Change Disassembly Options)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-asm--change-disassembly-options-)

[AddAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-addassemblyoptions)

[Assemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-assemble)

[DEBUG_ASMOPT_XXX](https://learn.microsoft.com/previous-versions/ff541443(v=vs.85))

[Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble)

[GetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getassemblyoptions)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[SetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setassemblyoptions)