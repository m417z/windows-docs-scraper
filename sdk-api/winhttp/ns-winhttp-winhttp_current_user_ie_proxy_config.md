## Description

The **WINHTTP_CURRENT_USER_IE_PROXY_CONFIG** structure contains the Internet Explorer proxy configuration information.

## Members

### `fAutoDetect`

If TRUE, indicates that the Internet Explorer proxy configuration for the current user specifies "automatically detect settings".

### `lpszAutoConfigUrl`

Pointer to a null-terminated Unicode string that contains the auto-configuration URL if the Internet Explorer proxy configuration for the current user specifies "Use automatic proxy configuration".

### `lpszProxy`

Pointer to a null-terminated Unicode string that contains the proxy URL if the Internet Explorer proxy configuration for the current user specifies "use a proxy server".

### `lpszProxyBypass`

Pointer to a null-terminated Unicode string that contains the optional proxy by-pass server list.

## See also

[WinHTTP
Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)