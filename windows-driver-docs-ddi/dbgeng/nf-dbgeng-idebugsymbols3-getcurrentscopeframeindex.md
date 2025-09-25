# IDebugSymbols3::GetCurrentScopeFrameIndex

## Description

The **GetCurrentScopeFrameIndex** method returns the index of the current stack frame in the call stack.

## Parameters

### `Index` [out]

Receives the index of the stack frame corresponding to the current scope. The index counts the number of frames from the top of the call stack. The frame at the top of the stack, representing the current call, has index zero.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

If the current scope was set using [SetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscope), *Index* receives the value of the **FrameNumber** member of the DEBUG_STACK_TRACE structure passed to the *ScopeFrame* parameter of **SetScope**.

For more information about scopes, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[.frame (Set Local Context)](https://learn.microsoft.com/windows-hardware/drivers/debugger/-frame--set-local-context-)

[GetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getscope)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetScopeFrameByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscopeframebyindex)