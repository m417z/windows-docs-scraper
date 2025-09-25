# WICProgressNotification enumeration

## Description

Specifies when the progress notification callback should be called.

## Constants

### `WICProgressNotificationBegin:0x10000`

The callback should be called when codec operations begin.

### `WICProgressNotificationEnd:0x20000`

The callback should be called when codec operations end.

### `WICProgressNotificationFrequent:0x40000`

The callback should be called frequently to report status.

### `WICProgressNotificationAll:0xffff0000`

The callback should be called on all available progress notifications.

### `WICPROGRESSNOTIFICATION_FORCE_DWORD:0x7fffffff`

## See also

[RegisterProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapcodecprogressnotification-registerprogressnotification)