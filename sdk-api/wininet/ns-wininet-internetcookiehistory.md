# InternetCookieHistory structure

## Description

The **InternetCookieHistory** structure contains the cookie history.

## Members

### `fAccepted`

If true, the cookie was accepted.

### `fLeashed`

If true, the cookie was leashed.

### `fDowngraded`

If true, the cookie was downgraded.

### `fRejected`

If true, the cookie was rejected.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).