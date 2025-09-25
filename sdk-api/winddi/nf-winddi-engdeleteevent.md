# EngDeleteEvent function

## Description

The **EngDeleteEvent** function deletes the specified event object.

## Parameters

### `pEvent` [in]

Pointer to the event object to be deleted.

## Return value

**EngDeleteEvent** returns **TRUE** if it is successful in deleting the specified event object. It returns **FALSE** if the caller attempts to delete a mapped user event.

## Remarks

A display driver can call **EngDeleteEvent** only with an event object returned from the [EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent) function, and must not call it to delete event objects returned from [EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent).

Before calling **EngDeleteEvent**, the display driver must notify all holders of the specified event object that it is about to become invalid.

## See also

[EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent)

[EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent)