# IUPnPServiceDocumentAccess::GetDocumentURL

## Description

The **GetDocumentURL** method retrieves the Service Control Protocol Description (SCPD) URL for a service object. Using this URL, the UPnP control point can download the complete SCPD document.

## Parameters

### `pbstrDocUrl` [out]

The URL to the complete SCPD document.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns **E_FAIL**. This method will fail if called after a service enumeration has already started.

## See also

[IUPnPServiceDocumentAccess](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicedocumentaccess)

[IUPnPServiceDocumentAccess:GetDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservicedocumentaccess-getdocument)