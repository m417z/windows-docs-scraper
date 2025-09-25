# IDebugSymbols3::SetScopeFromStoredEvent

## Description

The **SetScopeFromStoredEvent** method sets the current scope to the scope of the stored event.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

Currently only user-mode [Minidumps](https://learn.microsoft.com/windows-hardware/drivers/debugger/user-mode-dump-files#minidumps) can contain a stored event.

The new scope is printed to the debugger console.

For more information about scopes, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[.ecxr (Display Exception Context Record)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-ecxr--display-exception-context-record-)

[GetStoredEventInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getstoredeventinformation)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscope)

[SetScopeFrameByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscopeframebyindex)