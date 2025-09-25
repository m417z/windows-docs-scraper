# IUPnPDescriptionDocumentCallback::LoadComplete

## Description

The
**LoadComplete** method is invoked when the UPnP framework has finished loading a device description.

## Parameters

### `hrLoadResult` [in]

Specifies the load operation that the UPnP framework has completed. Possible return values are:

| UPnP-specific return value | Meaning |
| --- | --- |
| **UPNP_E_DEVICE_ELEMENT_EXPECTED** | The XML document does not have a device element. It is missing either from the root element or the **DeviceList** element. |
| **UPNP_E_DEVICE_NODE_INCOMPLETE** | The XML document is missing one of the required elements from the **Device** element. |
| **UPNP_E_ICON_ELEMENT_EXPECTED** | The XML document does not have an icon element. It is missing from the **IconList** element, or the **DeviceList** element does not contain an **IconList** element. |
| **UPNP_E_ICON_NODE_INCOMPLETE** | The XML document is missing one of the required elements from the **Icon** element. |
| **UPNP_E_ROOT_ELEMENT_EXPECTED** | The XML document does not have a root element at the top level of the document. |
| **UPNP_E_SERVICE_ELEMENT_EXPECTED** | The XML document does not have a service element. It is missing from the **ServiceList** element, or the **DeviceList** element does not contain a **ServiceList** element. |
| **UPNP_E_SERVICE_NODE_INCOMPLETE** | The XML document is missing one of the required elements from the **Service** element. |

## Return value

The application should return S_OK.

## See also

[IUPnPDescriptionDocument](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocument)

[IUPnPDescriptionDocument::LoadAsync](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdescriptiondocument-loadasync)

[IUPnPDescriptionDocumentCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdescriptiondocumentcallback)