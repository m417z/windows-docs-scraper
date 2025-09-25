# IUserNotification::Show

## Description

Displays the notification.

## Parameters

### `pqc` [in, optional]

Type: **[IQueryContinue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iquerycontinue)***

An [IQueryContinue](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iquerycontinue) interface pointer, used to determine whether the notification display can continue or should stop (for example, if the user closes the notification). This value can be **NULL**.

### `dwContinuePollInterval` [in]

Type: **DWORD**

The length of time, in milliseconds, to display user information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is equivalent to calling [Show](https://learn.microsoft.com/windows/desktop/api/shobjidl/nf-shobjidl-iusernotification2-show) with *pSink*=**NULL**.