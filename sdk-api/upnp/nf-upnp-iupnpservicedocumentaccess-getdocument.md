# IUPnPServiceDocumentAccess::GetDocument

## Description

The **GetDocument** method retrieves the Service Control Protocol Description (SCPD) document for a service object. The information provided by this document enables the user to pre-determine which actions are supported by the service, or review information about state variables.

## Parameters

### `pbstrDoc` [out]

The complete SCPD document.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns **E_FAIL**.

## See also

[IUPnPServiceDocumentAccess](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicedocumentaccess)

[IUPnPServiceDocumentAccess::GetDocumentURL](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpservicedocumentaccess-getdocumenturl)