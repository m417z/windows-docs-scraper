# _TARGET_DEVICE_CUSTOM_NOTIFICATION structure

## Description

The **TARGET_DEVICE_CUSTOM_NOTIFICATION** structure describes a custom device event.

## Members

### `Version`

Specifies the version of the data structure, currently 1.

### `Size`

Specifies the size of the structure, in bytes, including the first three standard members plus the event-specific data.

### `Event`

Specifies a GUID identifying the event. GUIDs for custom event notification are defined by the components that use this mechanism.

### `FileObject`

Pointer to a file object for the device.

### `NameBufferOffset`

Specifies the offset, in bytes, from beginning of **CustomDataBuffer** where text begins. A value of -1 indicates that there is no text.

### `CustomDataBuffer`

A variable-length buffer, optionally containing binary data at the start of the buffer, followed by an optional text buffer (word-aligned).

## Remarks

Kernel-mode components use this structure for custom event notification: to signal a custom event (**IoReportTargetDeviceChange**[**Asynchronous**]) and when handling a custom event (in a notification callback routine).

This structure accommodates both a variable-length binary data buffer and a variable-length Unicode text buffer. The *NameBufferOffset* must indicate where the text buffer begins, so the data can be delivered in the appropriate format (ANSI or Unicode) to user-mode applications that registered for handle-based notification with **RegisterDeviceNotification**. See also [**RegisterDeviceNotification**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerdevicenotificationa).

## See also

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[IoReportTargetDeviceChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreporttargetdevicechange)

[IoReportTargetDeviceChangeAsynchronous](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreporttargetdevicechangeasynchronous)

[**RegisterDeviceNotification**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerdevicenotificationa)