# _HID_MINIDRIVER_REGISTRATION structure

## Description

The HID_MINIDRIVER_REGISTRATION structure contains registration information that a HID minidriver passes to the [HID Client Drivers](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-client-drivers) when the minidriver registers with the class driver.

## Members

### `Revision`

Specifies the HID version that this minidriver supports.

### `DriverObject`

Pointer to the minidriver's [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object).

### `RegistryPath`

Pointer to the minidriver's registry path.

### `DeviceExtensionSize`

Specifies the length, in bytes, that the minidriver requests for a device extension.

### `DevicesArePolled`

Specifies that the devices on the bus that this minidriver supports must be polled in order to obtain data from the device.

### `Reserved`

Reserved for internal system use.

## Remarks

When a HID minidriver calls [HidRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/nf-hidport-hidregisterminidriver), it uses this structure to pass information to the HID class driver. The minidriver must zero-initialize this structure before setting members. A minidriver sets the members **DriverObject** and **RegistryPath** to the driver object and registry path parameters that are passed to the minidriver as system-supplied parameters to its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. **Revision** should be set to HID_REVISION.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[HidRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/nf-hidport-hidregisterminidriver)