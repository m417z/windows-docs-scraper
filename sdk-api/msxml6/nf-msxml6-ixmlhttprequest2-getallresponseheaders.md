# IXMLHTTPRequest2::GetAllResponseHeaders

## Description

Retrieves the values of all the HTTP response headers.

## Parameters

### `ppwszHeaders` [out]

The returned header information. Free the memory used for this parameter using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) method.

## Return value

Returns **S_OK** on success.

## Remarks

Each header name/value pair is separated by a combination carriage return-line feed.

The returned response header information is only valid after the [OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable) callback method has been called.

#### Examples

```cpp
HRESULT hr = S_OK;
WCHAR *pwszHeaderValue = NULL;
IXMLHTTPRequest2 *pIXMLHTTPRequest2 = NULL;

// Create IXMLHTTPRequest2 object and initialize pIXMLHTTPRequest2.
hr = pIXMLHTTPRequest2->GetAllResponseHeaders(&pwszHeaderValue);
if(SUCCEEDED(hr))
{
  MessageBox(NULL, pwszHeaderValue, L"All Response Headers", MB_OK);
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

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable)