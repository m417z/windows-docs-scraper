# RegisterScaleChangeNotifications function

## Description

Registers a window to receive callbacks when scaling information changes.

**Note** This function is not supported as of Windows 8.1. Use [RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent) instead.

## Parameters

### `displayDevice` [in]

Type: **[DISPLAY_DEVICE_TYPE](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-display_device_type)**

The enum value that indicates which display device to receive notifications about.

### `hwndNotify` [in]

Type: **HWND**

The handle of the window that will receive the notifications.

### `uMsgNotify` [in]

Type: **UINT**

An application-defined message that is passed to the window specified by *hwndNotify* when scaling information changes. Typically, this should be set to [WM_APP](https://learn.microsoft.com/windows/desktop/winmsg/wm-app)+*x*, where *x* is an integer value.

### `pdwCookie` [out]

Type: **DWORD***

Pointer to a value that, when this function returns successfully, receives a registration token. This token is used to revoke notifications by calling [RevokeScaleChangeNotifications](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-revokescalechangenotifications).

## Return value

Type: **STDAPI**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This message specified by *uMsgNotify* is posted to the registered window through [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea). The *wParam* of the message can contain a combination of [SCALE_CHANGE_FLAGS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-scale_change_flags) that describe the change that occurred.

## See also

[GetScaleFactorForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getscalefactorformonitor)

[RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent)

[UnregisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-unregisterscalechangeevent)