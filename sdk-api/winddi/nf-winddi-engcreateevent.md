# EngCreateEvent function

## Description

The **EngCreateEvent** function creates a synchronization event object that can be used to synchronize hardware access between a display driver and the video miniport driver.

## Parameters

### `ppEvent` [out]

Pointer to a location in which a valid event object is returned.

## Return value

**EngCreateEvent** returns **TRUE** if it is successful in creating an event object. Otherwise, it returns **FALSE**.

## Remarks

**EngCreateEvent** creates a synchronization event object, which is initialized to the nonsignaled state.

## See also

[EngDeleteEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeleteevent)

[EngSetEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetevent)

[EngWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engwaitforsingleobject)