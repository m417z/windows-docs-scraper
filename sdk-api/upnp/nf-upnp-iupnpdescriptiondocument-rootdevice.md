# IUPnPDescriptionDocument::RootDevice

## Description

The
**RootDevice** method returns the root device of the currently loaded document's device tree.

## Parameters

### `ppudRootDevice` [out]

Receives a reference to an
[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) object that describes the device. This reference must be released when it is no longer required.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

Do not use
**RootDevice** unless a device description is first loaded using either
[IUPnPDescriptionDocument::Load](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-load) or
[IUPnPDescriptionDocument::LoadAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-loadasync). The search operation only searches in the currently loaded device description.

## See also

[IUPnPDescriptionDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocument)

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)