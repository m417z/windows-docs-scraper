# EngSetEvent function

## Description

The **EngSetEvent** function sets the specified event object to the signaled state, and returns the event object's previous state.

## Parameters

### `pEvent` [in]

Pointer to the event object that is to be set to the signaled state. This event object was returned by a previous call to [EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent) or [EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent).

## Return value

**EngSetEvent** returns a nonzero value if the event object's previous state was signaled.

## Remarks

Every event object is in either the signaled state or the nonsignaled state. Calling **EngSetEvent** causes the event object to be set to the signaled state.

## See also

[EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent)

[EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent)

[EngWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwaitforsingleobject)