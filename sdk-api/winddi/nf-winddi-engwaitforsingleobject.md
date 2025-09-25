# EngWaitForSingleObject function

## Description

The **EngWaitForSingleObject** function puts the current thread of the display driver into a wait state until the specified event object is set to the signaled state, or until the wait times out.

## Parameters

### `pEvent` [in]

Pointer to an initialized event object. This event object handle was obtained in a previous call to [EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent).

### `pTimeOut` [in]

(*Optional*) Pointer to a time-out value that specifies the absolute or relative time at which the wait is to be completed. A negative value specifies an interval relative to the current time. The value should be expressed in units of 100 nanoseconds. Absolute expiration times track any changes in the system time; relative expiration times are not affected by system time changes. If *pTimeOut* is **NULL**, the calling thread remains in a waiting state until the event object is signaled.

## Return value

**EngWaitForSingleObject** returns **TRUE** upon success, which includes the occurrence of a time-out. Otherwise, it returns **FALSE**. A return value of **FALSE** indicates that one of the parameters is invalid.

## Remarks

**EngWaitForSingleObject** causes a display driver thread to be put into a wait state. The display driver thread stays in the wait state until either the event object is set to the signaled state or until the wait times out. If no time-out value is supplied, the display driver thread remains in the wait state until the event object is set to the signaled state.

A synchronization event is automatically reset to the nonsignaled state when the wait is satisfied. Thus, only one wait will be satisfied per call to [EngSetEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetevent) or [VideoPortSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/video/nf-video-videoportsetevent). In contrast, a notification event will not be automatically reset.

A time-out value of zero allows the driver to test the wait condition and to conditionally perform any side effects provided that the wait can be immediately satisfied.

The display driver can synchronize drawing operations between itself and the video miniport driver by calling **EngWaitForSingleObject** with an event object, and waiting until the miniport driver sets the event object to the signaled state.

The driver cannot call **EngWaitForSingleObject** on events returned from [EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent).

## See also

[EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent)

[EngSetEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engsetevent)

[VideoPortSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/video/nf-video-videoportsetevent)