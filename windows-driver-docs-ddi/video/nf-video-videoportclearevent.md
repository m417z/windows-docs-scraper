# VideoPortClearEvent function

## Description

The **VideoPortClearEvent** function sets a given event object to the nonsignaled state.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pEvent` [in]

Pointer to the event object.

## Return value

None

## Remarks

To set the state of an event object to the signaled state, use [VideoPortSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsetevent).

## See also

[VideoPortSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportsetevent)