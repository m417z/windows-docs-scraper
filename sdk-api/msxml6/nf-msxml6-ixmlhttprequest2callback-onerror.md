# IXMLHTTPRequest2Callback::OnError

## Description

Occurs when an error is encountered or the request has been aborted.

## Parameters

### `pXHR` [in, optional]

The initial HTTP request.

### `hrError`

A code representing the error that occurred on the HTTP request.

## Return value

Returns **S_OK** on success.

**Note** This callback function must not throw exceptions.

## Remarks

Unless the request completes successfully, indicated by [OnResponseReceived](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onresponsereceived), the call to **OnError** is the final callback. The client should perform any required cleanup including releasing references to the [IXMLHTTPRequest2](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2) object.

## See also

[ISequentialStream Interface](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-isequentialstream)

[IXMLHTTPRequest2Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback)