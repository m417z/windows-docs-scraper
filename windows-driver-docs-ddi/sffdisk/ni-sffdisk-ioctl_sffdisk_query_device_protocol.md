# IOCTL_SFFDISK_QUERY_DEVICE_PROTOCOL IOCTL

## Description

User-mode applications use this IOCTL to retrieve a protocol value that identifies the card as either an SD card or an MMC card. For a description of this command, see the *Secure Digital I/O (SDIO)* specification.

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function (described in the Microsoft Windows SDK documentation) using the following parameters.

```
bRet = DeviceIoControl (
    (HANDLE)  hDevice,
    (DWORD)  dwIoControlCode,
    (PUCHAR)  lpInBuffer,
    (DWORD)  nInBufferSize,
    (PUCHAR)  lpOutBuffer,
    (DWORD)  nOutBufferSize,
    (LPDWORD)  lpBytesReturned,
    (LPOVERLAPPED)  lpOverlapped
  );
```

Parameters

*hDevice*

The handle to a volume in the SD stack.

*dwIoControlCode*

Contains the control code for the operation. This value identifies the specific operation to be performed and the type of device on which to perform it. Use IOCTL_SFFDISK_QUERY_DEVICE_PROTOCOL for this operation.

*lpInBuffer*

Not used with this IOCTL. Caller should pass in a **NULL**.

*nInBufferSize*

Not used with this IOCTL. Caller should pass in a value of 0.

*lpOutBuffer*

Pointer to a [SFFDISK_QUERY_DEVICE_PROTOCOL_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff538140(v=vs.85)) structure in a user-supplied buffer that contains the results data. The **ProtocolGUID** member of the SFFDISK_QUERY_DEVICE_PROTOCOL_DATA structure contains a GUID that identifies the card as either an SD card or an MMC card. If the operation fails and **GetLastError** returns the error code STATUS_BUFFER_TOO_SMALL, the output buffer was not large enough to hold the results data.

*nOutBufferSize*

Contains the size, in bytes, of the output buffer pointed to by the *lpOutBuffer* parameter.

*lpBytesReturned*

Pointer to a variable that receives the size, in bytes, of the results data stored in the buffer pointed to by *lpOutBuffer*.

If the output buffer is too small to hold the return data then it will contain a value of zero on output, the call will fail, and **GetLastError** will return the error code ERROR_INSUFFICIENT_BUFFER. In case.

If *lpOverlapped* is **NULL** (nonoverlapped I/O), caller cannot assign a **NULL** to *lpBytesReturned* parameter on input. If *lpOverlapped* is not **NULL** (overlapped I/O), caller can assign a **NULL** to the *lpBytesReturned* parameter.

If this is an overlapped operation, you can retrieve the number of bytes returned by calling the **GetOverlappedResult** function. If *hDevice* is associated with an I/O completion port, you can get the number of bytes returned by calling the **GetQueuedCompletionStatus** function. For a description of the **GetOverlappedResult** and **GetQueuedCompletionStatus** functions see the Windows SDK documentation.

*lpOverlapped*

Pointer to an OVERLAPPED structure, as described in the Windows SDK documentation.

If the caller opened the device with the FILE_FLAG_OVERLAPPED flag, *lpOverlapped* must point to a valid OVERLAPPED structure. In this case, the system executes [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) as an overlapped, asynchronous operation. If the caller opened the device with the FILE_FLAG_OVERLAPPED flag, and *lpOverlapped* is **NULL**, the function fails in unpredictable ways.

If the caller opened the device without specifying the FILE_FLAG_OVERLAPPED flag, the system ignores the value in *lpOverlapped*, and the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function does not return until the operation has been completed, or until an error occurs.

## Parameters

### Major code

### Input buffer

TBD

### Input buffer length

TBD

### Output buffer

TBD

### Output buffer length

TBD

### Input/output buffer

TBD

### Input/output buffer length

TBD

### Status block

If the operation succeeds, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call **GetLastError**.