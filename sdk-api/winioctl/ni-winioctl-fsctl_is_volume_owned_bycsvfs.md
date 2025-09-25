# FSCTL_IS_VOLUME_OWNED_BYCSVFS IOCTL

## Description

Determines whether a volume is locked by CSVFS.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  FSCTL_IS_VOLUME_OWNED_BYCSVFS,    // dwIoControlCode
  NULL,                             // input buffer
  0,                                // size of input buffer
  (LPVOID) lpOutBuffer,             // lpOutBuffer
  (DWORD) nOutBufferSize,           // nOutBufferSize
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

## Remarks

If the volume is locked on behalf of CSVFS, the control code returns information that is sent to an NTFS volume. If the volume is locked (using [FSCTL_LOCK_VOLUME](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_lock_volume)) from a request that originates from CSVFS, then the [CSV_IS_OWNED_BY_CSVFS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_is_owned_by_csvfs) structure's **OwnedByCSVFS** member has a value of **TRUE**.

## See also

* [CSV_IS_OWNED_BY_CSVFS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-csv_is_owned_by_csvfs)
* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)