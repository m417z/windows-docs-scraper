# DlSetTrappedEmulatorPorts function

## Description

Dynamically change the list of I/O ports that are trapped when a video display monitor runs in full-screen mode on an x86-based machine.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `NumAccessRanges`

Specifies the number of elements in the *AccessRange* array.

### `AccessRange`

Pointer to an array of [VIDEO_ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_access_range) elements.

## Return value

This function returns VP_STATUS.

## Remarks

## See also