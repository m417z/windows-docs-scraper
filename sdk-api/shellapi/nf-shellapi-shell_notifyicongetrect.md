# Shell_NotifyIconGetRect function

## Description

Gets the screen coordinates of the bounding rectangle of a notification icon.

## Parameters

### `identifier` [in]

Type: **const [NOTIFYICONIDENTIFIER](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyiconidentifier)***

Pointer to a [NOTIFYICONIDENTIFIER](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyiconidentifier) structure that identifies the icon.

### `iconLocation` [out]

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that, when this function returns successfully, receives the coordinates of the icon.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Notifications and the Notification Area](https://learn.microsoft.com/windows/desktop/shell/notification-area)