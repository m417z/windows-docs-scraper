# WinHttpSetCredentials function

## Description

The **WinHttpSetCredentials** function passes the required authorization credentials to the server.

## Parameters

### `hRequest` [in]

Valid
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) handle returned by
[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest).

### `AuthTargets` [in]

An unsigned integer that specifies a flag that contains the authentication target. Can be one of the values in the following table.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTH_TARGET_SERVER** | Credentials are passed to a server. |
| **WINHTTP_AUTH_TARGET_PROXY** | Credentials are passed to a proxy. |

### `AuthScheme` [in]

An unsigned integer that specifies a flag that contains the authentication scheme. Must be one of the supported authentication schemes returned from
[WinHttpQueryAuthSchemes](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryauthschemes). The following table identifies the possible values.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTH_SCHEME_BASIC** | Use basic authentication. |
| **WINHTTP_AUTH_SCHEME_NTLM** | Use NTLM authentication. |
| **WINHTTP_AUTH_SCHEME_PASSPORT** | Use passport authentication. |
| **WINHTTP_AUTH_SCHEME_DIGEST** | Use digest authentication. |
| **WINHTTP_AUTH_SCHEME_NEGOTIATE** | Selects between NTLM and Kerberos authentication. |

### `pwszUserName` [in]

Pointer to a string that contains a valid user name.

### `pwszPassword` [in]

Pointer to a string that contains a valid password. The password can be blank.

### `pAuthParams` [in]

This parameter is reserved and must be **NULL**.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following table identifies the error codes returned.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be carried out because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation (Windows error code). |

## Remarks

Even when WinHTTP is used in asynchronous mode (that is, when **WINHTTP_FLAG_ASYNC** has been set in [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)), this function operates synchronously. The return value indicates success or failure. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The credentials set by **WinHttpSetCredentials** are only used for a single request; WinHTTP does not cache these credentials for use in subsequent requests. As a result, applications must be written so that they can respond to multiple challenges. If an authenticated connection is re-used, subsequent requests cannot be challenged, but your code should be able to respond to a challenge at any point.

For sample code that illustrates the use of **WinHttpSetCredentials**, see [Authentication in WinHTTP](https://learn.microsoft.com/windows/desktop/WinHttp/authentication-in-winhttp).

**Note** When using Passport authentication and responding to a 407 status code, a WinHTTP application must use [WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) to provide proxy credentials rather than **WinHttpSetCredentials**. This is only true when using Passport authentication; in all other circumstances, use **WinHttpSetCredentials**, because **WinHttpSetOption** is less secure.

**Note** For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page) section of the WinHttp start page.

## See also

[About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/about-winhttp)

[Authentication in WinHTTP](https://learn.microsoft.com/windows/desktop/WinHttp/authentication-in-winhttp)

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)

[WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle)

[WinHttpConnect](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpconnect)

[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen)

[WinHttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopenrequest)

[WinHttpQueryAuthSchemes](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryauthschemes)