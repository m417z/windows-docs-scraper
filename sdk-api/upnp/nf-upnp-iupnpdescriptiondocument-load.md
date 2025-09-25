# IUPnPDescriptionDocument::Load

## Description

The
**Load** method loads a document synchronously. This method does not return control to the caller until the load operation is complete.

## Parameters

### `bstrUrl` [in]

Specifies the URL of the document to load.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h, or one of the following UPnP return values.

| Return code | Description |
| --- | --- |
| **UPNP_E_DEVICE_ELEMENT_EXPECTED** | XML document does not have a device element. It is missing either from the root element or the DeviceList element. |
| **UPnP_E_DEVICE_ELEMENT_EXPECTED** | There is no Device element in the specified description document. |
| **UPNP_E_DEVICE_NODE_INCOMPLETE** | XML document is missing one of the required elements from the Device element. |
| **UPNP_E_ICON_ELEMENT_EXPECTED** | XML document does not have an icon element. It is missing from the IconList element, or the DeviceList element does not contain an IconList element. |
| **UPnP_E_ICON_ELEMENT_EXPECTED** | There is no Icon element in the specified description document. |
| **UPNP_E_ICON_NODE_INCOMPLETE** | XML document is missing one of the required elements from the Icon element. |
| **UPnP_E_ICON_NODE_INCOMPLETE** | There is no Icon Node in the specified description document. |
| **UPNP_E_ROOT_ELEMENT_EXPECTED** | XML document does not have a root element at the top level of the document. |
| **UPnP_E_ROOT_ELEMENT_EXPECTED** | There is no Root element in the specified description document. |
| **UPNP_E_SERVICE_ELEMENT_EXPECTED** | XML document does not have a service element. It is missing from the ServiceList element, or the DeviceList element does not contain a ServiceList element. |
| **UPNP_E_SERVICE_NODE_INCOMPLETE** | XML document is missing one of the required elements from the Service element. |

## Remarks

This method should not be called from a user interface thread because it can take a long time for the method to return.

If the
**Load** method is called by a script within a Web page, *bstrUrl* may be a relative URL. The address of the current web page is used as the base URL.

If this method is called from a Web page, the URL the caller specifies must refer to the same server from which the Web page was loaded.

## See also

[IUPnPDescriptionDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocument)

[IUPnPDescriptionDocument::LoadAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-loadasync)