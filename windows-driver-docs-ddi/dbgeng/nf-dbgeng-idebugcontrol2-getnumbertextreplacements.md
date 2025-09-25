# IDebugControl2::GetNumberTextReplacements

## Description

The **GetNumberTextReplacements** method returns the number of currently defined user-named and automatic aliases.

## Parameters

### `NumRepl` [out]

Receives the total number of user-named and automatic aliases.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For an overview of aliases used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction), see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases). For more information about using aliases with the debugger engine API, see [Interacting with the Engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/interacting-with-the-engine).

## See also

[GetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-gettextreplacement)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OutputTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputtextreplacements)

[RemoveTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removetextreplacements)

[SetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-settextreplacement)