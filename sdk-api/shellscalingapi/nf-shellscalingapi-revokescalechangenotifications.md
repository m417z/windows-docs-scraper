# RevokeScaleChangeNotifications function

## Description

Revokes the registration of a window, preventing it from receiving callbacks when scaling information changes.

**Note** This function is not supported as of Windows 8.1. Use [UnregisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-unregisterscalechangeevent) instead.

## Parameters

### `displayDevice` [in]

Type: **[DISPLAY_DEVICE_TYPE](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-display_device_type)**

The enum value that indicates which display device to receive notifications about.

### `dwCookie` [in]

Type: **DWORD**

The registration token returned by a previous call to [RegisterScaleChangeNotifications](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangenotifications).

## Return value

Type: **STDAPI**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetScaleFactorForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getscalefactorformonitor)

[RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent)

[UnregisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-unregisterscalechangeevent)