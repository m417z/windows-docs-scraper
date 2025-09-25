# IDebugControl3::AddAssemblyOptions

## Description

The **AddAssemblyOptions** method turns on some of the assembly and disassembly options.

## Parameters

### `Options` [in]

Specifies the assembly and disassembly options to turn on. *Options* is a bit-set that will be combined with the existing engine options using the bitwise OR operator. For a description of the options, see [DEBUG_ASMOPT_XXX](https://learn.microsoft.com/previous-versions/ff541443(v=vs.85)).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

These methods can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

For more information about using assembly with the [debugger engine API](https://learn.microsoft.com/windows-hardware/drivers/debugger/d), see [Assembling and Disassembling Instructions](https://learn.microsoft.com/windows-hardware/drivers/debugger/assembling-and-disassembling-instructions).

## See also

[.asm (Change Disassembly Options)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-asm--change-disassembly-options-)

[Assemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-assemble)

[DEBUG_ASMOPT_XXX](https://learn.microsoft.com/previous-versions/ff541443(v=vs.85))

[Disassemble](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-disassemble)

[GetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getassemblyoptions)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[RemoveAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removeassemblyoptions)

[SetAssemblyOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-setassemblyoptions)