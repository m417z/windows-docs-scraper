# WDF_DEVICE_STATE_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_STATE_INIT** function initializes a driver's [WDF_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_state) structure.

## Parameters

### `PnpDeviceState` [out]

A pointer to a driver-allocated [WDF_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_state) structure.

## Remarks

The **WDF_DEVICE_STATE_INIT** function initializes all of the [WDF_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_state) structure's [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed members to **WdfUseDefault**.

#### Examples

For a code example that uses **WDF_DEVICE_STATE_INIT**, see [WdfDeviceSetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetdevicestate).

## See also

[WDF_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_state)