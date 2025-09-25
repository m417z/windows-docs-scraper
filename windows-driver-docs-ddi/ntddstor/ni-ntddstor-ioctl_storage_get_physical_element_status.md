# IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS IOCTL

## Description

The **IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS** control code queries for and returns the physical element status from a device.

## Parameters

### Major code

### Input buffer

A pointer to an input buffer that receives a [**PHYSICAL_ELEMENT_STATUS_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_request) structure that defines the starting element to look for the physical element status of a device.

### Input buffer length

Specifies the size of the input buffer, in bytes.

### Output buffer

A pointer to an output buffer that contains a [**PHYSICAL_ELEMENT_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status) structure that defines the physical element status from a device.

### Output buffer length

The size of the output buffer, in bytes.

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status is set to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To perform this operation, call the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
function with the following parameters.

```C++
BOOL
WINAPI
DeviceIoControl((HANDLE)       hDevice,         // handle to device
                (DWORD)        IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS, // dwIoControlCode
                (LPDWORD)      lpInBuffer,      // input buffer
                (DWORD)        nInBufferSize,   // size of input buffer
                (LPDWORD)      lpOutBuffer,     // output buffer
                (DWORD)        nOutBufferSize,  // size of output buffer
                (LPDWORD)      lpBytesReturned, // number of bytes returned
                (LPOVERLAPPED) lpOverlapped );  // OVERLAPPED structure
```

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)

[**PHYSICAL_ELEMENT_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status)

[**PHYSICAL_ELEMENT_STATUS_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_physical_element_status_request)