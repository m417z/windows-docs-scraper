# IXMLHTTPRequest2Callback::OnHeadersAvailable

## Description

Occurs after an HTTP request has been sent to the server and the server has responded with response headers.

## Parameters

### `pXHR` [in, optional]

The initial HTTP request object that returns the headers.

### `dwStatus` [in]

The status code for the request.

**Note** Possible values for this parameter also include the **HTTP_STATUS_*** values defined by **winhttp.h** for desktop apps.

### `pwszStatus` [in]

The status code for the request appearing in human-readable form as a null-terminated string.

## Return value

Returns **S_OK** on success.

**Note** This callback function must not throw exceptions.

## Remarks

To view an individual response header, call the [GetResponseHeader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getresponseheader) method on the [IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) interface. To view all response headers, call the [GetAllResponseHeaders](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getallresponseheaders) method. To cancel the request, call the Abort method On the pXHR object.

## See also

[GetAllResponseHeaders Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getallresponseheaders)

[GetResponseHeader Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-getresponseheader)

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)

[IXMLHTTPRequest2Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback)

[OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable)