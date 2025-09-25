# VideoPortDeleteEvent function

## Description

The **VideoPortDeleteEvent** function deletes the specified event object.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `pEvent` [in]

Pointer to the event object to be deleted.

## Return value

**VideoPortDeleteEvent** returns NO_ERROR if the event object is successfully deleted.

## Remarks

This function should not be used to delete a mapped user event. To delete a mapped user event, use [EngUnmapEvent](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engunmapevent).

## See also

[EngUnmapEvent](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-engunmapevent)

[VideoPortCreateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcreateevent)