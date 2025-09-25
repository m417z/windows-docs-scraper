# DXGK_DSI_CAPS structure

## Description

The DXGK_DSI_CAPS structure is used to identify the MIPI Display Serial Interface (DSI) capabilities of a device.

## Members

### `DSITypeMajor`

The major number of the version of the DSI standard supported by this target (e.g. 2,0 for DSI 2, or 1,0 for DSI 1).

### `DSITypeMinor`

The minor number of the version of the DSI standard supported by this target (e.g. 2,0 for DSI 2, or 1,0 for DSI 1). Currently DSI does not have minor versions for the high-level type, but the `DSITypeMinor` is kept for future-proofing.

### `SpecVersionMajor`

The major number of the spec version of the DSI standard supported by this target (e.g. 1,3,1 for spec version 1.3.1).

### `SpecVersionMinor`

The minor number of the spec version of the DSI standard supported by this target (e.g. 1,3,1 for spec version 1.3.1).

### `SpecVersionPatch`

The patch number of the spec version of the DSI standard supported by this target (e.g. 1,3,1 for spec version 1.3.1).

### `TargetMaximumReturnPacketSize`

The maximum packet size that the OEM panel driver can request in a transmission for a long read. The graphics driver controls the size conveyed to the peripheral based on its own needs so may need to change the size for an OEM panel transmission however the graphics driver may have a maximum size it can support.

### `ResultCodeFlags`

### `ResultCodeStatus`

### `Revision`

### `Level`

### `DeviceClassHi`

### `DeviceClassLo`

### `ManufacturerHi`

### `ManufacturerLo`

### `ProductHi`

### `ProductLo`

### `LengthHi`

### `LengthLo`

## Remarks

The remaining fields are the Level 1 DDB data, defined in the MIPI-DDB spec in section 5.2.1.1 DdbL1Data. The fields are in the same order with no padding so the data may be copied directly from what is returned by the peripheral.

A DXGK_DSI_CAPS structure is provided to a graphics driver's [*DxgkDsiCaps*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsicaps) callback function.

## See also

[*DxgkDsiCaps*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsicaps)