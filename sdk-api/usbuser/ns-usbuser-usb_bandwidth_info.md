# USB_BANDWIDTH_INFO structure

## Description

The **USB_BANDWIDTH_INFO** structure is used with the [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request) I/O control request to retrieve information about the allocated bandwidth.

## Members

### `DeviceCount`

The number of devices on the bus.

### `TotalBusBandwidth`

The amount of allocated bandwidth, in bits per millisecond.

### `Total32secBandwidth`

The amount of allocated bandwidth bits in each 32-millisecond time slice.

### `AllocedBulkAndControl`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for bulk and control transfers.

### `AllocedIso`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for isochronous transfers.

### `AllocedInterrupt_1ms`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for interrupt transactions when the period is 1 millisecond.

### `AllocedInterrupt_2ms`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for interrupt transactions when the period is 2 milliseconds.

### `AllocedInterrupt_4ms`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for interrupt transactions when the period is 4 milliseconds.

### `AllocedInterrupt_8ms`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for interrupt transactions when the period is 8 milliseconds.

### `AllocedInterrupt_16ms`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for interrupt transactions when the period is 16 milliseconds.

### `AllocedInterrupt_32ms`

The amount of bandwidth, in bits per 32-millisecond, that is allocated for interrupt transactions when the period is 32 milliseconds.

## Remarks

The **USB_BANDWIDTH_INFO** structure is used with the USBUSER_GET_BANDWIDTH_INFORMATION user-mode request. For a description of this request, see [IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request).

In Windows 8, this request completes successfully. However, the values retrieved from the underlying USB 3.0 driver stack do not reflect actual information about the allocated bandwidth. That is because the bandwidth information is not exposed by xHCI controllers.

## See also

[IOCTL_USB_USER_REQUEST](https://learn.microsoft.com/windows/desktop/api/usbuser/ni-usbuser-ioctl_usb_user_request)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/)