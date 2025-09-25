# IOCTL_STORAGE_QUERY_PROPERTY IOCTL

## Description

Windows applications can use this control code to return the properties of a storage device or adapter. The request indicates the kind of information to retrieve, such as the inquiry data for a device or the capabilities and limitations of an adapter. **IOCTL_STORAGE_QUERY_PROPERTY** can also be used to determine whether the port driver supports a particular property or which fields in the property descriptor can be modified with a subsequent change-property request.

```cpp
BOOL DeviceIoControl(
     _In_        (HANDLE)       hDevice,                // handle to a partition
     _In_        (DWORD) IOCTL_STORAGE_QUERY_PROPERTY,  // dwIoControlCode
     _In_        (LPVOID)       lpInBuffer,             // input buffer - STORAGE_PROPERTY_QUERY structure
     _In_        (DWORD)        nInBufferSize,          // size of input buffer
     _Out_opt_   (LPVOID)       lpOutBuffer,            // output buffer - see Remarks
     _In_        (DWORD)        nOutBufferSize,         // size of output buffer
     _Out_opt_   (LPDWORD)      lpBytesReturned,        // number of bytes returned
     _Inout_opt_ (LPOVERLAPPED) lpOverlapped            // OVERLAPPED structure
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

The optional output buffer returned through the *lpOutBuffer* parameter can be one of several structures depending on the value of the **PropertyId** member of the [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query) structure pointed to by the *lpInBuffer* parameter. These values are enumerated by the [STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_property_id) enumeration. If the **QueryType** member of the **STORAGE_PROPERTY_QUERY** is set to **PropertyExistsQuery** then no structure is returned.

## See also

* [Disk Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-control-codes)
* [STORAGE_DESCRIPTOR_HEADER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_descriptor_header)
* [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query)