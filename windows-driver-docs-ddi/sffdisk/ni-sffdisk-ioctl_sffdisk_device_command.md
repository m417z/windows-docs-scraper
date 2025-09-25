# IOCTL_SFFDISK_DEVICE_COMMAND IOCTL

## Description

User-mode applications use this IOCTL to send Secure Digital (SD) card commands to an SD card. For a description of these commands, see the *SD Memory Card Part 1 Physical Layer Specification*, and the *SD Memory Card Part 3 Security* specification.

The caller must fill in an [SFFDISK_DEVICE_COMMAND_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff538133(v=vs.85)) structure and pass it as a parameter to the call.

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function (described in the Microsoft Windows SDK documentation) with the following parameters.

```cpp
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

The control code for the operation. This value identifies the specific operation to be performed and the type of device on which to perform it. Use IOCTL_SFFDISK_DEVICE_COMMAND for this operation.

*lpInBuffer*

A pointer to the input buffer. Caller must initialize a [SFFDISK_DEVICE_COMMAND_DATA](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff538133(v=vs.85)) structure and store it at the beginning of the buffer. Caller should store the parameters associated with the command at the location immediately after the SFFDISK_DEVICE_COMMAND_DATA structure.

*nInBufferSize*

Indicates the size in bytes of the input buffer pointed to by the *lpInBuffer* parameter. The size of the input buffer should be the sum of **sizeof**(SFFDISK_DEVICE_COMMAND_DATA) and the size of the command parameters that follow it.

*lpOutBuffer*

A pointer to the output buffer that contains the results of the operation. If the operation fails and **GetLastError** returns the error code ERROR_INSUFFICIENT_BUFFER, the output buffer was not large enough to hold the results data.

*nOutBufferSize*

The size, in bytes, of the output buffer pointed to by the *lpOutBuffer* parameter.

*lpBytesReturned*

A pointer to a variable that receives the size, in bytes, of the results data stored in the buffer pointed to by *lpOutBuffer*.

If the output buffer is too small to hold the return data then it will contain a value of zero on output, the call will fail, and **GetLastError** will return the error code ERROR_INSUFFICIENT_BUFFER. In case.

If *lpOverlapped* is **NULL** (nonoverlapped I/O), caller cannot assign a **NULL** to *lpBytesReturned* parameter on input. If *lpOverlapped* is not **NULL** (overlapped I/O), caller can assign a **NULL** to the *lpBytesReturned* parameter.

If this is an overlapped operation, you can retrieve the number of bytes returned by calling the **GetOverlappedResult** function. If *hDevice* is associated with an I/O completion port, you can get the number of bytes returned by calling the **GetQueuedCompletionStatus** function. For a description of the **GetOverlappedResult** and **GetQueuedCompletionStatus** functions see the Windows SDK documentation.

*lpOverlapped*

A pointer to an OVERLAPPED structure, as described in the Windows SDK documentation.

If the caller opened the device with the FILE_FLAG_OVERLAPPED flag, *lpOverlapped* must point to a valid OVERLAPPED structure. In this case, the system executes [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) as an overlapped, asynchronous operation. If the caller opened the device with the FILE_FLAG_OVERLAPPED flag, and *lpOverlapped* is **NULL**, the function fails in unpredictable ways.

If the caller opened the device without specifying the FILE_FLAG_OVERLAPPED flag, the system ignores the value in *lpOverlapped*, and the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function does not return until the operation has been completed, or until an error occurs.

## Parameters

### Major code

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the operation succeeds, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails, [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call **GetLastError**.