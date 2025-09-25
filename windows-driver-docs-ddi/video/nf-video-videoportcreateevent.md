# VideoPortCreateEvent function

## Description

The **VideoPortCreateEvent** function creates an event object.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `EventFlag` [in]

Specifies the event type and initial event state. This can be an ORed combination of the following flags:

|Flag|Meaning|
|--- |--- |
|INITIAL_EVENT_SIGNALED|Set this flag to indicate the signaled state for the event object. Otherwise, the initial state of the event is nonsignaled.|
|NOTIFICATION_EVENT|Set this flag to create a notification event. If this flag is not set, a synchronization event is created.|

### `Unused` [in]

Is currently ignored by the video port driver and must be set to **NULL**.

### `ppEvent` [out]

Pointer to the memory location at which a pointer to the event object will be returned.

## Return value

**VideoPortCreateEvent** returns NO_ERROR if the event object is successfully created.

## Remarks

When a synchronization event is set to the signaled state, a single thread that was waiting for the signaled state is released (its dispatch state transitions from waiting to ready, standby, or running), and the event is automatically reset to the nonsignaled state.

When a notification event is set to the signaled state, all threads that were waiting for the signaled state are released, and the event remains in the signaled state until it is explicitly reset to the nonsignaled state.

## See also

[VideoPortDeleteEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdeleteevent)