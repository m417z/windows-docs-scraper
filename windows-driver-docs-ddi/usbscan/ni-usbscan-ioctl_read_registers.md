## Description

Reads from USB device registers, using the control pipe.

## Parameters

### Major code

### Input buffer

Pointer to an [IO_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_io_block) structure.

### Input buffer length

Size of the input buffer.

### Output buffer

Pointer to a buffer to receive register contents.

### Output buffer length

Size of the output buffer. The value must match the contents of the **uLength** member of the IO_BLOCK structure.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_READ_REGISTERS I/O control code, the caller must specify the address of an [IO_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_io_block) structure as the function's *lpInBuffer* parameter.

Using the IO_BLOCK contents, the kernel-mode driver creates a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) that contains a [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) structure.

The following table indicates the values assigned to _URB_CONTROL_VENDOR_OR_CLASS_REQUEST structure members.

| Structure Member | Value Assigned |
|---|---|
| **TransferFlags** | 1 |
| **TransferBufferLength** | *pIoBlock*-\>**uLength** |
| **TransferBuffer** | [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)'s *lpOutBuffer* argument. |
| **TransferBufferMDL** | **NULL** |
| **RequestTypeReservedBits** | 0xC0 |
| **Request** | (*pIoBlock*-\>**uLength** \> 1) ? 0x04 : 0x0C |
| **Value** | (**SHORT**)*pIoBlock*-\>**uOffset** |
| **Index** | *pIoBlock*-\>**uIndex** |

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).