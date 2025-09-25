# IXMLHTTPRequest2::SetProperty

## Description

Sets a property on an outgoing HTTP request.

## Parameters

### `eProperty` [in]

The following values are valid:

| Value | Meaning |
| --- | --- |
| **XHR_PROP_NO_CRED_PROMPT** | Suppresses automatic prompts for user credentials |
| **XHR_PROP_NO_AUTH** | Suppresses authentication that the HTTP stack performs on behalf of the application |
| **XHR_PROP_TIMEOUT** | Sets all timeout values to the value given by *ullValue*, in milliseconds. |
| **XHR_PROP_NO_DEFAULT_HEADERS** | Suppresses adding default headers to the HTTP request. |
| **XHR_PROP_REPORT_REDIRECT_STATUS** | Causes the HTTP stack to call the [OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable) method with an interim redirecting status code. The **OnHeadersAvailable** method will be called again for additional redirects and the final destination status code. |
| **XHR_PROP_NO_CACHE** | Suppresses cache reads and writes for the HTTP request.<br><br>This property is supported by the [IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3) interface. |
| **XHR_PROP_EXTENDED_ERROR** | Causes the HTTP stack to provide HRESULTS with the underlying Win32 error code to the [OnError](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onerror) method in case of failure.<br><br>This property is supported by the [IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3) interface. |
| **XHR_PROP_QUERY_STRING_UTF8** | Causes the query string to be encoded in UTF-8 instead of ACP for the HTTP request.<br><br>This property is supported by the [IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3) interface. |
| **XHR_PROP_IGNORE_CERT_ERRORS** | Suppresses certain certificate errors.<br><br>This property is supported by the [IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3) interface. |

### `ullValue` [in]

Specifies the number of milliseconds that the application waits before timing out.

| Value | Meaning |
| --- | --- |
| **XHR_PROP_NO_CRED_PROMPT** | This parameter can be one of the values from the [XHR_CRED_PROMPT](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_cred_prompt) enumeration type defined in the *Msxml6.h* header file.<br><br>* **XHR_CRED_PROMPT_ALL** if credential prompting should be enabled **(default)**.<br>* **XHR_CRED_PROMPT_NONE** if credential prompting should be disabled.<br>* **XHR_CRED_PROMPT_PROXY** if credential prompting should only be enabled for proxy authentication. |
| **XHR_PROP_NO_AUTH** | This parameter can be one of the values from the [XHR_AUTH](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_cred_prompt) enumeration type defined in the *Msxml6.h* header file.<br><br>* **XHR_AUTH_ALL** if authentication is enabled **(default)**.<br>* **XHR_AUTH_NONE** if authentication is disabled.<br>* **XHR_AUTH_PROXY** if authentication should only be enabled for proxy authentication. |
| **XHR_PROP_TIMEOUT** | The number of milliseconds, up to 0xFFFFFFFF, that the app waits before timing out. |
| **XHR_PROP_NO_DEFAULT_HEADERS** | * FALSE(0x0) to enable adding default headers **(default)**.<br>* TRUE(0x1) to disable adding default headers. |
| **XHR_PROP_REPORT_REDIRECT_STATUS** | * FALSE(0x0) to not report redirect status **(default)**.<br>* TRUE(0x1) to report redirect status. |
| **XHR_PROP_NO_CACHE** | * FALSE(0x0) to enable caching **(default)**.<br>* TRUE(0x1) to disable caching. |
| **XHR_PROP_EXTENDED_ERROR** | * FALSE(0x0) to not provide extended errors **(default)**.<br>* TRUE(0x1) to provide extended errors . |
| **XHR_PROP_QUERY_STRING_UTF8** | * FALSE(0x0) to not encode the query string in UTF-8 **(default)**.<br>* TRUE(0x1) to encode the query string in UTF-8. |
| **XHR_PROP_IGNORE_CERT_ERRORS** | * FALSE(0x0) to not ignore certificate errors **(default)**.<br>* TRUE(0x1) to ignore certificate errors. |

## Return value

Returns **S_OK** on success.

## Remarks

The **SetProperty** method on the [IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) interface is extended on the [IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3) interface with new properties to support new scenarios:

* XHR_PROP_NO_CACHE – Suppresses cache reads and writes for the HTTP request.
* XHR_PROP_EXTENDED_ERROR – Causes the HTTP stack to provide HRESULTS with the underlying Win32 error code to the OnError method in case of failure.
* XHR_PROP_QUERY_STRING_UTF8 – Causes the query string to be encoded in UTF-8 instead of ACP for HTTP request.
* XHR_PROP_IGNORE_CERT_ERRORS – Suppresses certain server certificate errors.

## See also

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3)

[OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable)

[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-open)

[XHR_PROPERTY Enumeration](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_property)