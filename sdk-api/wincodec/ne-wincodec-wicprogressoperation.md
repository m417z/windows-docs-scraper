# WICProgressOperation enumeration

## Description

Specifies the progress operations to receive notifications for.

## Constants

### `WICProgressOperationCopyPixels:0x1`

Receive copy pixel operation.

### `WICProgressOperationWritePixels:0x2`

Receive write pixel operation.

### `WICProgressOperationAll:0xffff`

Receive all progress operations available.

### `WICPROGRESSOPERATION_FORCE_DWORD:0x7fffffff`

## See also

[RegisterProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapcodecprogressnotification-registerprogressnotification)