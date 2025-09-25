# IUserNotificationCallback::OnBalloonUserClick

## Description

Called when the user clicks the balloon. The application may respond with an action that is suitable for the balloon being clicked.

## Parameters

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

Takes a pointer to the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure which, upon method return, points to the position of the mouse in screen space where the mouse click occurred.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.