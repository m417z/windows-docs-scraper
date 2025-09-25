# IOCTL_WRITE_REGISTERS IOCTL

## Description

Writes to USB device registers, using the control pipe.

## Parameters

### Major code

### Input buffer

Pointer to an [IO_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_io_block) structure.

### Input buffer length

Size of the input buffer.

### Output buffer

NULL

### Output buffer length

Zero

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### DeviceIoControl Parameters

When the **DeviceloControl** function is called with the IOCTL_WRITE_REGISTERS I/O control code, the caller must specify the address of an [IO_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbscan/ns-usbscan-_io_block) structure as the function's *lpInBuffer* parameter.

Using the IO_BLOCK contents, the kernel-mode driver creates a [URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb) that contains a [_URB_CONTROL_VENDOR_OR_CLASS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_control_vendor_or_class_request) structure.

The following table indicates the values assigned to _URB_CONTROL_VENDOR_OR_CLASS_REQUEST structure members.

| Structure member | Value sssigned |
| --- | --- |
| **TransferFlags** | 0 |
| **TransferBufferLength** | *pIoBlock*->**uLength** |
| **TransferBuffer** | *pIoBlock*->**pbyData** |
| **TransferBufferMDL** | **NULL** |
| **RequestTypeReservedBits** | 0x40 |
| **Request** | (*pIoBlock*->**uLength** > 1) ? 0x04 : 0x0C |
| **Value** | (SHORT)*pIoBlock*->**uOffset** |
| **Index** | *pIoBlock*->**uIndex** |

For more information, see [Accessing Kernel-Mode Drivers for Still Image Devices](https://learn.microsoft.com/windows-hardware/drivers/image/accessing-kernel-mode-drivers-for-still-image-devices).

```cpp
DWORD             cbRet;
BOOL              bRet;
IO_BLOCK          IoBlock;
OVERLAPPED        overlapped;

IoBlock.uOffset = (BYTE)byOffset;
IoBlock.uLength = (BYTE)byNbOfReg;
IoBlock.pbyData = pbyData;

memset(&overlapped, 0, sizeof(OVERLAPPED));
overlapped.hEvent =
    CreateEvent(NULL,    // pointer to security attributes
                         // WIN95 ignores this parameter
                FALSE,   // automatic reset
                FALSE,   // initialize to not signaled
                NULL);   // pointer to the event-object name

bRet = DeviceIoControl( DeviceHandle,
                        (DWORD) IOCTL_WRITE_REGISTERS,
                        &IoBlock,
                        sizeof(IO_BLOCK),
                        NULL,
                        0,
                        &cbRet,
                        &overlapped);

if( bRet == TRUE )
{
    WaitForSingleObject(overlapped.hEvent, INFINITE);
    // we do not the test, the result is zero
}

CloseHandle(overlapped.hEvent);
```