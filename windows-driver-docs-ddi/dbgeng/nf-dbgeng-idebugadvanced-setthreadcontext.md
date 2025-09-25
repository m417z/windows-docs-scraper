# IDebugAdvanced::SetThreadContext

## Description

The **SetThreadContext** method sets the current [thread context](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## Parameters

### `Context` [in]

Specifies the thread context. The type of the thread context is the CONTEXT structure for the target's effective processor. The buffer *Context* must be large enough to hold this structure.

### `ContextSize` [in]

Specifies the size of the buffer *Context*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about the thread context, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

**Note** The CONTEXT structure varies with operating system and platform. Care should be taken when using the CONTEXT structure.

## See also

[GetThreadContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-getthreadcontext)

[IDebugAdvanced](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced)

[IDebugAdvanced2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced2)

[IDebugAdvanced3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced3)

[SetScope](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setscope)