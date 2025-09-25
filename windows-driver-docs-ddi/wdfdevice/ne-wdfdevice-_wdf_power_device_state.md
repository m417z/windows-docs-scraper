# _WDF_POWER_DEVICE_STATE enumeration (wdfdevice.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_POWER_DEVICE_STATE** enumeration identifies the [device power states](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that a device might support.

## Constants

### `WdfPowerDeviceInvalid:0`

The device power state is invalid or unknown.

### `WdfPowerDeviceD0`

The D0 device power state.

### `WdfPowerDeviceD1`

The D1 device power state.

### `WdfPowerDeviceD2`

The D2 device power state.

### `WdfPowerDeviceD3`

The D3 device power state.

### `WdfPowerDeviceD3Final`

Represents the final time that the device enters the D3 device power state. Typically, this enumerator means that the system is being turned off, the device is about to be removed, or a [resource rebalance](https://learn.microsoft.com/windows-hardware/drivers/wdf/the-pnp-manager-redistributes-system-resources) is in progress. The device might have been already removed.

### `WdfPowerDevicePrepareForHibernation`

The device supports hibernation files, and the system is ready to hibernate by entering [system state S4](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-sleeping-states). The driver must not turn off the device. For more information, see [Supporting Special Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-special-files).

### `WdfPowerDeviceMaximum`

The maximum enumerator value for this enumeration.

## See also

[EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry)

[EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit)