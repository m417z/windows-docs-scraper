# IDebugControl2::RemoveTextReplacements

## Description

The **RemoveTextReplacements** method removes all user-named aliases.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

For an overview of aliases used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction), see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases). For more information about using aliases with the debugger engine API, see [Interacting with the Engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/interacting-with-the-engine).

## See also

[GetNumberTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumbertextreplacements)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[OutputTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputtextreplacements)

[SetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-settextreplacement)

[ad (Delete Alias)](https://learn.microsoft.com/windows-hardware/drivers/debugger/ad--delete-alias-)