# IUPnPHttpHeaderControl::AddRequestHeaders

## Description

The [IUPnPHttpHeaderControl](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnphttpheadercontrol)::**AddRequestHeaders** method adds the supplied HTTP header to an HTTP request.

## Parameters

### `bstrHttpHeaders` [in]

String value that contains the HTTP header to attach to the request. For example, "User-Agent: DLNADOC/1.50\r\n".

**Note** For Windows 7 and Windows Server 2008 R2, only the User Agent HTTP header is supported.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPHttpHeaderControl](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnphttpheadercontrol)