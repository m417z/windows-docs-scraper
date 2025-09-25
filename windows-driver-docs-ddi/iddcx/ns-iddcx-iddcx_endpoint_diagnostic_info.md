# IDDCX_ENDPOINT_DIAGNOSTIC_INFO structure

## Description

The **IDDCX_ENDPOINT_DIAGNOSTIC_INFO** provides information about the video data endpoint.

## Members

### `Size`

Total size of this structure, in bytes.

### `TransmissionType`

A [**IDDCX_TRANSMISSION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_transmission_type) value that describes the type of link the video data is being transmitted over.

### `pEndPointFriendlyName`

Pointer to a string with the friendly name of the endpoint, if one exists. This is applicable if the user can give the device a name and is NULL if a friendly name does not exist.

### `pEndPointModelName`

Pointer to a string with the model name of the endpoint. Must be a non-empty string.

### `pEndPointManufacturerName`

Pointer to a string with the manufacturer name of the endpoint. Must be a non-empty string.

### `pHardwareVersion`

Pointer to a [**IDDCX_ENDPOINT_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_endpoint_version) structure that contains the version info for the endpoint hardware.

### `pFirmwareVersion`

Pointer to a [**IDDCX_ENDPOINT_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_endpoint_version) structure that contains the version info for the endpoint firmware.

### `GammaSupport`

 A [**IDDCX_FEATURE_IMPLEMENTATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_feature_implementation) value that indicates how gamma is implemented.

## See also

[**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps)

[**IDDCX_ENDPOINT_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_endpoint_version)

[**IDDCX_FEATURE_IMPLEMENTATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_feature_implementation)

[**IDDCX_TRANSMISSION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_transmission_type)