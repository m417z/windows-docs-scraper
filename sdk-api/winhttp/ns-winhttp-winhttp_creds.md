# WINHTTP_CREDS structure

## Description

The **WINHTTP_CREDS** structure contains user credential information used for server and proxy authentication.

**Note** This structure has been deprecated. Instead, the use of the [WINHTTP_CREDS_EX](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_creds_ex) structure is recommended.

## Members

### `lpszUserName`

Pointer to a buffer that contains username.

### `lpszPassword`

Pointer to a buffer that contains password.

### `lpszRealm`

Pointer to a buffer that contains realm.

### `dwAuthScheme`

A flag that contains the authentication scheme, as one of the following values.

| Value | Meaning |
| --- | --- |
| **WINHTTP_AUTH_SCHEME_BASIC** | Use basic authentication. |
| **WINHTTP_AUTH_SCHEME_NTLM** | Use NTLM authentication. |
| **INHTTP_AUTH_SCHEME_DIGEST** | Use digest authentication. |
| **WINHTTP_AUTH_SCHEME_NEGOTIATE** | Select between NTLM and Kerberos authentication. |

### `lpszHostName`

 Pointer to a buffer that contains hostname.

### `dwPort`

The server connection port.

## Remarks

This structure is used with options **WINHTTP_OPTION_GLOBAL_SERVER_CREDS** and **WINHTTP_OPTION_GLOBAL_PROXY_CREDS**
[option flags](https://learn.microsoft.com/windows/desktop/WinHttp/option-flags). These options require the registry key **HKLM\Software\Microsoft\Windows\CurrentVersion\Internet Settings!ShareCredsWithWinHttp**. This registry key is not present by default.

When it is set, WinINet will send credentials down to WinHTTP. Whenever WinHttp gets an authentication challenge and if there are no credentials set on the current handle, it will use the credentials provided by WinINet. In order to share server credentials in addition to proxy credentials, users needs to set the **WINHTTP_OPTION_USE_GLOBAL_SERVER_CREDENTIALS** option flag.

## See also

[WINHTTP_CREDS_EX](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_creds_ex)