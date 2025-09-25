# FSCTL_GET_NTFS_FILE_RECORD IOCTL

## Description

Retrieves the first file record that is in use and is of a lesser than or equal ordinal value to the requested file reference number.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  FSCTL_GET_NTFS_FILE_RECORD,       // dwIoControlCode
  (LPVOID) lpInBuffer,              // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  (LPVOID) lpOutBuffer,             // output buffer
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

## Remarks

This control code enumerates file identifiers in a downward fashion, and always returns a file record that is in use. This means that the file identifier returned by this control code may not be the same as the file identifier specified in the input buffer. For example, if file identifiers 1 through 9 and 15 are in use, file identifiers 10 through 14 are not in use, and the file record corresponding to file identifier 15 is requested, that file record is returned.

If the file records that correspond to file identifiers 10 through 14 are requested, then the file record corresponding to file identifier 9 is returned. If any of the file records corresponding to file identifiers 1 through 9 are requested, those file records is returned.

To determine the correct size of the output buffer pointed to by *lpOutBuffer*, first call the [FSCTL_GET_NTFS_VOLUME_DATA](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data) control code to get the size of one file record. This is the value of the **BytesPerFileRecordSegment** member of the returned [NTFS_VOLUME_DATA_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-ntfs_extended_volume_data) structure. Then set the size of the output buffer to the following expression:

```sizeof (NTFS_FILE_RECORD_OUTPUT_BUFFER) + sizeof (one file record) - 1```

If a file consists of multiple file records, they must be retrieved individually.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
---------- | ---------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes
Resilient File System (ReFS) | No

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [File Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/file-management-control-codes)
* [NTFS_FILE_RECORD_INPUT_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-ntfs_file_record_input_buffer)
* [NTFS_FILE_RECORD_OUTPUT_BUFFER](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-ntfs_file_record_output_buffer)