# IWSDServiceProxy::GetServiceMetadata

## Description

Retrieves the metadata for the [IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy) object.

## Parameters

### `ppServiceMetadata` [out]

Reference to a [WSD_SERVICE_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_service_metadata) structure that specifies service metadata. Do not release this object.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppServiceMetadata* is **NULL**. |

## Remarks

This metadata is also available as part of the metadata produced by [IWSDDeviceProxy::GetHostMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-gethostmetadata).

## See also

[IWSDServiceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdserviceproxy)