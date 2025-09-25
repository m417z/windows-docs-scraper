# IUPnPDeviceDocumentAccess::GetDocumentURL

## Description

The
**GetDocumentURL** method returns the URL from which the device description document can be loaded.

## Parameters

### `pbstrDocument` [out]

Receives the URL from which the device description document can be downloaded.

## Return value

If the method succeeds, the return value is as specified above. Otherwise, the method returns one of the COM error codes specified in winerror.h.

## Remarks

This method does not support scripting.

## See also

[IUPnPDescriptionDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocument)

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDeviceDocumentAccess](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicedocumentaccess)