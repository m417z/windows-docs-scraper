# IWSDDeviceProxy::GetHostMetadata

## Description

Retrieves class-specific metadata for the device describing the features of the device and the services it hosts.

## Parameters

### `ppHostMetadata` [out]

Reference to a [WSD_HOST_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_host_metadata) structure that specifies metadata.
Do not release this object.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppHostMetadata* is **NULL**. |

## Remarks

**GetHostMetadata** will not cause the device proxy to retrieve metadata from the device. Instead, **GetHostMetadata** will return the metadata retrieved with the last call to [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) and [EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata). If neither of these methods has been called, **GetHostMetadata** will return the metadata retrieved when the [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object was initialized.

Upon success, the memory at *ppMetadata* will be valid until [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) or [EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata) is called or until the [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object is released.

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)