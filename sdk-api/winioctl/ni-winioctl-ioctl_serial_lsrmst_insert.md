# IOCTL_SERIAL_LSRMST_INSERT IOCTL

## Description

Enables or disables the placement of line status and modem status values into the regular data stream that an application acquires through the [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) function.

When this line-status and modem-status data placement mode is enabled, status values are preceded in the data stream by an escape character. The user-definable escape character is set by the **IOCTL_SERIAL_LSRMST_INSERT** control code. See the Remarks section for status value details.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_SERIAL_LSRMST_INSERT,   // dwIoControlCode
  (LPVOID) lpInBuffer,          // input buffer
  (DWORD) nInBufferSize,        // size of input buffer
  NULL,                         // lpOutBuffer
  0,                            // nOutBufferSize
  (LPDWORD) lpBytesReturned,    // number of bytes returned
  (LPOVERLAPPED) lpOverlapped   // OVERLAPPED structure
);
```

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

> [!NOTE]
> An application that uses this scheme must examine each character in the data stream to determine the presence of modem-status or line-status data.

The following values follow the designated escape character in the data stream if the **LSRMST_INSERT** mode has been turned on.

Value | Meaning
------|--------
**SERIAL_LSRMST_ESCAPE** | Indicates the reception of the escape character itself into the data stream.
**SERIAL_LSRMST_LSR_DATA** | Indicates that a line status change occurred, and data was available in the receive hardware buffer. Following this **BYTE** is a **BYTE** value of the line status register is the **BYTE** present in the receive hardware buffer when the line status change was processed.
**SERIAL_LSRMST_LSR_NODATA** | Indicates that a line status change occurred, but no data was available in the receive hardware buffer.
**SERIAL_LSRMST_MST** | Indicates that a modem status change occurred. Following this **BYTE** is a **BYTE** that is the value of the modem status register when the modem status change was processed.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)