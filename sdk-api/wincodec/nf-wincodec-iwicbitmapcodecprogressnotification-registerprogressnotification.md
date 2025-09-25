# IWICBitmapCodecProgressNotification::RegisterProgressNotification

## Description

Registers a progress notification callback function.

## Parameters

### `pfnProgressNotification` [in]

Type: **PFNProgressNotification**

A function pointer to the application defined progress notification callback function. See [ProgressNotificationCallback](https://learn.microsoft.com/windows/desktop/api/wincodec/nc-wincodec-pfnprogressnotification) for the callback signature.

### `pvData` [in]

Type: **LPVOID**

A pointer to component data for the callback method.

### `dwProgressFlags` [in]

Type: **DWORD**

The [WICProgressOperation](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicprogressoperation) and [WICProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicprogressnotification) flags to use for progress notification.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications can only register a single callback. Subsequent registration calls will replace the previously registered callback. To unregister a callback, pass in **NULL** or register a new callback function.

Progress is reported in an increasing order between 0.0 and 1.0.
If *dwProgressFlags* includes **WICProgressNotificationBegin**, the callback is guaranteed to be called with progress 0.0.
If *dwProgressFlags* includes **WICProgressNotificationEnd**, the callback is guaranteed to be called with progress 1.0.

**WICProgressNotificationFrequent** increases the frequency in which the callback is called.
If an operation is expected to take more than 30 seconds, **WICProgressNotificationFrequent** should be added to *dwProgressFlags*.

## See also

[IWICBitmapCodecProgressNotification](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapcodecprogressnotification)

[ProgressNotificationCallback](https://learn.microsoft.com/windows/desktop/api/wincodec/nc-wincodec-pfnprogressnotification)