# IDebugSymbols3::GetScope

## Description

The **GetScope** method returns information about the current scope.

## Parameters

### `InstructionOffset` [out, optional]

Receives the location in the process's virtual address space of the current scope's current instruction.

### `ScopeFrame` [out, optional]

Receives the [DEBUG_STACK_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_stack_frame) structure representing the current scope's stack frame.

### `ScopeContext` [out, optional]

Receives the current scope's [thread context](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups). The type of the thread context is the CONTEXT structure for the target's effective processor. The buffer *ScopeContext* must be large enough to hold this structure.

### `ScopeContextSize` [in]

Specifies the size of the buffer *ScopeContext*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The size of the buffer *ScopeContext* was not large enough to hold the scope's context. |

## Remarks

For more information about scopes, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[IDebugControl::GetEffectiveProcessorType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-geteffectiveprocessortype)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[ResetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-resetscope)

[SetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscope)