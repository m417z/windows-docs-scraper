# ZwQueryDirectoryFile function

## Description

The **ZwQueryDirectoryFile** routine returns various information about files in the directory specified by a given file handle.

## Parameters

### `FileHandle` [in]

A handle returned by [**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile) or [**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile) for the file object that represents the directory for which information is being requested. The file object must have been opened for asynchronous I/O if the caller specifies a non-**NULL** value for **Event** or **ApcRoutine**.

### `Event` [in, optional]

An optional handle for a caller-created event. If this parameter is supplied, the caller will be put into a wait state until the requested operation is completed and the given event is set to the Signaled state. This parameter is optional and can be **NULL**. It must be **NULL** if the caller will wait for the **FileHandle** to be set to the Signaled state.

### `ApcRoutine` [in, optional]

An address of an optional, caller-supplied APC routine to be called when the requested operation completes. This parameter is optional and can be **NULL**. If there is an I/O completion object associated with the file object, this parameter must be **NULL**.

### `ApcContext` [in, optional]

An optional pointer to a caller-determined context area if the caller supplies an APC or if an I/O completion object is associated with the file object. When the operation completes, this context is passed to the APC, if one was specified, or is included as part of the completion message that the I/O Manager posts to the associated I/O completion object.

This parameter is optional and can be **NULL**. It must be **NULL** if **ApcRoutine** is **NULL** and there is no I/O completion object associated with the file object.

### `IoStatusBlock` [out]

A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives the final completion status and information about the operation. For successful calls that return data, the number of bytes written to the **FileInformation** buffer is returned in the structure's **Information** member.

### `FileInformation` [out]

A pointer to an output buffer that receives the desired information about the file. The structure of the information returned in the buffer is defined by the **FileInformationClass** parameter.

### `Length` [in]

The size, in bytes, of the buffer pointed to by **FileInformation**. The caller should set this parameter according to the given **FileInformationClass**.

### `FileInformationClass` [in]

The type of information to be returned about files in the directory. See the **FileInformationClass** parameter of [**NtQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntquerydirectoryfileex) for the list of possible values.

### `ReturnSingleEntry` [in]

Set to **TRUE** if only a single entry should be returned, **FALSE** otherwise. If this parameter is **TRUE**, **ZwQueryDirectoryFile** returns only the first entry that is found.

### `FileName` [in, optional]

An optional pointer to a caller-allocated Unicode string containing the name of a file (or multiple files, if wildcards are used) within the directory specified by **FileHandle**. This parameter is optional:

* If **FileName** is not **NULL**, only files whose names match the **FileName** string are included in the directory scan.
* If **FileName** is **NULL**, all files are included if **ReturnSingleEntry** is **FALSE**; one file is included if **ReturnSingleEntry** is **TRUE**.

The **FileName** is used as a search expression and is captured on the very first call to **ZwQueryDirectoryFile** for a given handle. Subsequent calls to **ZwQueryDirectoryFile** will use the search expression set in the first call. The **FileName** parameter passed to subsequent calls will be ignored.

### `RestartScan` [in]

Set to **TRUE** if the scan is to start at the first entry in the directory. Set to **FALSE** if resuming the scan from a previous call.

When the **ZwQueryDirectoryFile** routine is called for a particular handle, the **RestartScan** parameter is treated as if it were set to **TRUE**, regardless of its value. On subsequent **ZwQueryDirectoryFile** calls, the value of the **RestartScan** parameter is honored.

## Return value

The **ZwQueryDirectoryFile** routine returns STATUS_SUCCESS or an appropriate error status. The set of error status values that can be returned is file system-specific. **ZwQueryDirectoryFile** also returns the number of bytes actually written to the given **FileInformation** buffer in the **Information** member of **IoStatusBlock**. See [**NtQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntquerydirectoryfileex) for a list of some possible error codes.

## Remarks

The **ZwQueryDirectoryFile** routine returns information about files that are contained in the directory represented by **FileHandle**.

If provided, **FileName** determines the entries that are included in the directory scan for all subsequent calls to **ZwQueryDirectoryFile** for a given **FileHandle**.

If there is at least one matching entry, **ZwQueryDirectoryFile** creates a **FILE_*XXX*_INFORMATION** structure for each entry and stores them in the buffer.

Assuming that at least one matching directory entry is found, the number of entries for which information is returned is the *smallest* of the following:

* One entry, if **ReturnSingleEntry** is **TRUE** and **FileName** is **NULL**.
* The number of entries that match the **FileName** string, if **FileName** is not **NULL**. If the string contains no wildcards, there can be at most one matching entry.
* The number of entries whose information fits into the specified buffer.
* The number of entries contained in the directory.

On the first call to **ZwQueryDirectoryFile**, if the structure it creates for the first entry found is too large to fit into the output buffer, this routine does the following:

* Writes the fixed portion of the structure to **FileInformation**'s output buffer. The fixed portion consists of all fields except the final **FileName** string. On the first call, but not on subsequent calls, the I/O system ensures that the buffer is large enough to hold the fixed portion of the appropriate **FILE_*XXX*_INFORMATION** structure.
* Writes to the output buffer as much of the **FileName** string as will fit.
* Returns an appropriate status value such as STATUS_BUFFER_OVERFLOW.

On each call, **ZwQueryDirectoryFile** returns as many **FILE_*XXX*_INFORMATION** structures (one per directory entry) as can be contained entirely in the buffer pointed to by **FileInformation**:

* On the first call, **ZwQueryDirectoryFile** returns STATUS_SUCCESS only if the output buffer contains at least one complete structure.
* On subsequent calls, if the output buffer contains no structures, **ZwQueryDirectoryFile** returns STATUS_SUCCESS but sets **IoStatusBlock**->**Information** = 0 to notify the caller of this condition. In this case, the caller should allocate a larger buffer and call **ZwQueryDirectoryFile** again. No information about any remaining entries is reported. Thus, except in the cases listed above where only one entry is returned, **ZwQueryDirectoryFile** must be called at least twice to enumerate the contents of an entire directory.

When calling **ZwQueryDirectoryFile**, you might see changes made to the directory that occur in parallel with **ZwQueryDirectoryFile** calls. This behavior is dependent on the implementation of the underlying file system.

The final call to **ZwQueryDirectoryFile** returns an empty output buffer and reports an appropriate status value such as STATUS_NO_MORE_FILES.

If **ZwQueryDirectoryFile** is called multiple times on the same directory and some other operation changes the contents of that directory, any changes might or might not be seen, depending on the timing of the operations.

**ZwQueryDirectoryFile** returns zero in any member of a **FILE_*XXX*_INFORMATION** structure that is not supported by the file system.

Callers of **ZwQueryDirectoryFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

For information about other file information query routines, see [File Objects](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#file-objects).

> [!NOTE]
> If the call to the **ZwQueryDirectoryFile** function occurs in user mode, you should use the name "**NtQueryDirectoryFile**" instead of "**ZwQueryDirectoryFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**FILE_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_both_dir_information)

[**FILE_DIRECTORY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_directory_information)

[**FILE_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_full_dir_information)

[**FILE_ID_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_both_dir_information)

[**FILE_ID_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_full_dir_information)

[**FILE_NAMES_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information)

[**FILE_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_objectid_information)

[**FILE_REPARSE_POINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_reparse_point_information)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)

[**ZwQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfileex)

[**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntopenfile)