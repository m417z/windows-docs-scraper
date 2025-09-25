# IDebugSymbols3::SetScope

## Description

The **SetScope** method sets the current scope.

## Parameters

### `InstructionOffset` [in]

Specifies the location in the process's virtual address space for the scope's current instruction. This is only used if both *ScopeFrame* and *ScopeContext* are **NULL**; otherwise, it is ignored.

### `ScopeFrame` [in, optional]

Specifies the scope's stack frame. For information about this structure, see [DEBUG_STACK_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_stack_frame).

### `ScopeContext` [in, optional]

Specifies the scope's [thread context](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups). The type of the thread context is the CONTEXT structure for the target's effective processor. The buffer *ScopeContext* must be large enough to hold this structure. If *ScopeContext* is **NULL**, the current [register context](https://learn.microsoft.com/windows-hardware/drivers/debugger/changing-contexts) is used instead.

### `ScopeContextSize` [in]

Specifies the size of the buffer *ScopeContext*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The scope identified by *InstructionOffset*, *ScopeFrame*, and *ScopeContext* is the same as the old scope. |
| **S_FALSE** | The scope has changed. |

## Remarks

If only *InstructionOffset* is provided, the scope can be used to look up symbol names; however, the values of these symbols will not be available.

To set the scope to a previous state, *ScopeContext* must be provided. This is not always necessary (for example, if you only wish to access the symbols and not the [registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers)). To set the scope to a frame on the current stack, [SetScopeFrameByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscopeframebyindex) can be used.

For more information about scopes, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getscope)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[ResetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-resetscope)

[SetScopeFrameByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscopeframebyindex)