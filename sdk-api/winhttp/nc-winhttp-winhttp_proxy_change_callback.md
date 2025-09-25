## Description

Represents an application-defined proxy change callback function.

## Parameters

### `ullFlags`

Type: \_In\_ **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The flag passed to the [WinHttpRegisterProxyChangeNotification](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpregisterproxychangenotification) function (for example, **WINHTTP_PROXY_NOTIFY_CHANGE**).

### `pvContext`

Type: \_In\_ **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The context object pointer passed to the [WinHttpRegisterProxyChangeNotification](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpregisterproxychangenotification) function.

## Remarks

## See also