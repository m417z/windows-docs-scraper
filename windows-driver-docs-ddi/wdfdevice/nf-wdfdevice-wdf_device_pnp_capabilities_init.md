# WDF_DEVICE_PNP_CAPABILITIES_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_PNP_CAPABILITIES_INIT** function initializes a [WDF_DEVICE_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_capabilities) structure.

## Parameters

### `Caps` [out]

A pointer to a driver-supplied [WDF_DEVICE_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_capabilities) structure.

## Remarks

The **WDF_DEVICE_PNP_CAPABILITIES_INIT** function zeros the specified [WDF_DEVICE_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_capabilities) structure, sets the structure's **Size** member, and sets other members to default values.

#### Examples

For a code example that uses **WDF_DEVICE_PNP_CAPABILITIES_INIT**, see [WdfDeviceSetPnpCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpnpcapabilities).