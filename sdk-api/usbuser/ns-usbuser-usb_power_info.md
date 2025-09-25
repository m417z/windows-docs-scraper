# USB_POWER_INFO structure

## Description

The **USB_POWER_INFO** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve device power state that the host controller power policy specifies for the indicated system power state.

## Members

### `SystemState`

On input, a [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies the system power state.

### `HcDevicePowerState`

On output, an [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies the device power state of the host controller.

### `HcDeviceWake`

On output, a [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies whether the host controller is in a wake state.

### `HcSystemWake`

On output, a [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies whether the host controller can wake the system.

### `RhDevicePowerState`

On output, a [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies the device power state of the root hub.

### `RhDeviceWake`

On output, a [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies whether the root hub is in a wake state.

### `RhSystemWake`

On output, a [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies whether the root hub can wake the system.

### `LastSystemSleepState`

On output, a [WDMUSB_POWER_STATE](https://learn.microsoft.com/windows/desktop/api/usbuser/ne-usbuser-wdmusb_power_state)-type enumerator value that specifies the last system sleep state.

### `CanWakeup`

A Boolean value that indicates whether the host controller device can wake up the system from the specified system power state. If **TRUE**, the host controller device can wake up the system. If **FALSE**, the host controller cannot wake up the system.

### `IsPowered`

A Boolean value that indicates whether the host controller is powered when in the specified system power state. If **TRUE**, the host controller is powered. If **FALSE**, the host controller is not powered.

## Remarks

The **USB_POWER_INFO** structure is used with the USBUSER_GET_POWER_STATE_MAP user-mode request. For more information about this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)