# FltQueryDirectoryFile function

## Description

The **FltQueryDirectoryFile** routine returns various kinds of information about files in the directory specified by a given file object. Use [FltQueryDirectoryFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltquerydirectoryfileex) for greater query control.

## Parameters

### `Instance` [in]

Opaque pointer to the filter driver instance that initiates the I/O.

### `FileObject` [in]

Pointer to the file object that represents the directory to be scanned.

### `FileInformation` [out]

Pointer to a buffer that receives the desired information about the file. The structure of the information returned in the buffer is defined by the *FileInformationClass* parameter.

### `Length` [in]

Size, in bytes, of the buffer pointed to by *FileInformation*. The caller should set this parameter according to the given *FileInformationClass*.

### `FileInformationClass` [in]

Type of information to be returned about files in the directory. See the **FileInformationClass** parameter of [**NtQueryDirectoryFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntquerydirectoryfileex) for the list of possible values.

### `ReturnSingleEntry` [in]

Set to **TRUE** if only a single entry should be returned, **FALSE** otherwise. If this parameter is **TRUE**, **FltQueryDirectoryFile** returns only the first entry that is found.

### `FileName` [in, optional]

Pointer to a caller-allocated Unicode string that contains the name of a file (or multiple files, if wildcards are used) within the directory specified by *FileObject*. This parameter is optional and can be **NULL**.

If *FileName* is not **NULL**, only files whose names match the *FileName* string are included in the directory scan. If *FileName* is **NULL**, all files are included. If *RestartScan* is **FALSE**, the value of *FileName* is ignored.

### `RestartScan` [in]

Set to **TRUE** if the scan is to start at the first entry in the directory. Set to **FALSE** if resuming the scan from a previous call. The caller must set this parameter to **TRUE** when calling **FltQueryDirectoryFile** for the first time.

### `LengthReturned` [out, optional]

Receives the number of bytes actually written to the given *FileInformation* buffer.

## Return value

**FltQueryDirectoryFile** returns STATUS_SUCCESS or an appropriate error status. Note that the set of error status values that can be returned is file-system-specific.

## Remarks

**FltQueryDirectoryFile** returns information about files that are contained in the directory that is represented by *FileObject*.

The first call to **FltQueryDirectoryFile** determines the set of entries to be included in the directory scan for all subsequent calls, based on the values of *ReturnSingleEntry*, *FileName*, and *RestartScan*. If there is at least one matching entry, **FltQueryDirectoryFile** creates a FILE_*XXX*_INFORMATION structure (see the above table) for each entry in turn and stores the structure into the buffer.

Assuming that at least one matching directory entry is found, the number of entries for which information is returned is the smallest of the following:

* One entry, if *ReturnSingleEntry* is **TRUE** and *FileName* is **NULL**.

* The number of entries that match the *FileName* string, if *FileName* is not **NULL**. (Note that if the string contains no wildcards, there can be at most one matching entry.)

* The number of entries whose information fits into the specified buffer.

* The number of entries contained in the directory.

On the first call to **FltQueryDirectoryFile**, if the structure created for the first entry found too large to fit into the output buffer, only the fixed portion of the structure is returned. The fixed portion consists of all fields of the structure except the final *FileName* string. On the first call, but not on subsequent ones, the I/O system ensures that the buffer is large enough to hold the fixed portion of the appropriate FILE_*XXX*_INFORMATION structure. When this happens, **FltQueryDirectoryFile** returns an appropriate status value such as STATUS_BUFFER_OVERFLOW. Also on the first call to **FltQueryDirectoryFile**, if there is no file in the *FileObject* directory that matches the *FileName* parameter, **FltQueryDirectoryFile** returns an appropriate status value such as STATUS_NO_SUCH_FILE.

On each call, **FltQueryDirectoryFile** returns as many FILE_*XXX*_INFORMATION structures (one per directory entry) as can be contained entirely in the buffer pointed to by *FileInformation*. As long as the output buffer contains at least one complete structure, the status value returned is STATUS_SUCCESS. No information about any remaining entries is reported. Thus, except in the cases listed above where only one entry is returned, **FltQueryDirectoryFile** must be called at least twice to enumerate the contents of an entire directory (for example, when the *FileName* parameter contains one or more wildcard characters or is **NULL**).

The final call to **FltQueryDirectoryFile** returns an empty output buffer and reports an appropriate status value such as STATUS_NO_MORE_FILES.

> [!NOTE]
> When **FltQueryDirectoryFile** is called multiple times on the same directory, it is possible that the number of entries for which information is returned will be less than expected. This is because the set of entries to be included in the directory scan is fixed on the first call to **FltQueryDirectoryFile**. In subsequent calls, **FltQueryDirectoryFile** resumes the directory scan wherever it left off in this same enumeration. However, between calls to **FltQueryDirectoryFile**, the actual directory entries can change so that they are no longer in sync with the original enumeration.

**FltQueryDirectoryFile** returns zero in any member of a FILE_*XXX*_INFORMATION structure that is not supported by the file system.

For information about other file information query routines, see [File Objects](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

Callers of **FltQueryDirectoryFile** must be running at IRQL = PASSIVE_LEVEL and with special kernel APCs enabled. For more information, see [Disabling APCs](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

## See also

[FILE_BOTH_DIR_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_both_dir_information)

[FILE_DIRECTORY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_directory_information)

[FILE_FULL_DIR_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_full_dir_information)

[FILE_ID_BOTH_DIR_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_both_dir_information)

[FILE_ID_EXTD_BOTH_DIR_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_extd_both_dir_information)

[FILE_ID_EXTD_DIR_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_id_extd_dir_information)

[FILE_ID_FULL_DIR_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_full_dir_information)

[FILE_ID_GLOBAL_TX_DIR_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_id_global_tx_dir_information)

[FILE_NAMES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information)

[FILE_OBJECTID_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_objectid_information)

[FILE_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_quota_information)

[FILE_REPARSE_POINT_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_reparse_point_information)

[FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefile)

[FltCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatefileex2)

[FltQueryDirectoryFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltquerydirectoryfileex)

[IRP_MJ_DIRECTORY_CONTROL IRP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control)

[UNICODE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfwdm/ns-wudfwdm-_unicode_string)

[ZwQueryDirectoryFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwquerydirectoryfile)