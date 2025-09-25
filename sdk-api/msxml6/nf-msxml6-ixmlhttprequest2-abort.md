# IXMLHTTPRequest2::Abort

## Description

Cancels the current HTTP request.

## Return value

Returns **S_OK** on success.

## Remarks

After a request is aborted, the object representing the request is no longer valid.

This method is not guarantee to cancel a request. The app must still wait for to receive the **OnError** callback method that indicates the request was successfully aborted or the **OnResponseReceived** callback method that indicates the request was completed before the abort can be processed.

## See also

[IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2)