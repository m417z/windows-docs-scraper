# FSCTL_SET_INTEGRITY_INFORMATION IOCTL

## Description

Retrieves the integrity status of a file or directory on a ReFS volume.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                     // handle to file or directory
  FSCTL_SET_INTEGRITY_INFORMATION,      // dwIoControlCode
  (LPDWORD) pInBuffer,                  // FSCTL_SET_INTEGRITY_INFORMATION_BUFFER
  (DWORD) InBufferSize,                 // size of input buffer
  (LPDWORD) NULL,                       // pOutBuffer
  (DWORD) 0,                            // OutBufferSize
  (LPDWORD) NULL,                       // lpBytesReturned
  (LPOVERLAPPED) lpOverlapped           // OVERLAPPED structure
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

If the [ReplaceFile](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-replacefilea) is used to replace a file with integrity set, and the *lpBackupFileName* parameter points to a location that does not have integrity set, the integrity status of the original file will not be persisted.

Writes to integrity streams are always cluster-sized. Reads from integrity streams are always done in 16 KB blocks. This can lead to reads failing even when the corrupt area is outside the region being read. For example, if 4 KB is read at offset 0 in a file and there is corruption starting 12 KB into the file, a read would fail with **ERROR_DATA_CHECKSUM_ERROR** (0x143).

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_GET_INTEGRITY_INFORMATION](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_integrity_information)
* [FSCTL_SET_INTEGRITY_INFORMATION_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-fsctl_set_integrity_information_buffer)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)