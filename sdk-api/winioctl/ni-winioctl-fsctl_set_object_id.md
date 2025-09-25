# FSCTL_SET_OBJECT_ID IOCTL

## Description

Sets the object identifier for the specified file or directory.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  FSCTL_SET_OBJECT_ID,              // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  NULL,                             // lpOutBuffer
  0,                                // nOutBufferSize
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

Object identifiers are used to track files and directories. They are invisible to most applications and should never be modified by applications. Modifying an object identifier can result in the loss of data from portions of a file, up to and including entire volumes of data.

Use this operation to explicitly set an object identifier to a value you provide. Attempting to set an object identifier on an object that already has an object identifier will fail. An attempt to use an object identifier that is already in use on the volume will also fail. Use the [FSCTL_CREATE_OR_GET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_create_or_get_object_id) operation to have the NTFS file system generate an object identifier if the object does not already have one.

Note that the time stamps may not be updated correctly for a remote file. To ensure consistent results, use unbuffered I/O.

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
* [FILE_OBJECTID_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_objectid_buffer)
* [FSCTL_CREATE_OR_GET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_create_or_get_object_id)
* [FSCTL_DELETE_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_delete_object_id)
* [FSCTL_GET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_object_id)
* [FSCTL_SET_OBJECT_ID_EXTENDED](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_object_id_extended)
* [Object Identifiers](https://learn.microsoft.com/windows/desktop/FileIO/distributed-link-tracking-and-object-identifiers)