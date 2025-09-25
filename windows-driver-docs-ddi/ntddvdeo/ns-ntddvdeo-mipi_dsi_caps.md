# MIPI_DSI_CAPS structure

## Description

The **MIPI_DSI_CAPS** structure is used to describe the capabalities and characteristics of a MIPI (mobile industry processor interface) DSI-2 (display serial interface) device.

## Members

### `DSITypeMajor`

Major version of the DSI type.

### `DSITypeMinor`

Minor version of the DSI type.

### `SpecVersionMajor`

Major version of the MIPI DSI specification.

### `SpecVersionMinor`

Minor version of the MIPI DSI specification.

### `SpecVersionPatch`

Patch level of the MIPI DSI specification.

### `TargetMaximumReturnPacketSize`

The maximum size, in bytes, of the return packet that the DSI device can handle.

### `ResultCodeFlags`

Flags that provide additional information about the result of querying the capabilities.

### `ResultCodeStatus`

The status code resulting from the query operation.

### `Revision`

Revision number of the DSI device.

### `Level`

Level of compliance or functionality of the DSI device.

### `DeviceClassHi`

High byte of the device class identifier.

### `DeviceClassLo`

Low byte of the device class identifier.

### `ManufacturerHi`

High byte of the manufacturer identifier.

### `ManufacturerLo`

Low byte of the manufacturer identifier.

### `ProductHi`

High byte of the product identifier.

### `ProductLo`

Low byte of the product identifier.

### `LengthHi`

High byte indicating the length of additional data or descriptors.

### `LengthLo`

Low byte indicating the length of additional data or descriptors.

## Remarks

## See also

[**IOCTL_MIPI_DSI_QUERY_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_query_caps)