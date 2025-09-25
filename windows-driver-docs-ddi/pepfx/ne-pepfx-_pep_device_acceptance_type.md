# _PEP_DEVICE_ACCEPTANCE_TYPE enumeration (pepfx.h)

## Description

The **PEP_DEVICE_ACCEPTANCE_TYPE** enumeration indicates whether a PEP accepts ownership of a device.

## Constants

### `PepDeviceNotAccepted`

The PEP does not claim ownership of this device.

### `PepDeviceAccepted`

The PEP claims ownership of this device.

### `PepDeviceAceptedMax`

Reserved for use by operating system.

## Remarks

This enumeration is used by *DeviceAccepted* member of the [PEP_REGISTER_DEVICE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_device_v2) structure to indicate whether a PEP accepts ownership of a device.

## See also

- [PEP_REGISTER_DEVICE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_device_v2)