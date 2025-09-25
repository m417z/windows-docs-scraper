# IWSDDeviceHost::SetMetadata

## Description

Sets the metadata for a device, excluding user-defined service metadata.

## Parameters

### `pThisModelMetadata` [in]

Reference to a [WSD_THIS_MODEL_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_this_model_metadata) structure which specifies metadata that is common to all instances of the model of this device.
The **Manufacturer**, **ModelNames**, and **ModelNumber** members of the structure must contain non-**NULL**, non-blank entries.

### `pThisDeviceMetadata` [in]

Reference to a [WSD_THIS_DEVICE_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_this_device_metadata) structure which specifies metadata unique to this device. The **FriendlyName**, **FirmwareVersion**, and **SerialNumber** members of this structure must contain non-**NULL**, non-blank entries.

### `pHostMetadata` [in, optional]

Reference to a [WSD_HOST_METADATA](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_host_metadata) structure that specifies service host metadata, which the specific data and characteristics of the device (for example, a printer supports color or has a stapler.).

### `pCustomMetadata` [in, optional]

Reference to a [WSD_METADATA_SECTION_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_metadata_section_list) structure which specifies additional custom metadata associated with this device.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pThisDeviceMetadata* is **NULL**, *pThisModelMetadata* is **NULL**, or either structure does not contain the required members. See the parameter descriptions for a list of required members. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

This method must be called at least once prior to starting any device host which was registered with [RegisterService](https://learn.microsoft.com/windows/desktop/api/wsdhost/nf-wsdhost-iwsddevicehost-registerservice). It may be called after the device is started to update the metadata, in which case WS-Discovery Hello messages are issued indicating the new metadata version.

**Note** The update feature has not yet been implemented.

## See also

[IWSDDeviceHost](https://learn.microsoft.com/windows/desktop/api/wsdhost/nn-wsdhost-iwsddevicehost)