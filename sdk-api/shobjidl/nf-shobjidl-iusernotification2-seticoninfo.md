# IUserNotification2::SetIconInfo

## Description

Sets the notification area icon associated with specific user information.

## Parameters

### `hIcon` [in]

Type: **HICON**

A handle to the icon.

### `pszToolTip` [in]

Type: **LPCWSTR**

A pointer to a string that contains the tooltip text to display for the specified icon. This value can be **NULL**, although it is not recommended.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IUserNotification2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iusernotification2)

[SetIconInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iusernotification-seticoninfo)