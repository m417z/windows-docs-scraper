# IXMLHTTPRequest2::GetResponseHeader

## Description

Retrieves the value of an HTTP header from the response headers.

## Parameters

### `pwszHeader` [in]

A case-insensitive header name.

### `ppwszValue` [out, optional]

The resulting header information. You should free the memory for this parameter by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

Returns **S_OK** on success.

## Remarks

The results of this method are valid only after [OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable) callback method has been called.

#### Examples

```cpp
HRESULT hr = S_OK;
WCHAR *pwszHeaderValue = NULL;
IXMLHTTPRequest2 *pIXMLHTTPRequest2 = NULL;

// Create XMLHTTPRequest2 object and initialize pIXMLHTTP2Request.
hr = pIXMLHTTPRequest2->GetResponseHeader(L"Server", &pwszHeaderValue);
if(SUCCEEDED(hr))
{
   MessageBox(NULL, pwszHeaderValue, L"Response Header-Server", MB_OK);
}

if (pwszHeaderValue != NULL)
{
   CoTaskMemFree(pwszHeaderValue);
   pwszHeaderValue = NULL;
}

// Release pIXMLHTTPRequest2 when finished with it.

```

## See also

[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)

[GetAllResponseHeaders](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getallresponseheaders)

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable)