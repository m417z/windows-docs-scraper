# XHR_COOKIE structure

## Description

Defines a cookie that you can add to the HTTP cookie jar by calling the [SetCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setcookie) method or retrieve from the HTTP cookie jar by calling the [GetCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getcookie) method.

## Members

### `pwszUrl`

A null-terminated string that specifies the URL in the cookie.

### `pwszName`

A null-terminated string that specifies the name in the cookie.

### `pwszValue`

A null-terminated string that specifies the value in the cookie.

### `pwszP3PPolicy`

A null-terminated string that specifies the user policy in the cookie.

### `ftExpires`

A null-terminated string that specifies the date and time at which the cookie expires.

### `dwFlags`

A set of bit flags that specifies properties of the cookie.

This member can be one of the values from the **XHR_COOKIE_FLAG** enumeration type defined in the *Msxml6.h* header file.

| Value | Meaning |
| --- | --- |
| **XHR_COOKIE_IS_SECURE**<br><br>0x1 |  |
| **XHR_COOKIE_IS_SESSION**<br><br>0x2 | The cookie is a session cookie and not a persistent cookie. |
| **XHR_COOKIE_THIRD_PARTY**<br><br>0x10 | Indicates that the cookie being set is a third-party cookie. |
| **XHR_COOKIE_PROMPT_REQUIRED**<br><br>0x20 |  |
| **XHR_COOKIE_EVALUATE_P3P**<br><br>0x40 | If this flag is set, the **pwszP3PPolicy** member points to a Platform-for-Privacy-Protection (P3P) header for the cookie in question. |
| **XHR_COOKIE_APPLY_P3P**<br><br>0x80 |  |
| **XHR_COOKIE_APPLY_P3P**<br><br>0x100 |  |
| **XHR_COOKIE_IS_RESTRICTED**<br><br>0x200 | Indicates that the cookie being set is associated with an untrusted site. |
| **XHR_COOKIE_IE6**<br><br>0x400 |  |
| **XHR_COOKIE_IS_LEGACY**<br><br>0x800 |  |
| **XHR_COOKIE_NON_SCRIPT**<br><br>0x1000 |  |
| **XHR_COOKIE_HTTPONLY**<br><br>0x2000 | Enables the retrieval of cookies that are marked as "HTTPOnly". <br><br>Do not use this flag if you expose a scriptable interface, because this has security implications. If you expose a scriptable interface, you can become an attack vector for cross-site scripting attacks. It is imperative that you use this flag only if they can guarantee that you will never permit third-party code to set a cookie using this flag by way of an extensibility mechanism you provide. |

## See also

[IXMLHTTPRequest2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[SetCookie Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setcookie)

[SetProperty Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty)