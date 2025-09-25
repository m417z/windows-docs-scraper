# IWSDiscoveryPublisher::GetXMLContext

## Description

Gets the XML context associated with the device.

## Parameters

### `ppContext` [out]

Pointer to a pointer to an [IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext) object that represents the XML context.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *ppContext* is **NULL**. |
| **E_ABORT** | The publisher has not been started. Attaching a notification sink starts the publisher. To attach a sink, call [RegisterNotificationSink](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoverypublisher-registernotificationsink). |

## Remarks

Returns an optional context for the XML state of the transaction. If the service layer is used then this should be the context the XML namespaces and types were registered with.

## See also

[IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext)

[IWSDiscoveryPublisher](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoverypublisher)