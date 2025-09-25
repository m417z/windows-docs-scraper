# FSCTL_GET_OBJECT_ID IOCTL

## Description

Retrieves the object identifier for the specified file or directory.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,           // handle to file object
  FSCTL_GET_OBJECT_ID,        // dwIoControlCode
  NULL,                       // lpInBuffer
  0,                          // nInBufferSize
  (LPVOID) lpOutBuffer,       // output buffer
  (DWORD) nOutBufferSize,     // size of output buffer
  (LPDWORD) lpBytesReturned,  // number of bytes returned
  (LPOVERLAPPED) lpOverlapped // OVERLAPPED structure
);
```

## Parameters

### `hDevice` [in]

A handle to the file object.

To retrieve a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew) function.

### `dwIoControlCode` [in]

The control code for the operation.

Use **FSCTL_GET_OBJECT_ID** for this operation.

### `lpInBuffer` [in, optional]

Not used with this operation. Set to **NULL**.

### `nInBufferSize` [in]

The size of the input buffer, in bytes. Set to 0 (zero).

### `lpOutBuffer` [out, optional]

A pointer to the output buffer that is to receive the [**FILE_OBJECTID_BUFFER**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-file_objectid_buffer) data returned by the operation.

### `nOutBufferSize` [in]

The size of the output buffer, in bytes. It must be >= **sizeof**(FILE_OBJECTID_BUFFER).

### `lpBytesReturned` [out, optional]

A pointer to a variable that receives the size of the data stored in the output buffer, in bytes.

### `lpOverlapped` [in, out, optional]

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Object identifiers are used to track files and directories. They are invisible to most applications and should never be modified by applications. Modifying an object identifier can result in the loss of data from portions of a file, up to and including entire volumes of data.

If there is no object identifier associated with the specified handle, none is created and an error is returned. To retrieve an existing object identifier or generate one if there is no existing object identifier in one step, use [FSCTL_CREATE_OR_GET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_create_or_get_object_id). To manually assign an object identifier, use [FSCTL_SET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_object_id).

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
* [FSCTL_SET_OBJECT_ID](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_object_id)
* [FSCTL_SET_OBJECT_ID_EXTENDED](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_set_object_id_extended)
* [Object Identifiers](https://learn.microsoft.com/windows/desktop/FileIO/distributed-link-tracking-and-object-identifiers)