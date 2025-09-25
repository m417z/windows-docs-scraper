# IUserNotificationCallback::OnContextMenu

## Description

Called when the user right-clicks (or presses SHIFT+F10) the icon in the notification area. The application should show its context menu in response.

## Parameters

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

When returned by the method, takes a pointer to the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure at the position of the mouse in the screen space where the click occurred.

In the case where user presses SHIFT+F10, the pointer points to the center of the icon in the screen space.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.