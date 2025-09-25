# WinHttpSetOption function

## Description

The **WinHttpSetOption** function sets an Internet option.

## Parameters

### `hInternet` [in]

The [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle on which to set data. Be aware that this can be either a Session handle or a Request handle, depending on what option is being set. For more information about how to determine which handle is appropriate to use in setting a particular option, see the [Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags).

### `dwOption` [in]

An unsigned long integer value that contains the Internet option to set. This can be one of the
[Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags) values.

### `lpBuffer` [in]

A pointer to a buffer that contains the option setting.

### `dwBufferLength` [in]

Unsigned long integer value that contains the length of the
*lpBuffer* buffer. The length of the buffer is specified in characters for the following options; for all other options, the length is specified in bytes.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Among the error codes returned are the following:

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_OPTION** | A request to [WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) or [WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) specified an invalid option value. |
| **ERROR_INVALID_PARAMETER** | A parameter is not valid.<br><br>This value will be returned if **WINHTTP_OPTION_WEB_SOCKET_KEEPALIVE_INTERVAL** is set to a value lower than 15000. |
| **ERROR_WINHTTP_OPTION_NOT_SETTABLE** | The requested option cannot be set, only queried. |
| **ERROR_INVALID_PARAMETER** | A parameter is not valid.<br><br>This value will be returned if **WINHTTP_OPTION_WEB_SOCKET_KEEPALIVE_INTERVAL** is set to a value lower than 15000. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

Credentials passed to **WinHttpSetOption** could be unexpectedly sent in plaintext. It is strongly recommended that you use [WinHttpQueryAuthSchemes](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryauthschemes) and [WinHttpSetCredentials](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetcredentials) instead of **WinHttpSetOption** for setting credentials.

**Note** When using Passport authentication, however, a WinHTTP application responding to a 407 status code must use **WinHttpSetOption** to provide proxy credentials rather than [WinHttpSetCredentials](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetcredentials). This is only true when using Passport authentication; in all other circumstances, use **WinHttpSetCredentials**.

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the error ERROR_INVALID_PARAMETER if an option flag is specified that cannot be set.

For more information and code examples that show the use of **WinHttpSetOption**, see [Authentication in WinHTTP](https://learn.microsoft.com/windows/desktop/WinHttp/authentication-in-winhttp).

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

## See also

[Authentication in WinHTTP](https://learn.microsoft.com/windows/desktop/WinHttp/authentication-in-winhttp)

[Option Flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption)