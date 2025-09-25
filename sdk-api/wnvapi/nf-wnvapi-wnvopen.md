# WnvOpen function

## Description

Provides a handle to the Windows Network Virtualization (WNV) driver object to be used to request and receive WNV notifications.

## Return value

Type: **HANDLE**

If the function succeeds, it returns the handle to the WNV driver object. If the function fails, it returns **NULL**.

## Remarks

This handle is used for multiple invocations of the [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function. When you have finished using the handle, close it by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.