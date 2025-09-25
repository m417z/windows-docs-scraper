# IDebugControl4::SetTextReplacementWide

## Description

The **SetTextReplacementWide** method sets the value of a user-named alias.

## Parameters

### `SrcText` [in]

Specifies the name of the user-named alias. The [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) makes a copy of this string. If *SrcText* is the same as the name of an automatic alias, the automatic alias is hidden by the new user-named alias.

### `DstText` [in, optional]

Specifies the value of the user-named alias. The debugger engine makes a copy of this string. If *DstText* is **NULL**, the user-named alias is removed.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Before executing commands or evaluating expressions, the debugger engine will replace the alias specified by *SrcText* with the value of the alias (specified by *DstText*).

If *SrcText* is an asterisk (*****) and *DstText* is **NULL**, all user-named aliases are removed. This is the same behavior as the [RemoveTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removetextreplacements) method.

When an alias is changed by this method, the event callbacks are notified by passing the DEBUG_CES_TEXT_REPLACEMENTS flag to the [IDebugEventCallbacks::ChangeEngineState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changeenginestate) callback method.

For an overview of aliases used by the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction), see [Using Aliases](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-aliases). For more information about using aliases with the debugger engine API, see [Interacting with the Engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/interacting-with-the-engine).

## See also

[GetTextReplacement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-gettextreplacement)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)

[OutputTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-outputtextreplacements)

[RemoveTextReplacements](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-removetextreplacements)

[SetTextMacro](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-settextmacro)

[ad (Delete Alias)](https://learn.microsoft.com/windows-hardware/drivers/debugger/ad--delete-alias-)

[as, aS (Set Alias)](https://learn.microsoft.com/windows-hardware/drivers/debugger/as--as--set-alias-)