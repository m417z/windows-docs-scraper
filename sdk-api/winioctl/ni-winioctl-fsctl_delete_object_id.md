# FSCTL_DELETE_OBJECT_ID IOCTL

## Description

Removes the object identifier from a specified file or directory. The underlying object is not deleted.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  FSCTL_DELETE_OBJECT_ID,       // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
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

Object identifiers are used to track files and directories. They are invisible to most applications and should never be modified by applications. Modifying an object identifier can result in the loss of data from portions of a file, up to and including entire volumes of data.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | Yes
SMB 3.0 Transparent Failover (TFO) | Yes
SMB 3.0 with Scale-out File Shares (SO) | Yes
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | No

## See also

* [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [FSCTL_CREATE_OR_GET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_create_or_get_object_id)
* [FSCTL_GET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_object_id)
* [FSCTL_SET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_object_id)
* [FSCTL_SET_OBJECT_ID_EXTENDED](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_object_id_extended)
* [Object Identifiers](https://learn.microsoft.com/windows/desktop/FileIO/distributed-link-tracking-and-object-identifiers)