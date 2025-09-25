# IUserNotification2::Show

## Description

Displays the user information in a balloon-style tooltip.

## Parameters

### `pqc` [in, optional]

Type: **[IQueryContinue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iquerycontinue)***

An [IQueryContinue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iquerycontinue) interface pointer, used to determine whether the notification display can continue or should stop (for example, if the user closes the notification). This value can be **NULL**.

### `dwContinuePollInterval` [in]

Type: **DWORD**

The length of time, in milliseconds, to display user information.

### `pSink` [in]

Type: **[IUserNotificationCallback](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iusernotificationcallback)***

A pointer to an [IUserNotificationCallback](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iusernotificationcallback) interface, used to handle mouse click and hover actions on the notification area icon and within the notification itself. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUserNotification2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iusernotification2)

[Show](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iusernotification-show)