# IOCTL_INTERNAL_USB_GET_CONTROLLER_NAME IOCTL

## Description

The **IOCTL_INTERNAL_USB_GET_CONTROLLER_NAME** I/O request queries the bus driver for the device name of the USB host controller.

**IOCTL_INTERNAL_USB_GET_CONTROLLER_NAME** is a kernel-mode I/O control request. This request targets the USB hub PDO. This request must be sent at an IRQL of PASSIVE_LEVEL.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** should be a pointer to a [USB_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_name) structure that will be filled in with the name of the host controller.

### Input buffer length

**Parameters.Others.Argument2** should be a ULONG specifying the length of the buffer (in bytes) in **Parameters.Others.Argument1**.

### Output buffer

The bus driver will fill the buffer pointed to by **Parameters.Others.Argument1** with the host controller device name.

### Output buffer length

It will be filled only up to the length specified in **Parameters.Others.Argument2**.

### Input/output buffer

### Input/output buffer length

### Status block

The bus or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.

## Remarks

The caller must supply a buffer that is large enough to hold a [USB_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_name) structure. The **Parameters.Others.Argument2** value indicates size of that buffer. Upon successful completion, the **HubName** member of **USB_HUB_NAME** contains the name of the controller and the **ActualLength** member indicates the length of the controller name string. Note that **ActualLength** does not indicate the size of the entire **USB_HUB_NAME** structure. If the buffer supplied in **Parameters.Others.Argument1** is not large enough to hold the string, the **HubName** value might show a truncated string.

To obtain the size of the buffer required to hold the string, send the request twice. In the first request, specify a buffer that is at least `sizeof(USB_HUB_NAME)` bytes. Otherwise, **ActualLength** does not indicate the correct length of the string and the request fails with STATUS_BUFFER_TOO_SMALL.

After the first request completes successfully, allocate a buffer of `ActualLength + sizeof(ULONG)` bytes and send the request again. After the request completes, **HubName** indicates the entire controller name string.

## See also

[USB_HUB_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_hub_name)