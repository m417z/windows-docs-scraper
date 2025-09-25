# VideoPortSetEvent function

## Description

The **VideoPortSetEvent** function sets an event object to the signaled state if it was not already in that state, and returns the event object's previous state.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pEvent` [in]

Pointer to the event object whose state is to be set.

## Return value

**VideoPortSetEvent** returns a nonzero value if the event object was previously in the signaled state.

## See also

[VideoPortClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportclearevent)