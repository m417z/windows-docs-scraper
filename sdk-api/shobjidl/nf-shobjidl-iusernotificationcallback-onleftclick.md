# IUserNotificationCallback::OnLeftClick

## Description

Called when the user clicks the icon in the notification area. The applications may launch some customary UI in response.

## Parameters

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

Takes a pointer to the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure which, when the method returns, points to the position of the mouse in the screen space where the mouse click occurred.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.