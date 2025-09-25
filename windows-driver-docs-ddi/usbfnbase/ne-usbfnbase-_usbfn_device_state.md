# _USBFN_DEVICE_STATE enumeration

## Description

Defines the Universal Serial Bus (USB) device states for the device/controller. These states correspond to the USB device states as defined in section 9.1 of the USB 2.0 Specification.

## Constants

### `UsbfnDeviceStateMinimum`

The minimum value of the enumeration.

### `UsbfnDeviceStateAttached`

Device is attached to an upstream port.

### `UsbfnDeviceStateDefault`

Device is attached and connected to an upstream port but has not been reset.

### `UsbfnDeviceStateDetached`

Device is not attached to an upstream port.

### `UsbfnDeviceStateAddressed`

Device has been assigned a non-default USB address by the host.

### `UsbfnDeviceStateConfigured`

Device has been configured by the host.

### `UsbfnDeviceStateSuspended`

Device has been suspended.

### `UsbfnDeviceStateStateMaximum`

The maximum value of the enumeration.