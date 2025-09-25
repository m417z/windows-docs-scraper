## Description

Retrieves extended proxy settings.

## Parameters

### `hResolver`

Type: \_In\_ **[HINTERNET](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The WinHTTP resolver handle returned by the [WinHttpCreateProxyResolver](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpcreateproxyresolver) function.

### `ProxySettingsType`

Type: \_In\_ **[WINHTTP_PROXY_SETTINGS_TYPE](https://learn.microsoft.com/windows/win32/api/winhttp/ne-winhttp-winhttp_proxy_settings_type)**

A proxy settings type.

### `pProxySettingsParam`

Type: \_In\_opt\_ **[PWINHTTP_PROXY_SETTINGS_PARAM](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_settings_param)**

An optional pointer to a [WINHTTP_PROXY_SETTINGS_PARAM](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_settings_param).

### `pContext`

Type: \_In\_opt\_ **[DWORD_PTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

An optional pointer to a **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)** containing context data that will be passed to the completion callback function.

## Return value

A **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)** containing a status code indicating the result of the operation. The following codes can be returned (the list is not exhaustive).

|Code|Description|
|-|-|
|ERROR_IO_PENDING|The operation is continuing asynchronously.|

## Remarks

## See also