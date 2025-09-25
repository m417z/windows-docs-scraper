# IWSDDeviceProxy::GetAllMetadata

## Description

Retrieves all metadata for this device.

## Parameters

### `ppMetadata` [out]

Reference to a [WSD_METADATA_SECTION_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_metadata_section_list) structure that specifies all metadata related to a device.
Do not release this object.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppMetadata* is **NULL**. |

## Remarks

This method is supplied so that extended metadata may be accessed. Manufacturer, service host and device-specific metadata is best obtained using methods provided specifically for those purposes.

**GetAllMetadata** will not cause the device proxy to retrieve metadata from the device. Instead, **GetAllMetadata** will return the metadata retrieved with the last call to [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) and [EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata). If neither of these methods has been called, **GetAllMetadata** will return the metadata retrieved when the [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object was initialized.

Upon success, the memory at *ppMetadata* will be valid until [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) or [EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata) is called, or until the [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object is released.

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)