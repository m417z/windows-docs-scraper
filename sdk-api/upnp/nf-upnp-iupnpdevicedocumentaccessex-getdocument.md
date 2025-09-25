# IUPnPDeviceDocumentAccessEx::GetDocument

## Description

The **GetDocument** method retrieves the XML device description document for a UPnP device.

## Parameters

### `pbstrDocument` [out, retval]

Receives the XML device description document for the device.

After obtaining the XML device document, the memory for this parameter must be free by passing it to SysFreeString.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

**Note** This method does not support scripting.

## See also

[IUPnPDeviceDocumentAccessEx](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicedocumentaccessex)