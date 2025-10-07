# NtReadFile function

Reads data from an open file.

This function is the user-mode equivalent to the [**ZwReadFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntreadfile) function documented in the Windows Driver Kit (WDK).

## Parameters

*FileHandle* \[in\]

Handle to the file object. This handle is created by a successful call to [**NtCreateFile**](https://learn.microsoft.com/windows/desktop/api/Winternl/nf-winternl-ntcreatefile) or [**NtOpenFile**](https://learn.microsoft.com/windows/desktop/api/Winternl/nf-winternl-ntopenfile).

*Event* \[in, optional\]

Optionally, a handle to an event object to set to the signaled state after the read operation completes. Device and intermediate drivers should set this parameter to **NULL**.

*ApcRoutine* \[in, optional\]

This parameter is reserved. Device and intermediate drivers should set this pointer to **NULL**.

*ApcContext* \[in, optional\]

This parameter is reserved. Device and intermediate drivers should set this pointer to **NULL**.

*IoStatusBlock* \[out\]

Pointer to an [**IO\_STATUS\_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the requested read operation. The **Information** member receives the number of bytes actually read from the file.

*Buffer* \[out\]

Pointer to a caller-allocated buffer that receives the data read from the file.

*Length* \[in\]

The size, in bytes, of the buffer pointed to by *Buffer*.

*ByteOffset* \[in, optional\]

Pointer to a variable that specifies the starting byte offset in the file where the read operation will begin. If an attempt is made to read beyond the end of the file, **NtReadFile** returns an error.

If the call to [**NtCreateFile**](https://learn.microsoft.com/windows/desktop/api/Winternl/nf-winternl-ntcreatefile) set either of the *CreateOptions* flags FILE\_SYNCHRONOUS\_IO\_ALERT or FILE\_SYNCHRONOUS\_IO\_NONALERT, the I/O Manager maintains the current file position. If so, the caller of **NtReadFile** can specify that the current file position offset be used instead of an explicit *ByteOffset* value. This specification can be made by using one of the following methods:

- Specify a pointer to a **LARGE\_INTEGER** value with the **HighPart** member set to -1 and the **LowPart** member set to the system-defined value FILE\_USE\_FILE\_POINTER\_POSITION.

- Pass a **NULL** pointer for *ByteOffset*.

**NtReadFile** updates the current file position by adding the number of bytes read when it completes the read operation, if it is using the current file position maintained by the I/O Manager.

Even when the I/O Manager is maintaining the current file position, the caller can reset this position by passing an explicit *ByteOffset* value to **NtReadFile**. Doing this automatically changes the current file position to that *ByteOffset* value, performs the read operation, and then updates the position according to the number of bytes actually read. This technique gives the caller atomic seek-and-read service.

*Key* \[in, optional\]

Device and intermediate drivers should set this pointer to **NULL**.

## Return value

**NtReadFile** returns either STATUS\_SUCCESS or the appropriate NTSTATUS error code.

## Remarks

Callers of **NtReadFile** must have already called [**NtCreateFile**](https://learn.microsoft.com/windows/desktop/api/Winternl/nf-winternl-ntcreatefile) with the FILE\_READ\_DATA or GENERIC\_READ value set in the *DesiredAccess* parameter.

If the preceding call to [**NtCreateFile**](https://learn.microsoft.com/windows/desktop/api/Winternl/nf-winternl-ntcreatefile) set the FILE\_NO\_INTERMEDIATE\_BUFFERING flag in the *CreateOptions* parameter to **NtCreateFile**, the *Length* and *ByteOffset* parameters to **NtReadFile** must be multiples of the sector size. For more information, see **NtCreateFile**.

**NtReadFile** begins reading from the given *ByteOffset* or the current file position into the given *Buffer*. It terminates the read operation under one of the following conditions:

- The buffer is full because the number of bytes specified by the *Length* parameter has been read. Therefore, no more data can be placed into the buffer without an overflow.

- The end of file is reached during the read operation, so there is no more data in the file to be transferred into the buffer.

If the caller opened the file with the SYNCHRONIZE flag set in *DesiredAccess*, the calling thread can synchronize to the completion of the read operation by waiting on the file handle, *FileHandle*. The handle is signaled each time that an I/O operation that was issued on the handle completes. However, the caller must not wait on a handle that was opened for synchronous file access (FILE\_SYNCHRONOUS\_IO\_NONALERT or FILE\_SYNCHRONOUS\_IO\_ALERT). In this case, **NtReadFile** waits on behalf of the caller and does not return until the read operation is complete. The caller can safely wait on the file handle only if all three of the following conditions are met:

- The handle was opened for asynchronous access (that is, neither FILE\_SYNCHRONOUS\_IO\_*XXX* flag was specified).

- The handle is being used for only one I/O operation at a time.

- **NtReadFile** returned STATUS\_PENDING.

A driver should call **NtReadFile** in the context of the system process if any of the following conditions exist:

- The driver created the file handle that it passes to **NtReadFile**.

- **NtReadFile** will notify the driver of I/O completion by means of an event that the driver created.

- **NtReadFile** will notify the driver of I/O completion by means of an APC callback routine that the driver passes to **NtReadFile**.

File and event handles are valid only in the process context where the handles are created. Therefore, to avoid security holes, the driver should create any file or event handle that it passes to **NtReadFile** in the context of the system process rather than the context of the process that the driver is in.

Likewise, **NtReadFile** should be called in the context of the system process if it notifies the driver of I/O completion by means of an APC, because APCs are always fired in the context of the thread that issues the I/O request. If the driver calls **NtReadFile** in the context of a process other than the system one, the APC could be delayed indefinitely, or it might not fire at all.

For more information about working with files, see [Using Files in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-files-in-a-driver).

Callers of **NtReadFile** must be running at IRQL = PASSIVE\_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Target platform<br> | [Universal](https://msdn.microsoft.com/Library/Windows/Hardware/EB2264A4-BAE8-446B-B9A5-19893936DDCA) |
| Header<br> | Wdm.h (include Wdm.h, Ntddk.h, or Ntifs.h) |
| Library<br> | Ntdll.lib |
| DLL<br> | Ntdll.dll (user mode) |

## See also

[**KeInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[**NtCreateFile**](https://learn.microsoft.com/windows/desktop/api/Winternl/nf-winternl-ntcreatefile)

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[**NtSetInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)

[**NtWriteFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile)

