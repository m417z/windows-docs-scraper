# IDebugControl4::GetStoredEventInformation

## Description

The **GetStoredEventInformation** method retrieves information about an event of interest available in the current target.

## Parameters

### `Type` [out]

Receives the type of the stored event. For a list of possible types, see [DEBUG_EVENT_XXX](https://learn.microsoft.com/previous-versions/ff541478(v=vs.85)).

### `ProcessId` [out]

Receives the process ID of the process in which the event occurred. If this information is not available, DEBUG_ANY_ID will be returned instead.

### `ThreadId` [out]

Receives the thread ID of the thread in which the last event occurred. If this information is not available, DEBUG_ANY_ID will be returned instead.

### `Context` [out, optional]

Receives the [thread context](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups) of the stored event. The type of the thread context is the CONTEXT structure for the target's effective processor at the time of the event. The *Context* buffer must be large enough to hold this structure. If *Context* is **NULL**, this information is not returned.

### `ContextSize` [in]

Specifies the size, in bytes, of the buffer that *Context* specifies.

### `ContextUsed` [out, optional]

Receives the size in bytes of the context. If *ContextUsed* is **NULL**, this information is not returned.

### `ExtraInformation` [out, optional]

Receives extra information about the event. The contents of this extra information depends on the type of the event. If *ExtraInformation* is **NULL**, this information is not returned.

### `ExtraInformationSize` [in]

Specifies the size, in bytes, of the buffer that *ExtraInformation* specifies.

### `ExtraInformationUsed` [out, optional]

Receives the size in bytes of extra information. If *ExtraInformationUsed* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Many targets do not have an event of interest.

If the target is a user-mode minidump file, the dump file generator may store an additional event. Typically, this is the event that provoked the generator to save the dump file.

For more information, see the topic [Event Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-information).

## See also

[GetLastEventInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getlasteventinformation)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)