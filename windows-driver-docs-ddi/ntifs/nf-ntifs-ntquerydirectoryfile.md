# NtQueryDirectoryFile function

## Description

The **NtQueryDirectoryFile** routine returns various kinds of information about files in the directory specified by a given file handle.

## Parameters

### `FileHandle` [in]

A handle returned by [**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile) for the file object that represents the directory for which information is being requested. The file object must have been opened for asynchronous I/O if the caller specifies a non-NULL value for **Event** or **ApcRoutine**.

### `Event` [in, optional]

An optional handle for a caller-created event. If this parameter is supplied, the caller will be put into a wait state until the requested operation is completed and the given event is set to the Signaled state. This parameter is optional and can be NULL. It must be NULL if the caller will wait for the **FileHandle** to be set to the Signaled state.

### `ApcRoutine` [in, optional]

An address of an optional, caller-supplied APC routine to be called when the requested operation completes. This parameter is optional and can be NULL. If there is an I/O completion object associated with the file object, this parameter must be NULL.

### `ApcContext` [in, optional]

An optional pointer to a caller-determined context area if the caller supplies an APC or if an I/O completion object is associated with the file object. When the operation completes, this context is passed to the APC, if one was specified, or is included as part of the completion message that the I/O Manager posts to the associated I/O completion object.

This parameter is optional and can be NULL. It must be NULL if **ApcRoutine** is NULL and there is no I/O completion object associated with the file object.

### `IoStatusBlock` [out]

A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the operation. For successful calls that return data, the number of bytes written to the **FileInformation** buffer is returned in the structure's **Information** member.

### `FileInformation` [out]

A pointer to a buffer that receives the desired information about the file. The structure of the information returned in the buffer is defined by the **FileInformationClass** parameter.

### `Length` [in]

The size, in bytes, of the buffer pointed to by **FileInformation**. The caller should set this parameter according to the given **FileInformationClass**.

### `FileInformationClass` [in]

The type of information to be returned about files in the directory. Type of information to be returned about files in the directory. See the **FileInformationClass** parameter of [**NtQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntquerydirectoryfileex) for the list of possible values.

### `ReturnSingleEntry` [in]

Set to **TRUE** if only a single entry should be returned, **FALSE** otherwise. If this parameter is **TRUE**, **NtQueryDirectoryFile** returns only the first entry that is found.

### `FileName` [in, optional]

An optional pointer to a caller-allocated Unicode string containing the name of a file (or multiple files, if wildcards are used) within the directory specified by **FileHandle**. This parameter is optional and can be NULL.

If **FileName** is not NULL, only files whose names match the **FileName** string are included in the directory scan. If **FileName** is NULL, all files are included.

The **FileName** is used as a search expression and is captured on the very first call to **NtQueryDirectoryFile** for a given handle. Subsequent calls to **NtQueryDirectoryFile** will use the search expression set in the first call. The **FileName** parameter passed to subsequent calls will be ignored.

### `RestartScan` [in]

Set to **TRUE** if the scan is to start at the first entry in the directory. Set to **FALSE** if resuming the scan from a previous call.

When the **NtQueryDirectoryFile** routine is called for a particular handle, the **RestartScan** parameter is treated as if it were set to **TRUE**, regardless of its value. On subsequent **NtQueryDirectoryFile** calls, the value of the **RestartScan** parameter is honored.

## Return value

The **NtQueryDirectoryFile**routine returns STATUS_SUCCESS or an appropriate error status. The set of error status values that can be returned is file-system-specific. **NtQueryDirectoryFile**also returns the number of bytes actually written to the given **FileInformation** buffer in the **Information** member of **IoStatusblock**. See [**NtQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntquerydirectoryfileex) for a list of some possible error codes.

## Remarks

The **NtQueryDirectoryFile** routine returns information about files that are contained in the directory represented by **FileHandle**.

If provided, the value of the **FileName** parameter determines the entries that are included in the directory scan for all subsequent calls to **NtQueryDirectoryFile** for a given **FileHandle**.

If there is at least one matching entry, **NtQueryDirectoryFile** creates a **FILE_*XXX*_INFORMATION** structure for each entry and stores them in the buffer.

Assuming that at least one matching directory entry is found, the number of entries for which information is returned is the *smallest of the following:

* One entry, if **ReturnSingleEntry** is **TRUE** and **FileName** is NULL.
* The number of entries that match the **FileName** string, if **FileName** is not NULL. (Note that if the string contains no wildcards, there can be at most one matching entry.)
* The number of entries whose information fits into the specified buffer.
* The number of entries contained in the directory.

On the first call to **NtQueryDirectoryFile**, if the structure created for the first entry found is too large to fit into the output buffer, the routine writes the fixed portion of the structure to the output buffer. The routine then writes to the output buffer as much of the **FileName** string as will fit. (The fixed portion of the structure consists of all fields except the final **FileName** string. On the first call, but not on subsequent calls, the I/O system ensures that the buffer is large enough to hold the fixed portion of the appropriate **FILE_*XXX*_INFORMATION** structure.) When this happens, **NtQueryDirectoryFile** returns an appropriate status value such as STATUS_BUFFER_OVERFLOW.

On each call, **NtQueryDirectoryFile** returns as many **FILE_*XXX*_INFORMATION** structures (one per directory entry) as can be contained entirely in the buffer pointed to by **FileInformation**. On the first call, **NtQueryDirectoryFile** returns STATUS_SUCCESS only if the output buffer contains at least one complete structure. On subsequent calls, if the output buffer contains no structures, **NtQueryDirectoryFile** returns STATUS_SUCCESS but sets **IoStatusblock**->**Information** = 0 to notify the caller of this condition. In this case, the caller should allocate a larger buffer and call **NtQueryDirectoryFile** again. No information about any remaining entries is reported. Thus, except in the cases listed above where only one entry is returned, **NtQueryDirectoryFile** must be called at least twice to enumerate the contents of an entire directory.

When calling **NtQueryDirectoryFile**, you may see changes made to the directory that occur in parallel with **NtQueryDirectoryFile** calls. This behavior is dependent on the implementation of the underlying file system.

The final call to **NtQueryDirectoryFile** returns an empty output buffer and reports an appropriate status value such as STATUS_NO_MORE_FILES.

If **NtQueryDirectoryFile** is called multiple times on the same directory and some other operation changes the contents of that directory, any changes may or may not be seen, depending on the timing of the operations.

**NtQueryDirectoryFile**returns zero in any member of a **FILE_*XXX*_INFORMATION** structure that is not supported by the file system.

Callers of **NtQueryDirectoryFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

For information about other file information query routines, see [File Objects](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#file-objects).

> [!NOTE]
> If the call to the **NtQueryDirectoryFile** function occurs in user mode, you should use the name "**NtQueryDirectoryFile**" instead of "**ZwQueryDirectoryFile**".

For calls from kernel-mode drivers, the **Nt*XXX*** and **Zw*XXX*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*XXX*** and **Zw*XXX*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FILE_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_both_dir_information)

[**FILE_DIRECTORY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_directory_information)

[**FILE_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_full_dir_information)

[**FILE_ID_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_both_dir_information)

[**FILE_ID_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_full_dir_information)

[**FILE_NAMES_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information)

[**FILE_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_objectid_information)

[**FILE_REPARSE_POINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_reparse_point_information)

[**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[**NtCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**NtOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)