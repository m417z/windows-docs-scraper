# USB_BUS_STATISTICS_0 structure

## Description

The **USB_BUS_STATISTICS_0** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve bus statistics.

## Members

### `DeviceCount`

The number of devices on the bus.

### `CurrentSystemTime`

The current system time.

### `CurrentUsbFrame`

The number of the current USB frame.

### `BulkBytes`

The amount, in bytes, of bulk transfer data.

### `IsoBytes`

The amount, in bytes, of isochronous data.

### `InterruptBytes`

The amount, in bytes, of interrupt data.

### `ControlDataBytes`

The amount, in bytes, of control data.

### `PciInterruptCount`

The amount, in bytes, of interrupt data.

### `HardResetCount`

The number of hard bus resets that have occurred.

### `WorkerSignalCount`

The number of times that a worker thread has signaled completion of a task.

### `CommonBufferBytes`

The number of bytes that are transferred by common buffer.

### `WorkerIdleTimeMs`

The amount of time, in milliseconds, that worker threads have been idle.

### `RootHubEnabled`

A Boolean value that indicates whether the root hub is enabled. If **TRUE**, he root hub is enabled. If **FALSE**, the root hub is disabled.

### `RootHubDevicePowerState`

The power state of the root hub devices. This member can have any of the following values:

| Value | Meaning |
| --- | --- |
| 0 | D0 power state |
| 1 | D1 power state |
| 2 | D2 power state |
| 3 | D3 power state |

### `Unused`

If this member is 1, the bus is active. If 0, the bus is inactive.

### `NameIndex`

The index that is used to generate a symbolic link name for the hub PDO. This format of the symbolic link is USBPDO-*n*, where *n* is the value in **NameIndex**.

## Remarks

The **USB_BUS_STATISTICS_0** structure is used with the [USBUSER_BUS_STATISTICS_0](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_bus_statistics_0_request) user-mode request. For a description of this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

In Windows 8, this request completes successfully. However, the values retrieved from the underlying USB 3.0 driver stack do not reflect actual bus statistics.

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)