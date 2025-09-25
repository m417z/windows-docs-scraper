# IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES IOCTL

## Description

The **IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES** I/O control request is sent by an application to retrieve information about a specific port on a USB hub.

**IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES** is a user-mode I/O control request. This request targets the Universal Serial Bus (USB) hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

**AssociatedIrp.SystemBuffer** points to a caller-allocated [USB_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_connector_properties) structure. The caller must set the structure members as follows:

* The caller must specify the port number of the port being queried in the **ConnectionIndex** member. **ConnectionIndex** must be a value in the range of 1 to *n*, where *n* is the highest port number retrieved in a previous [IOCTL_USB_GET_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_hub_information_ex) I/O control request.
* The caller must specify the **CompanionIndex** member. For a SuperSpeed hub, the caller must set the **CompanionIndex** member to 0.

  The caller can use **CompanionIndex** to get port numbers associated with the port being queried. If more than one companion port is associated with the port, to get all port numbers, the application can send the request in a loop. Start with **CompanionIndex** set to 0 and increment the **CompanionIndex** value in each iteration until the request completes with **CompanionPortNumber** set to 0 and **CompanionHubSymbolicLinkName** is NULL.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member indicates the size, in bytes, of the caller-allocated buffer pointed to by **AssociatedIrp.SystemBuffer**. For more information see Remarks.

### Output buffer

On output, [USB_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_connector_properties), pointed to by **AssociatedIrp.SystemBuffer**, is filled with information about the physical connector associated with the port.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member indicates the size, in bytes, of the output buffer **SystemBuffer**.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES. If the hub has not been started or is not functional, the request returns STATUS_UNSUCCESSFUL.

## Remarks

The caller must supply a buffer that is large enough to hold a [USB_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_connector_properties) structure and the symbolic link name of a companion hub, if such a hub is associated with the specified port. To obtain the size of the buffer to allocate, the caller must send a **IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES** request. In the request, **AssociatedIrp.SystemBuffer** must be a caller-allocated **USB_PORT_CONNECTOR_PROPERTIES** structure and **Parameters.DeviceIoControl.InputBufferLength** must be `sizeof(USB_PORT_CONNECTOR_PROPERTIES)`. Upon successful completion, the **ActualLength** member of **USB_PORT_CONNECTOR_PROPERTIES** indicates the actual size of the buffer. If a symbolic link name exists, the received value includes the size of the string that stores the link name.

Based on the **ActualLength** value, the caller can then allocate a buffer and send the **IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES** request again. After the request completes, the buffer is filled with port information and the **CompanionHubSymbolicLinkName** member is a Unicode string that contains the symbolic link name of the companion hub.

## See also

[IOCTL_USB_GET_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ni-usbioctl-ioctl_usb_get_port_connector_properties)

[USB_HUB_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_information_ex)

[USB_PORT_CONNECTOR_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_port_connector_properties)