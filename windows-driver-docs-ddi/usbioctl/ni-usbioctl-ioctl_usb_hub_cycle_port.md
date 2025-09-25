# IOCTL_USB_HUB_CYCLE_PORT IOCTL

## Description

The **IOCTL_USB_HUB_CYCLE_PORT** I/O control request power-cycles the port that is associated with the PDO that receives the request.

**IOCTL_USB_HUB_CYCLE_PORT** is a user-mode I/O control request. This request targets the USB hub device (GUID_DEVINTERFACE_USB_HUB).

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member points to a caller-allocated [USB_CYCLE_PORT_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_cycle_port_params) structure that specifies the port number.

### Input buffer length

The size of a [USB_CYCLE_PORT_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_cycle_port_params) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## Remarks

You can also power cycle the port by using the **Device Manager**'s **Enable**/**Disable** feature. This feature causes the bus driver to reset the device. Alternatively, you can use DevCon to enable or disable the device.

The executable for DevCon can be found in the `\WinDDK\build_number\tools\devcon\\devcon.exe` folder.