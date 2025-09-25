# IDebugSymbols4::SetScopeEx

## Description

Sets the scope as an extended frame structure.

## Parameters

### `InstructionOffset` [in]

The offset of the instruction for the scope.

### `ScopeFrame` [in, optional]

The scope frame to set as a [DEBUG_STACK_FRAME_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_stack_frame_ex) structure.

### `ScopeContext` [in]

A pointer to a scope context.

### `ScopeContextSize` [in]

The size of the scope context.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DEBUG_STACK_FRAME_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_stack_frame_ex)

[IDebugSymbols4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols4)