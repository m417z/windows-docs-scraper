## Description

Sends a vendor-defined request to a USB device, using the control pipe, and optionally sends or receives additional data.

## Parameters

### Major code

### Input buffer

Pointer to an [**IO_BLOCK_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_io_block_ex) structure.

### Input buffer length

Size of the input buffer.

### Output buffer

Pointer to the same buffer the **pbyData** member of the IO_BLOCK_EX structure identified, or **NULL** if a data transfer is not being requested.

### Output buffer length

Size of the output buffer, or zero if a data transfer is not being requested.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_SEND_USB_REQUEST control code, the caller must specify the address of an [**IO_BLOCK_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_io_block_ex) structure as the function's *lpInBuffer* parameter. The type of request specified with this I/O control code is device-specific and vendor-defined, as are the type and size of any information that might be sent or received.

The following table shows how input arguments should be specified.

| Argument | Read Operation | Write Operation | No Data Transfer |
|---|---|---|---|
| *lpInBuffer* | IO_BLOCK_EX pointer. | IO_BLOCK_EX pointer. | IO_BLOCK_EX pointer. |
| *lpOutBuffer* | Pointer to buffer that will receive data to be read. | Pointer to buffer containing data to be written. | **NULL** |
| *lpOutBufferSize* | Size of buffer. | Size of buffer. | Zero |
| **bRequest** member of IO_BLOCK_EX structure | Device-specific request code. | Device-specific request code. | Device-specific request code. |
| **pbyData** member of IO_BLOCK_EX structure | Same pointer as *lpOutBuffer*. | Same pointer as *lpOutBuffer*. | **NULL** |
| **uLength** member of IO_BLOCK_EX structure | Same value as *lpOutBufferSize*. | Same value as *lpOutBufferSize*. | Zero |
| **fTransferDirectionIn** member of IO_BLOCK_EX structure | **TRUE** | **FALSE** | **FALSE** |

The **bmRequestType** member of the IO_BLOCK_EX structure is not used with IOCTL_SEND_USB_REQUEST.

Using the [**IO_BLOCK_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_io_block_ex) structure contents, the kernel-mode driver creates a [**URB**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) that contains a [**URB_CONTROL_VENDOR_OR_CLASS_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) structure.

The following table indicates the values assigned to _URB_CONTROL_VENDOR_OR_CLASS_REQUEST structure members.

| Structure Member | Value Assigned |
|---|---|
| **TransferFlags** | 0 |
| **TransferBufferLength** | *pIoBlockEx*-\>**uLength** |
| **TransferBuffer** | *lpOutBuffer* (read) or *pIoBlockEx*-\>**pbyData** (write) |
| **TransferBufferMDL** | **NULL** |
| **RequestTypeReservedBits** | 0xC0 (read) or 0x40 (write) |
| **Request** | *pIoBlockEx*-\>**bRequest** |
| **Value** | (**SHORT**)*pIoBlockEx*-\>**uOffset** |
| **Index** | *pIoBlockEx*-\>**uIndex** |

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).