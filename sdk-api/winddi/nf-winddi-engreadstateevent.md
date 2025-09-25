# EngReadStateEvent function

## Description

The **EngReadStateEvent** function returns the current state of the specified event object: signaled or nonsignaled.

## Parameters

### `pEvent` [in]

Pointer to the event object returned by a previous call to [EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent) or [EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent).

## Return value

**EngReadStateEvent** returns a nonzero value if the event object is currently set to the signaled state. If the event object is set to the nonsignaled state, this function returns zero.

## See also

[EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent)

[EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent)