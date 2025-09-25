# WDMUSB_POWER_STATE enumeration

## Description

The **WDMUSB_POWER_STATE** enumeration indicates the power state of a host controller or root hub.

## Constants

### `WdmUsbPowerNotMapped:0`

Power state information is not mapped.

### `WdmUsbPowerSystemUnspecified:100`

Power state information is not available.

### `WdmUsbPowerSystemWorking`

The system is in the working state.

### `WdmUsbPowerSystemSleeping1`

The system is in the S1 power state.

### `WdmUsbPowerSystemSleeping2`

The system is in the S2 power state.

### `WdmUsbPowerSystemSleeping3`

The system is in the S3 power state.

### `WdmUsbPowerSystemHibernate`

The system is hibernating.

### `WdmUsbPowerSystemShutdown`

The system is shutdown.

### `WdmUsbPowerDeviceUnspecified:200`

A device is not specified.

### `WdmUsbPowerDeviceD0`

The host controller is in the D0 power state.

### `WdmUsbPowerDeviceD1`

The host controller is in the D1 power state.

### `WdmUsbPowerDeviceD2`

The host controller is in the D2 power state.

### `WdmUsbPowerDeviceD3`

The host controller is in the D3 power state.

## Remarks

The USB stack uses the **WDMUSB_POWER_STATE** enumeration to report the power state of the host controller after receiving a USBUSER_GET_POWER_STATE_MAP request. For more information about this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Constants and Enumerations](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)