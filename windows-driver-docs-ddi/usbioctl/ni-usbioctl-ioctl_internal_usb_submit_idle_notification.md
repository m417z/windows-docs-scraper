# IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION IOCTL

## Description

The **IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION** I/O request is used by drivers to inform the USB bus driver that a device is idle and can be suspended.

When sending this IOCTL, caller must furnish a callback routine that does the actual suspension of the device. The USB bus driver will call this routine at PASSIVE_LEVEL when it is safe for the device to be powered down. If the device supports remote wake up and has no Wait/Wake IRP already pending, the callback routine should submit a Wait/Wake IRP to the bus driver for the device, before powering it down.

For additional information, see [Supporting Devices that Have Wake-Up Capabilities](https://learn.microsoft.com/windows-hardware/drivers/kernel/supporting-devices-that-have-wake-up-capabilities) and [USB Selective Suspend](https://learn.microsoft.com/windows-hardware/drivers/usbcon/usb-selective-suspend).

**IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION** is a kernel-mode I/O control request. This request targets the USB hub PDO. This request must be sent at an IRQL of PASSIVE_LEVEL.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

**Parameters.DeviceIoControl.Type3InputBuffer** should be a pointer to a **USB_IDLE_CALLBACK_INFO** structure. This structure should contain a pointer to the callback routine and a pointer to the callback routine context.

The structure holding the callback information is defined in usbioctl.h as follows:

```c++
typedef VOID (*USB_IDLE_CALLBACK)(PVOID Context);

typedef struct _USB_IDLE_CALLBACK_INFO
{
  USB_IDLE_CALLBACK IdleCallback;
  PVOID IdleContext;
} USB_IDLE_CALLBACK_INFO, *PUSB_IDLE_CALLBACK_INFO;
```

### Input buffer length

The size of a **USB_IDLE_CALLBACK_INFO** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The bus or port driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS or the appropriate error status.