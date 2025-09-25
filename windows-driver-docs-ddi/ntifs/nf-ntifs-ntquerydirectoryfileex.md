## Description

The **NtQueryDirectoryFileEx** routine returns various kinds of information about files in the directory specified by a given file handle.

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

A pointer to an output buffer that receives the desired information about the file. The structure of the information returned in the buffer is defined by the **FileInformationClass** parameter.

### `Length` [in]

The size, in bytes, of the buffer pointed to by **FileInformation**. The caller should set this parameter according to the given **FileInformationClass**.

### `FileInformationClass`

The type of information to be returned about files in the directory. Type of information to be returned about files in the directory. **FileInformationClass** can be one of the following [**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) values.

| Value | Meaning |
| ----- | ------- |
| **FileDirectoryInformation** (1) | Return a [**FILE_DIRECTORY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_directory_information) structure for each file. |
| **FileFullDirectoryInformation** (2) | Return a [**FILE_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_full_dir_information) structure for each file. |
| **FileBothDirectoryInformation** (3) | Return a [**FILE_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_both_dir_information) structure for each file. |
| **FileNamesInformation** (12) | Return a [**FILE_NAMES_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information) structure for each file. |
| **FileObjectIdInformation** (29) | Return a [**FILE_OBJECTID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_objectid_information) structure for each file that has an object ID on the volume. This information class is valid only for the special directory "\\$Extend\\$ObjId:$O:$INDEX_ALLOCATION" on NTFS volumes. |
| **FileQuotaInformation** (32) | Return a single [**FILE_QUOTA_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information) structure for each user on the volume that has quotas applied. This information class is valid only for the special directory "\\$Extend\\$Quota:$Q:$INDEX_ALLOCATION" on NTFS volumes. |
**FileReparsePointInformation** (33) | Return a single [**FILE_REPARSE_POINT_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_reparse_point_information) structure for each file that has a reparse point on the volume. This information class is valid only for the special directory "\\$Extend\\$Reparse:$R:$INDEX_ALLOCATION" on NTFS and ReFS volumes. |
| **FileIdBothDirectoryInformation** (37) | Return a [**FILE_ID_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_both_dir_information) structure for each file. |
| **FileIdFullDirectoryInformation** (38) | Return a [**FILE_ID_FULL_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_full_dir_information) structure for each file. |
| **FileIdGlobalTxDirectoryInformation** (50) | Return a [**FILE_ID_GLOBAL_TX_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_global_tx_dir_information) structure for each file. |
| **FileIdExtdDirectoryInformation** (60) | Return a [**FILE_ID_EXTD_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_id_extd_dir_information) structure for each file. |
| **FileIdExtdBothDirectoryInformation** (63) | Return a [**FILE_ID_EXTD_BOTH_DIR_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_extd_both_dir_information) structure for each file. |

### `QueryFlags` [in]

One or more of the flags contained in SL_QUERY_DIRECTORY_MASK. Possible values are specified in the following table.

| Value | Meaning |
| ----- | ------- |
| SL_RESTART_SCAN (0x00000001) | The scan will start at the first entry in the directory. If this flag is not set, the scan will resume from where the last query ended. |
| SL_RETURN_SINGLE_ENTRY (0x00000002) | Normally the return buffer is packed with as many matching directory entries that fit. If this flag is set, the file system will return only one directory entry at a time. This does make the operation less efficient. |
| SL_INDEX_SPECIFIED (0x00000004) | The scan should start at a specified indexed position in the directory. This flag can only be set if you generate your own IRP_MJ_DIRECTORY_CONTROL IRP; the index is specified in the IRP. How the position is specified varies from file system to file system. |
| SL_RETURN_ON_DISK_ENTRIES_ONLY (0x00000008) | Any file system filters that perform directory virtualization or just-in-time expansion should simply pass the request through to the file system and return entries that are currently on disk. Not all file systems support this flag. |
| SL_NO_CURSOR_UPDATE_QUERY (0x00000010) | File systems maintain per-FileObject directory cursor information. When multiple threads do queries using the same FileObject, access to the per-FileObject structure is single threaded to prevent corruption of the cursor state. This flag tells the file system to not update per-FileObject cursor state information thus allowing multiple threads to query in parallel using the same handle. It behaves as if SL_RESTART_SCAN is specified on each call. If a wild card pattern is given on the next call, the operation will not pick up where the last query ended. This allows for true asynchronous directory query support. If this flag is used inside a TxF transaction the operation will be failed. Not all file systems support this flag. |

### `FileName` [in, optional]

An optional pointer to a caller-allocated Unicode string containing the name of a file (or multiple files, if wildcards are used) within the directory specified by **FileHandle**. This parameter is optional:

* If **FileName** is not NULL, only files whose names match the **FileName** string are included in the directory scan.
* If **FileName** is NULL:
  * If SL_RETURN_SINGLE_ENTRY is not set in **QueryFlags**, all files are included.
  * If SL_RETURN_SINGLE_ENTRY is set, only one file is included.

The **FileName** is used as a search expression and is captured on the very first call to **NtQueryDirectoryFileEx** for a given handle. Subsequent calls to **NtQueryDirectoryFileEx** will use the search expression set in the first call. The **FileName** parameter passed to subsequent calls will be ignored.

## Return value

**NtQueryDirectoryFileEx** returns STATUS_SUCCESS or an appropriate error status. The set of error status values that can be returned is file system-specific. **NtQueryDirectoryFileEx** also returns the number of bytes actually written to the given **FileInformation** buffer in the **Information** member of **IoStatusBlock**. Some possible error codes and reasons might be the following:

| Return code | Meaning |
| ----------- | ------- |
| STATUS_BUFFER_OVERFLOW | The output buffer isn't large enough to return the full filename. |
| STATUS_BUFFER_TOO_SMALL | The output buffer isn't large enough for at least the base structure identified by **FileInformationClass**. |
| STATUS_INVALID_INFO_CLASS | An invalid **FileInformationClass** was specified, or the information class is valid only for a special condition (for example, valid only for a special directory). |
| STATUS_INVALID_PARAMETER | One of the parameters is invalid for the file system. |

## Remarks

**NtQueryDirectoryFileEx** returns information about files that are contained in the directory represented by **FileHandle**.

If provided, **FileName** determines the entries that are included in the directory scan for all subsequent calls to **NtQueryDirectoryFileEx** for a given **FileHandle**.

If there is at least one matching entry, **NtQueryDirectoryFileEx** creates a **FILE_*XXX*_INFORMATION** structure for each entry and stores them in the buffer.

Assuming that at least one matching directory entry is found, the number of entries for which information is returned is the *smallest* of the following:

* One entry, if SL_RETURN_SINGLE_ENTRY is set in **QueryFlags** and **FileName** is NULL.
* The number of entries that match the **FileName** string, if **FileName** is not NULL. If the string contains no wildcards, there can be at most one matching entry.
* The number of entries whose information fits into the specified buffer.
* The number of entries contained in the directory.

On the first call to **NtQueryDirectoryFileEx**, if the structure it creates for the first entry found is too large to fit into the output buffer, this routine does the following:

* Writes the fixed portion of the structure to **FileInformation**'s output buffer. The fixed portion consists of all fields except the final **FileName** string. On the first call, but not on subsequent calls, the I/O system ensures that the buffer is large enough to hold the fixed portion of the appropriate **FILE_*XXX*_INFORMATION** structure.
* Writes to the output buffer as much of the **FileName** string as will fit.
* Returns an appropriate status value such as STATUS_BUFFER_OVERFLOW.

On each call, **NtQueryDirectoryFileEx** returns as many **FILE_*XXX*_INFORMATION** structures (one per directory entry) as can be contained entirely in the buffer pointed to by **FileInformation**:

* On the first call, **NtQueryDirectoryFileEx** returns STATUS_SUCCESS only if the output buffer contains at least one complete structure.
* On subsequent calls, if the output buffer contains no structures, **NtQueryDirectoryFileEx** returns STATUS_SUCCESS but sets **IoStatusBlock**->**Information** = 0 to notify the caller of this condition. In this case, the caller should allocate a larger buffer and call **NtQueryDirectoryFileEx** again. No information about any remaining entries is reported. Thus, except in the cases listed above where only one entry is returned, **NtQueryDirectoryFileEx** must be called at least twice to enumerate the contents of an entire directory.

When calling **NtQueryDirectoryFileEx**, you might see changes made to the directory that occur in parallel with **NtQueryDirectoryFileEx** calls. This behavior is dependent on the implementation of the underlying file system.

The final call to **NtQueryDirectoryFileEx** returns an empty output buffer and reports an appropriate status value such as STATUS_NO_MORE_FILES.

If **NtQueryDirectoryFileEx** is called multiple times on the same directory and some other operation changes the contents of that directory, any changes might or might not be seen, depending on the timing of the operations.

**NtQueryDirectoryFileEx** returns zero in any member of a **FILE_*XXX*_INFORMATION** structure that is not supported by the file system.

Callers of **NtQueryDirectoryFileEx** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

For information about other file information query routines, see [File Objects](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#file-objects).

> [!NOTE]
> If the call to the **NtQueryDirectoryFileEx** function occurs in kernel mode, you should use the name "**ZwQueryDirectoryFileEx**" instead of "**NtQueryDirectoryFileEx**".

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

[**ZwCreateFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatefile)

[**ZwOpenFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenfile)