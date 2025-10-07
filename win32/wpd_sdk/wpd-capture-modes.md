# WPD\_CAPTURE\_MODES enumeration

The **WPD\_CAPTURE\_MODES** enumeration type describes the capture timing mode of a still image capture.

## Constants

**WPD\_CAPTURE\_MODE\_UNDEFINED**

The capture mode has not been defined.

**WPD\_CAPTURE\_MODE\_NORMAL**

No delay or burst mode should be used.

**WPD\_CAPTURE\_MODE\_BURST**

Specifies that a defined number of images should be captured with a defined interval between them. The number of images to capture and time delay between them are specified by the [WPD\_STILL\_IMAGE\_BURST\_NUMBER](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) and [WPD\_STILL\_IMAGE\_BURST\_INTERVAL](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) properties.

**WPD\_CAPTURE\_MODE\_TIMELAPSE**

Image capture should use time lapse photography. The number of images and interval between them are described by the [WPD\_STILL\_IMAGE\_TIMELAPSE\_NUMBER](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) and [WPD\_STILL\_IMAGE\_TIMELAPSE\_INTERVAL](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) properties.

## Remarks

This enumeration is used by the [WPD\_STILL\_IMAGE\_CAPTURE\_MODE](https://learn.microsoft.com/windows/win32/wpd_sdk/still-image-properties) property.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**WPD Properties and Attributes**](https://learn.microsoft.com/windows/win32/wpd_sdk/properties-and-attributes)

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)

