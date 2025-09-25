## Description

Registers a callback function that WinHTTP calls when the effective proxy settings change.

## Parameters

### `ullFlags`

Type: \_In\_ **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The flag to pass to the callback (for example, **WINHTTP_PROXY_NOTIFY_CHANGE**).

### `pfnCallback`

Type: \_In\_ **[WINHTTP_PROXY_CHANGE_CALLBACK](https://learn.microsoft.com/windows/win32/api/winhttp/nc-winhttp-winhttp_proxy_change_callback)**

A pointer to the callback function that should be called when the effective proxy settings change.

### `pvContext`

Type: \_In\_ **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A pointer to a context object to pass to the callback.

### `hRegistration`

Type: \_Out\_ **WINHTTP_PROXY_CHANGE_REGISTRATION_HANDLE\***

A handle that identifies the registration of the callback function. To unregister, pass this value to [WinHttpUnregisterProxyChangeNotification](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpunregisterproxychangenotification). **WINHTTP_PROXY_CHANGE_REGISTRATION_HANDLE** is equivalent to [PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types).

## Return value

A **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)** containing a status code indicating the result of the operation. The following codes can be returned (the list is not exhaustive).

|Code|Description|
|-|-|
|ERROR_SUCCESS|The operation succeeded.|

## Remarks

## See also