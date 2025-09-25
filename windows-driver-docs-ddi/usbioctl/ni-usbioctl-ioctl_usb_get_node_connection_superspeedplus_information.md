## Description

The **IOCTL_USB_GET_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION** request retrieves USB port super-speed lane information.

Client drivers must send this IOCTL at an IRQL of PASSIVE_LEVEL.

**IOCTL_USB_GET_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

[IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-device-control)

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

Both input and output buffers point to a caller-allocated **[USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-usb_node_connection_superspeedplus_information)** structure. On input, the ConnectionIndex member of this structure must contain a number greater than or equal to 1 that indicates the number of the port whose super-speed lane information is to be reported. The hub driver returns super-speed lane information in the remaining members of the **[USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-usb_node_connection_superspeedplus_information)** structure. The IRP, the *AssociatedIrp.SystemBuffer* member points to the **[USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-usb_node_connection_superspeedplus_information)** structure.

On output, the **[USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-usb_node_connection_superspeedplus_information)** structure receives information about the indicated super-speed lanes from the USB hub driver.

### Input/output buffer length

The size of a **[USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-usb_node_connection_superspeedplus_information)** structure.

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## Remarks

Here is an example that shows how to retrieve the USB port super-speed lane information.

```cpp
success = DeviceIoControl(hHubDevice,
                          IOCTL_USB_GET_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION,
                          connectionSSPInfo,
                          sizeof(USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION),
                          connectionSSPInfo,
                          sizeof(USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION),
                          &nBytes,
                          NULL);
```

## See also

- **[USB_NODE_CONNECTION_SUPERSPEEDPLUS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-usb_node_connection_superspeedplus_information)**
- **[IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_node_connection_information_ex)**