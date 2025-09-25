# StorPortMarkDeviceFailed function

## Description

The **StorPortMarkDeviceFailed** routine marks a device with failed status. See also [**StorPortMarkDeviceFailedEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportmarkdevicefailedex).

## Parameters

### `HwDeviceExtension`

Pointer to the hardware device extension for the host bus adapter (HBA).

### `StorAddress`

Storage unit device address. This parameter is NULL for adapter devices.

### `Flags`

Set to STORPORT_MARK_DEVICE_FAILED_FLAG_REMOVE_DEVICE to remove the failed device.

### `FailReason`

String that specifies the reason for the device failure along with other details.

## Remarks

A miniport driver can call this function to mark a failed device. If STORPORT_MARK_DEVICE_FAILED_FLAG_REMOVE_DEVICE is not set in *Flags*, Storport will only log the event.

The PnP manager will send an IRP to query the failed device's PnP state. If *Flags* is set to STORPORT_MARK_DEVICE_FAILED_FLAG_REMOVE_DEVICE, the PnP manager will then try to remove the failed device.

## See also

[**IoInvalidateDeviceState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinvalidatedevicestate)

[**StorPortMarkDeviceFailedEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportmarkdevicefailedex)