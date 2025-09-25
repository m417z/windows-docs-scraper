# IXMLHTTPRequest2::GetCookie

## Description

Gets a cookie associated with the specified URL from the HTTP cookie jar.

## Parameters

### `pwszUrl`

A null-terminated string that specifies the URL in the cookie.

### `pwszName`

A null-terminated string that specifies the name in the cookie.

### `dwFlags`

A set of bit flags that specifies how this method retrieves the cookies. This parameter can be a set values from the [XHR_COOKIE_FLAG](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_cookie_flag) enumeration type defined in the *Msxml6.h* header file.

### `pcCookies`

A count of cookies pointed to by the *ppCookies* if the call is successful.

### `ppCookies` [out]

A pointer to the cookies associated with the specified *pwszUrl* and *pwszName*.

## Return value

Returns **S_OK** on success; **E_FAIL** indicates an error.

## See also

[CoTaskMemFree Function](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[SetCookie Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setcookie)

[XHR_COOKIE Structure](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cookie)

[XHR_COOKIE_FLAG](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_cookie_flag)