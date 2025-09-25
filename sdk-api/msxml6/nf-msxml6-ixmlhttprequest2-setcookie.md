# IXMLHTTPRequest2::SetCookie

## Description

Sets a cookie associated with the specified URL in the HTTP cookie jar.

## Parameters

### `pCookie`

A pointer to an [XHR_COOKIE](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cookie) structure that specifies the cookie and properties of the cookie to be associated with the specified URL.

### `pdwCookieState`

A pointer to a value that indicates the cookie state if the call completes successfully.

This parameter can be one of the values from the [XHR_COOKIE_STATE](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_cookie_state) enumeration type defined in the *Msxml6.h* header file.

| Value | Meaning |
| --- | --- |
| **XHR_COOKIE_STATE_UNKNOWN**<br><br>0 | Reserved. |
| **XHR_COOKIE_STATE_ACCEPT**<br><br>1 | The cookie was accepted. |
| **XHR_COOKIE_STATE_PROMPT**<br><br>2 | The user is prompted to accept or refuse the cookie. |
| **XHR_COOKIE_STATE_LEASH**<br><br>3 | The cookie is accepted only in the first-party context. |
| **XHR_COOKIE_STATE_DOWNGRADE**<br><br>4 | The cookie was accepted and became session cookie. |
| **XHR_COOKIE_STATE_REJECT**<br><br>5 | The cookie was rejected. |

## Return value

Returns **S_OK** on success.

## Remarks

The **SetCookie** method has different behavior for Windows Store apps and Windows desktop applications.

When used in a Windows Store app, the **SetCookie** method by default sets the cookie as a persistent cookie in the Windows Store app. When the **dwFlags** member of the [XHR_COOKIE](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cookie) has the **XHR_COOKIE_IS_SESSION** flag set, then the cookie is set only for the current session of the app.

When used in a Windows desktop application, the **SetCookie** method by default sets a persistent cookie that is system wide and shared by all Windows desktop applications. When the **dwFlags** member of the [XHR_COOKIE](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cookie) has the **XHR_COOKIE_IS_SESSION** flag set, then the cookie is set only for the current session of the Windows desktop application.

## See also

[GetCookie Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getcookie)

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[XHR_COOKIE Structure](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cookie)

[XHR_COOKIE_STATE](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_cookie_state)