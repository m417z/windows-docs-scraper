# IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO IOCTL

## Description

The **IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO**
I/O request returns information about a USB device and the hub it is attached to.

**IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO** is a kernel-mode I/O control request. This request targets the USB hub PDO. This request must be sent at an IRQL of DISPATCH_LEVEL or lower.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.Others.Argument1** points to a [HUB_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_hub_device_config_info_v1) structure to receive the device configuration information.

### Input buffer length

The size of a [HUB_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_hub_device_config_info_v1) structure.

### Output buffer

**Parameters.Others.Argument1** points to a [HUB_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_hub_device_config_info_v1) structure containing the device configuration information.

### Output buffer length

The size of a [HUB_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_hub_device_config_info_v1) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The hub or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.

## Remarks

Upon successful completion, the HardwareIds, CompatibleIds, DeviceDescription [USB_ID_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_id_string) structures contained in the [HUB_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_hub_device_config_info_v1) structure points to string buffers allocated by the hub driver. The caller driver is responsible for releasing these buffers before the driver unloads.

## See also

[HUB_DEVICE_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_hub_device_config_info_v1)

[USB_ID_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbioctl/ns-usbioctl-_usb_id_string)