# tagWPD_CAPTURE_MODES enumeration

## Description

The **WPD_CAPTURE_MODES** enumeration type describes the capture timing mode of a still image capture.

## Constants

### `WPD_CAPTURE_MODE_UNDEFINED`

The capture mode has not been defined.

### `WPD_CAPTURE_MODE_NORMAL`

No delay or burst mode should be used.

### `WPD_CAPTURE_MODE_BURST`

Specifies that a defined number of images should be captured with a defined interval between them. The number of images to capture and time delay between them are specified by the [WPD_STILL_IMAGE_BURST_NUMBER](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) and [WPD_STILL_IMAGE_BURST_INTERVAL](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) properties.

### `WPD_CAPTURE_MODE_TIMELAPSE`

Image capture should use time lapse photography. The number of images and interval between them are described by the [WPD_STILL_IMAGE_TIMELAPSE_NUMBER](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) and [WPD_STILL_IMAGE_TIMELAPSE_INTERVAL](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) properties.

## Remarks

This enumeration is used by the [WPD_STILL_IMAGE_CAPTURE_MODE](https://learn.microsoft.com/windows/desktop/wpd_sdk/still-image-properties) property.

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))

[WPD Properties and Attributes](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597900(v=vs.85))