# _WDF_POWER_DEVICE_STATE enumeration (wudfddi_types.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state) enumeration contains values that identify the power state that a device might support.

## Constants

### `WdfPowerDeviceInvalid`

The device power state is invalid or unknown.

### `WdfPowerDeviceD0`

The device supports the D0 device power state.

### `WdfPowerDeviceD1`

The device supports the D1 device power state.

### `WdfPowerDeviceD2`

The device supports the D2 device power state.

### `WdfPowerDeviceD3`

The device supports the D3 device power state.

### `WdfPowerDeviceD3Final`

The final time that the device enters the D3 device power state. Typically, this value means that the computer's power is being turned off or the device is being removed from the computer. The device might have been already removed.

### `WdfPowerDevicePrepareForHibernation`

The device supports hibernation files, and the computer is ready to hibernate by entering system state S4. The driver must not turn off the device.

### `WdfPowerDeviceMaximum`

Valid enumeration values were exceeded.

## Remarks

The framework supplies one of the values of [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state) to the [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) or [IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit) method to notify the UMDF driver about the power state of the device.

## See also

[IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry)

[IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit)