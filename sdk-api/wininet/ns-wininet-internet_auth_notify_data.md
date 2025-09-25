# INTERNET_AUTH_NOTIFY_DATA structure

## Description

Contains the notification data for an authentication request.

## Members

### `cbStruct`

Size of the structure, in bytes.

### `dwOptions`

### `pfnNotify`

Notification callback to retry
[InternetErrorDlg](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-interneterrordlg).

### `dwContext`

Pointer to a variable that contains an application-defined value used to identify the application context to pass to the notification function.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetErrorDlg](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-interneterrordlg)