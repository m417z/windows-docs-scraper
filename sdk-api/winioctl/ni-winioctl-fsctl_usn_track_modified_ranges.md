# FSCTL_USN_TRACK_MODIFIED_RANGES IOCTL

## Description

Enables range tracking feature for update sequence number (USN) change journal stream on a target volume, or modifies already enabled range tracking parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to volume
  FSCTL_USN_TRACK_MODIFIED_RANGES,  // dwIoControlCode
  (LPDWORD) lpInBuffer,             // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  (LPDWORD) lpOutBuffer,            // lpOutbuffer
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

For the implications of overlapped I/O on this operation, see the Remarks section of the [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

You can use **FSCTL_USN_TRACK_MODIFIED_RANGES** to enable range tracking for the first time for a volume. After the enabling range tracking, the state and parameters will be persisted for that volume and on next reboot the range tracking will be initialized read from the persisted parameters.

You can also use **FSCTL_USN_TRACK_MODIFIED_RANGES** to modify an existing change journal stream range track parameter. If range tracking is already exists, **FSCTL_USN_TRACK_MODIFIED_RANGES** sets it to the parameters provided in the [USN_TRACK_MODIFIED_RANGES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_track_modified_ranges) structure. The chunk size or file size threshold can only be lowered from previous values. Once enabled, range tracking feature cannot be disabled unless the journal is deleted.

To retrieve a handle to a volume, call [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) with the *lpFileName* parameter set to a string in the following form:

\\\\.\\X:

In the preceding string, X is the letter identifying the drive on which the volume appears. The volume must be NTFS 3.0 or later. To obtain the NTFS version of a volume, open a command prompt with Administrator access rights and execute the following command:

**fsutil fsinfo ntfsinfo** _X_**:**

where *X* is the drive letter of the volume.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)