# IWSDDeviceProxy::GetThisModelMetadata

## Description

Retrieves model-specific metadata for the device.

## Parameters

### `ppManufacturerMetadata` [out]

Reference to a [WSD_THIS_MODEL_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_this_model_metadata) structure that specifies manufacturer and model-specific metadata. Do not release this object.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *ppManufacturerMetadata* is **NULL**. |

## Remarks

**GetThisModelMetadata** will not cause the device proxy to retrieve metadata from the device. Instead, **GetThisModelMetadata** will return the metadata retrieved with the last call to [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) and [EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata). If neither of these methods has been called, **GetThisModelMetadata** will return the metadata retrieved when the [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object was initialized.

Upon success, the memory at *ppMetadata* will be valid until [BeginGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-begingetmetadata) or [EndGetMetadata](https://learn.microsoft.com/windows/desktop/api/wsdclient/nf-wsdclient-iwsddeviceproxy-endgetmetadata) is called or until the [IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy) object is released.

## See also

[IWSDDeviceProxy](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsddeviceproxy)