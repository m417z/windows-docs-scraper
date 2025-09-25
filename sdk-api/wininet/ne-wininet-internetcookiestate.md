# InternetCookieState enumeration

## Description

The **InternetCookieState** enumeration defines the state of the cookie.

## Constants

### `COOKIE_STATE_UNKNOWN:0x0`

Reserved.

### `COOKIE_STATE_ACCEPT:0x1`

The cookies are accepted.

### `COOKIE_STATE_PROMPT:0x2`

The user is prompted to accept or deny the cookie.

### `COOKIE_STATE_LEASH:0x3`

Cookies are accepted only in the first-party context.

### `COOKIE_STATE_DOWNGRADE:0x4`

Cookies are accepted and become session cookies.

### `COOKIE_STATE_REJECT:0x5`

The cookies are rejected.

### `COOKIE_STATE_MAX`

Same as **COOKIE_STATE_REJECT**.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetEnumPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetenumpersitecookiedecisiona)

[InternetGetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetpersitecookiedecisiona)

[InternetSetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetpersitecookiedecisiona)