# IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2 IOCTL

## Description

The **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2** I/O control is sent by an application to retrieve information about the protocols that are supported by a particular USB port on a hub. The request also retrieves the speed capability of the port.

**IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2** is a user-mode I/O control request. This request targets the Universal Serial Bus (USB) hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

**AssociatedIrp.SystemBuffer** points to a caller-allocated [USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2) structure.

 On input, the caller must set the structure members as follows:

* The caller must specify the port number in the **ConnectionIndex** member. **ConnectionIndex** must be a value in the range of 1 to *n*, where *n* is the highest port number retrieved in a previous [IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex) I/O control request.
* The caller must set a protocol flag in the **SupportedUsbProtocols** member (see [USB_PROTOCOLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_protocols)). In Windows 8, **SupportedUsbProtocols.Usb300** must be set to 1. Otherwise, the request fails with the STATUS_INVALID_PARAMETER error code.
* The caller must set the **Length** member to the size, in bytes, of the caller-allocated buffer pointed to by **AssociatedIrp.SystemBuffer**. The size of the buffer must be `sizeof (USB_NODE_CONNECTION_INFORMATION_EX_V2)`.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member indicates the size, in bytes, of the caller-allocated buffer whose size equals `sizeof(USB_NODE_CONNECTION_INFORMATION_EX_V2)`.

### Output buffer

 On output, the [USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2) structure that is pointed to by **AssociatedIrp.SystemBuffer** is filled with information about the attached device.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member indicates the size, in bytes, of the output buffer **SystemBuffer**.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB driver stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## Remarks

The **IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX_V2** request queries the specified port's hub to get information about protocols supported by the port and the operating speed capability, if a device is attached to the port.

If the request completes successfully, the **SupportedUsbProtocols.Usb200** member of [USB_NODE_CONNECTION_INFORMATION_EX_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_node_connection_information_ex_v2) indicates protocols supported by the port. For instance, if the port supports signaling protocol defined by the USB 2.0 specification, then **SupportedUsbProtocols.Usb200** is set to 1.

Note that **SupportedUsbProtocols.Usb110** is always set to 1 for high-speed and full-speed hubs. That is because a high speed-capable hub supports USB 1.1 protocol through split transactions and transaction translators. **SupportedUsbProtocols.Usb110** is never set to 1 for a USB 3.0 port.

In addition, the request also determines whether the port and the attached device are capable of operating at SuperSpeed. If they are, the **Flags.DeviceIsSuperSpeedCapableOrHigher** member is set to 1. If the device attached to the port is currently operating at SuperSpeed, then **DeviceIsOperatingAtSuperSpeedOrHigher** is set to 1.