# IOCTL_STORAGE_PROTOCOL_COMMAND IOCTL

## Description

Windows applications can use **IOCTL_STORAGE_PROTOCOL_COMMAND** to conduct pass-through of protocol specific commands to the storage device or adapter. The request indicates the bus specific command which is further sent to a specific type of device to process. For more information, see the page on [working with NVMe drives](https://learn.microsoft.com/windows/win32/fileio/working-with-nvme-devices#using-ioctl_storage_protocol_command-to-send-commands).

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_STORAGE_PROTOCOL_COMMAND,   // dwIoControlCode
  (LPDWORD) lpInBuffer,             // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  (LPDWORD) lpOutBuffer,            // output buffer
  (DWORD) nOutBufferSize,           // size of output buffer
  (LPDWORD) lpBytesReturned,        // number of bytes returned
  (LPOVERLAPPED) lpOverlapped       // OVERLAPPED structure
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

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [STORAGE_PROPERTY_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_property_id)
* [STORAGE_PROPERTY_QUERY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-storage_property_query)