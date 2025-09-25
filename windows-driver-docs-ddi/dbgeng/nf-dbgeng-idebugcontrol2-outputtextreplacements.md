# IDebugControl2::OutputTextReplacements

## Description

The **OutputTextReplacements** method prints all the currently defined user-named aliases to the debugger's output stream.

## Parameters

### `OutputControl` [in]

Specifies the output control to use when printing the aliases. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Flags` [in]

Must be set to DEBUG_OUT_TEXT_REPL_DEFAULT.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For an overview of aliases used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction), see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases). For more information about using aliases with the debugger engine API, see [Interacting with the Engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/interacting-with-the-engine).

## See also

[GetNumberTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbertextreplacements)

[GetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-gettextreplacement)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[RemoveTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removetextreplacements)

[SetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-settextreplacement)

[al (List Aliases)](https://learn.microsoft.com/windows-hardware/drivers/debugger/al--list-aliases-)