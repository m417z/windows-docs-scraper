# XHR_COOKIE_FLAG enumeration

## Description

Defines a set of flags that you can assign to a cookie in the HTTP cookie jar by calling the [SetCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setcookie) method or query from the HTTP cookie jar by calling the [GetCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getcookie) method.

## Constants

### `XHR_COOKIE_IS_SECURE:0x1`

The cookie is secure.

When this flag is set, the client is only to return the cookie in subsequent requests if those requests use HTTPS.

### `XHR_COOKIE_IS_SESSION:0x2`

The cookie is only usable in the current HTTP session and is not persisted or saved.

### `XHR_COOKIE_THIRD_PARTY:0x10`

The cookie being set is a third-party cookie.

### `XHR_COOKIE_PROMPT_REQUIRED:0x20`

A prompt to the user is required to accept the cookie from the server.

### `XHR_COOKIE_EVALUATE_P3P:0x40`

The cookie has a Platform-for-Privacy-Protection (P3P) header.

### `XHR_COOKIE_APPLY_P3P:0x80`

A cookie with a Platform-for-Privacy-Protection (P3P) header has been applied.

### `XHR_COOKIE_P3P_ENABLED:0x100`

A cookie with a Platform-for-Privacy-Protection (P3P) header has been enabled.

### `XHR_COOKIE_IS_RESTRICTED:0x200`

The cookie being set is associated with an untrusted site.

### `XHR_COOKIE_IE6:0x400`

### `XHR_COOKIE_IS_LEGACY:0x800`

### `XHR_COOKIE_NON_SCRIPT:0x1000`

Does not allow a script or other active content to access this cookie.

### `XHR_COOKIE_HTTPONLY:0x2000`

Enables the retrieval of cookies that are marked as "HTTPOnly".

Do not use this flag if you expose a scriptable interface, because this has security implications. If you expose a scriptable interface, you can become an attack vector for cross-site scripting attacks. It is imperative that you use this flag only if they can guarantee that you will never permit third-party code to set a cookie using this flag by way of an extensibility mechanism you provide.

## See also

[GetCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getcookie)

[SetCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setcookie)

[XHR_COOKIE](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cookie)