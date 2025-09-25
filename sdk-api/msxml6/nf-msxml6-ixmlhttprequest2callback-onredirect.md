# IXMLHTTPRequest2Callback::OnRedirect

## Description

Occurs when a client sends an HTTP request that the server redirects to a new URL.

## Parameters

### `pXHR` [in, optional]

The HTTP request object being redirected.

### `pwszRedirectUrl` [in]

The new URL for the HTTP request.

## Return value

Returns **S_OK** on success.

**Note** This callback function must not throw exceptions.

## Remarks

If the request redirection is not permitted, you can call the Abort method on the pXHR object.

XMLHTTPRequest2 imposes a maximum of 100 re-directions on any request. Any re-directions above that limit generate an [OnError](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onerror) event.
Applications have no access to the headers for re-directions.

Once the final redirection has completed and the final URL has been reached, the application receives an [OnHeadersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable) callback.

## See also

[Abort Method](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-abort)

[IXMLHTTPRequest2Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest2callback)

[OnError Event](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onerror)

[OnHeadersAvailable Event](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2callback-onheadersavailable)