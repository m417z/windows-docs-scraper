## Description

The **ZwReadFile** routine reads data from an open file.

## Parameters

### `FileHandle` [in]

Handle to the file object. This handle is created by a successful call to [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [ZwOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile).

### `Event` [in, optional]

Optionally, a handle to an event object to set to the signaled state after the read operation completes. Device and intermediate drivers should set this parameter to **NULL**.

### `ApcRoutine` [in, optional]

This parameter is reserved. Device and intermediate drivers should set this pointer to **NULL**.

### `ApcContext` [in, optional]

This parameter is reserved. Device and intermediate drivers should set this pointer to **NULL**.

### `IoStatusBlock` [out]

Pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the requested read operation. The **Information** member receives the number of bytes actually read from the file.

### `Buffer` [out]

Pointer to a caller-allocated buffer that receives the data read from the file.

### `Length` [in]

The size, in bytes, of the buffer pointed to by *Buffer*.

### `ByteOffset` [in, optional]

Pointer to a variable that specifies the starting byte offset in the file where the read operation will begin. If an attempt is made to read beyond the end of the file, **ZwReadFile** returns an error.

If the call to [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) set either of the **CreateOptions** flags FILE_SYNCHRONOUS_IO_ALERT or FILE_SYNCHRONOUS_IO_NONALERT, the I/O Manager maintains the current file position. If so, the caller of **ZwReadFile** can specify that the current file position offset be used instead of an explicit **ByteOffset** value. This specification can be made by using one of the following methods:

- Specify a pointer to a LARGE_INTEGER value with the **HighPart** member set to -1 and the **LowPart** member set to the system-defined value FILE_USE_FILE_POINTER_POSITION.

- Pass a **NULL** pointer for *ByteOffset*.

**ZwReadFile** updates the current file position by adding the number of bytes read when it completes the read operation, if it is using the current file position maintained by the I/O Manager.

Even when the I/O Manager is maintaining the current file position, the caller can reset this position by passing an explicit *ByteOffset* value to **ZwReadFile**. Doing this automatically changes the current file position to that *ByteOffset* value, performs the read operation, and then updates the position according to the number of bytes actually read. This technique gives the caller atomic seek-and-read service.

### `Key` [in, optional]

Device and intermediate drivers should set this pointer to **NULL**.

## Return value

**ZwReadFile** returns either STATUS_SUCCESS or the appropriate NTSTATUS error code.

## Remarks

Callers of **ZwReadFile** must have already called [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) with the FILE_READ_DATA or GENERIC_READ value set in the *DesiredAccess* parameter.

If the preceding call to [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) set the FILE_NO_INTERMEDIATE_BUFFERING flag in the *CreateOptions* parameter to **ZwCreateFile**, the *Length* and *ByteOffset* parameters to **ZwReadFile** must be multiples of the sector size. For more information, see **ZwCreateFile**.

**ZwReadFile** begins reading from the given *ByteOffset* or the current file position into the given *Buffer*. It terminates the read operation under one of the following conditions:

- The buffer is full because the number of bytes specified by the *Length* parameter has been read. Therefore, no more data can be placed into the buffer without an overflow.

- The end of file is reached during the read operation, so there is no more data in the file to be transferred into the buffer.

If the caller opened the file with the SYNCHRONIZE flag set in *DesiredAccess*, the calling thread can synchronize to the completion of the read operation by waiting on the file handle, *FileHandle*. The handle is signaled each time that an I/O operation that was issued on the handle completes. However, the caller must not wait on a handle that was opened for synchronous file access (FILE_SYNCHRONOUS_IO_NONALERT or FILE_SYNCHRONOUS_IO_ALERT). In this case, **ZwReadFile** waits on behalf of the caller and does not return until the read operation is complete. The caller can safely wait on the file handle only if all three of the following conditions are met:

- The handle was opened for asynchronous access (that is, neither FILE_SYNCHRONOUS_IO_**XXX** flag was specified).

- The handle is being used for only one I/O operation at a time.

- **ZwReadFile** returned STATUS_PENDING.

A driver should call **ZwReadFile** in the context of the system process if any of the following conditions exist:

- The driver created the file handle that it passes to **ZwReadFile**.

- **ZwReadFile** will notify the driver of I/O completion by means of an event that the driver created.

- **ZwReadFile** will notify the driver of I/O completion by means of an APC callback routine that the driver passes to **ZwReadFile**.

File and event handles are valid only in the process context where the handles are created. Therefore, to avoid security holes, the driver should create any file or event handle that it passes to **ZwReadFile** in the context of the system process rather than the context of the process that the driver is in.

Likewise, **ZwReadFile** should be called in the context of the system process if it notifies the driver of I/O completion by means of an APC, because APCs are always fired in the context of the thread that issues the I/O request. If the driver calls **ZwReadFile** in the context of a process other than the system one, the APC could be delayed indefinitely, or it might not fire at all.

For more information about working with files, see [Using Files in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-files-in-a-driver).

Callers of **ZwReadFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

If the call to this function occurs in user mode, you should use the name "[NtReadFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntreadfile)" instead of "**ZwReadFile**".

## See also

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)

[ZwSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetinformationfile)

[ZwWriteFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntwritefile)