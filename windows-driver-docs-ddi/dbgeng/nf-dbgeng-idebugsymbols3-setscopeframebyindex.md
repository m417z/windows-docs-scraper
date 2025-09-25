# IDebugSymbols3::SetScopeFrameByIndex

## Description

The **SetScopeFrameByIndex** method sets the current scope to the scope of one of the frames on the call stack.

## Parameters

### `Index` [in]

Specifies the index of the stack frame from which to set the scope. The index counts the number of frames from the top of the call stack. The frame at the top of the stack, representing the current call, has index zero.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

When an event occurs and the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) breaks into a target, the scope is set to the current function call (the function that was executing when the event occurred). Calling this method with *Index* set to one will change the current scope to the caller of the current function; with *Index* set to two, the scope is changed to the caller's caller, and so on.

For more information about scopes, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[.frame (Set Local Context)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-frame--set-local-context-)

[GetCurrentScopeFrameIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getcurrentscopeframeindex)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscope)

[SetScopeFromStoredEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscopefromstoredevent)