# FltGetFileNameInformation function

## Description

The **FltGetFileNameInformation** routine returns name information for a file or directory.

## Parameters

### `CallbackData` [in]

Pointer to a [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure, which is the callback data structure for the I/O operation. This parameter is required and cannot be **NULL**.

### `NameOptions` [in]

A [**FLT_FILE_NAME_OPTIONS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-file-name-options) value containing flags that specify the format of the name information to be returned, as well as the query method that the Filter Manager is to use. The caller must include a name format flag and a query method flag. Additional flags can be used by name provider minifilter drivers to specify name query options. This parameter is required and cannot be **NULL**.

The following are the file name format flag values. Only one of the following flags can be specified. For an explanation of these formats, see [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information).

| Name Format Flag Value | Meaning |
| ----- | ------- |
| FLT_FILE_NAME_NORMALIZED | The *FileNameInformation* parameter receives the address of a structure containing the normalized name for the file. |
| FLT_FILE_NAME_OPENED | The *FileNameInformation* parameter receives the address of a structure containing the name that was used when the file was opened. |
| FLT_FILE_NAME_SHORT | The *FileNameInformation* parameter receives the address of a structure containing the short (8.3) name for the file. The short name consists of up to 8 characters, followed immediately by a period and up to 3 more characters. The short name for a file does not include the volume name, directory path, or stream name. Not valid in the pre-create path. |

Following are the file name query method flag values. Only one of the following flags can be specified.

| Query Method Flag Value | Meaning |
| ----- | ------- |
| FLT_FILE_NAME_QUERY_DEFAULT | If it is not currently safe to query the file system for the file name, **FltGetFileNameInformation** does nothing. Otherwise, **FltGetFileNameInformation** queries the Filter Manager's name cache for the file name information. If the name is not found in the cache, **FltGetFileNameInformation** queries the file system and caches the result. |
| FLT_FILE_NAME_QUERY_CACHE_ONLY | **FltGetFileNameInformation** queries the Filter Manager's name cache for the file name information. **FltGetFileNameInformation** does not query the file system. |
| FLT_FILE_NAME_QUERY_FILESYSTEM_ONLY | **FltGetFileNameInformation** queries the file system for the file name information. **FltGetFileNameInformation** does not query the Filter Manager's name cache, and does not cache the result of the file system query. |
| FLT_FILE_NAME_QUERY_ALWAYS_ALLOW_CACHE_LOOKUP | **FltGetFileNameInformation** queries the Filter Manager's name cache for the file name information. If the name is not found in the cache, and it is currently safe to do so, **FltGetFileNameInformation** queries the file system for the file name information and caches the result. |

Name provider minifilters use the following flags to specify the properties of file name operations.

| Name Provider Flag Value | Meaning |
| ----- | ------- |
| FLT_FILE_NAME_REQUEST_FROM_CURRENT_PROVIDER | A name provider minifilter can use this flag to specify that a name query request should be redirected to itself (the name provider minifilter) rather than being satisfied by the name providers lower in the stack. |
| FLT_FILE_NAME_DO_NOT_CACHE | This flag denotes that the name retrieved from this query should not be cached. Name provider minifilters use this flag as they perform intermediate queries to generate a name. |
| FLT_FILE_NAME_ALLOW_QUERY_ON_REPARSE | A name provider minifilter can use this flag to specify that it is safe to query the name in the post-create path even if STATUS_REPARSE was returned. It is the caller's responsibility to ensure that the **FileObject->FileName** field was not changed. Do not use this flag with mount points or symbolic link reparse points. |

### `FileNameInformation` [out]

Pointer to a caller-allocated variable that receives the address of a system-allocated [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information) structure containing the file name information. **FltGetFileNameInformation** allocates this structure from paged pool. This parameter is required and cannot be **NULL**.

## Return value

If the name information is successfully returned, **FltGetFileNameInformation** returns STATUS_SUCCESS. Otherwise, it returns an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_INVALID_NAME_REQUEST** | **FltGetFileNameInformation** cannot get file name information in any of the following circumstances if the query cannot be satisfied from Filter Manager’s name cache:<br><br>* In the paging I/O path.<br><br>* When the **TopLevelIrp** field of the current thread is not **NULL**, because the resulting file system recursion could cause deadlocks or stack overflows. (For more information about this issue, see [IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp).)<br><br>* After an [IRP_MJ_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup) operation is completed; that is, in the post-clean up, pre-close, or post-close path (the target file object has the FO_CLEANUP_COMPLETE flag set).<br><br>* In a preoperation (PFLT_PRE_OPERATION_CALLBACK) or postoperation (PFLT_POST_OPERATION_CALLBACK) callback routine for any of the following operations:   + IRP_MJ_ACQUIRE_FOR_CC_FLUSH   + IRP_MJ_ACQUIRE_FOR_MOD_WRITE+ IRP_MJ_RELEASE_FOR_CC_FLUSH     + IRP_MJ_RELEASE_FOR_MOD_WRITE     + IRP_MJ_RELEASE_FOR_SECTION_SYNCHRONIZATION<br><br>* In a postoperation callback routine for IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION.<br><br>* When all APCs are disabled; that is, when [KeAreAllApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keareallapcsdisabled) returns TRUE.<br><br>**FltGetFileNameInformation** cannot get the short name of a file in the pre-create path.<br><br>STATUS_FLT_INVALID_NAME_REQUEST is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltGetFileNameInformation** encountered a pool allocation failure. This is an error code. |
| **STATUS_INVALID_PARAMETER** | Returned when an invalid parameter is passed, such as one of the following:<br><br>* The **FileNameInformation** parameter cannot be **NULL**.<br>* The *CallbackData* parameter cannot be **NULL**.<br><br>STATUS_INVALID_PARAMETER is an error code. |
| **STATUS_FLT_NAME_CACHE_MISS** | The file name information is not found in the name cache and *NameOptions* includes FLT_FILE_NAME_QUERY_CACHE_ONLY.<br><br>-or-<br><br>The file name information is not found in the name cache when *NameOptions* includes FLT_FILE_NAME_QUERY_ALWAYS_ALLOW_CACHE_LOOKUP and the file name information cannot be queried from the file system.<br><br>An additional call to **FltGetFileNameInformation** with FLT_FILE_NAME_QUERY_FILESYSTEM_ONLY set in *NameOptions* may return the file name information. |
| **STATUS_NOT_SAME_DEVICE** | The file being queried during pre-create is on a different volume than its parent directory. This error is returned for normalized name queries, where the file was a junction or symlink that resolved to a different volume. |
| **STATUS_ACCESS_DENIED** | If the user opened the file by file ID but does not have traverse privileges for the entire path, **FltGetFileNameInformation** fails with this return value.<br><br>STATUS_ACCESS_DENIED is an error code.<br><br>-or-<br><br>The file is a system file with all access denied. |

## Remarks

**FltGetFileNameInformation** returns the requested name information for the file or directory that is the target of the operation described by *CallbackData*, in the specified format. The file or directory does not need to be opened yet by the file system.

For a pre-create operation, if the **CallbackData->Iopb->OperationFlags** member contains the SL_OPEN_TARGET_DIRECTORY bitwise flag, **FltGetFileNameInformation** returns the name of the containing (parent) directory for the given file. This name is the actual path that the create operation opens.

To parse the contents of the FLT_FILE_NAME_INFORMATION structure returned by **FltGetFileNameInformation**, call [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation). (For more information about file name formats, see [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information).)

After a successful call to **FltGetFileNameInformation**, the caller is responsible for releasing the pointer returned in the *FileNameInformation* parameter when the pointer is no longer needed. The caller does this by calling [FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation).

The caller must not modify the contents of the structure returned in the *FileNameInformation* parameter because this structure is cached by the Filter Manager so that all minifilter drivers can use it.

If **FltGetFileNameInformation** is called in the preoperation callback routine for a create operation to retrieve the opened name, **FltGetFileNameInformation** succeeds even if the path to the file being opened does not exist on the volume.

If **FltGetFileNameInformation** is called in the preoperation callback routine for a create operation to retrieve the normalized name, **FltGetFileNameInformation** succeeds even if the final component of the path to the file being opened does not exist on the volume.

> [!NOTE]
>
> Server Message Block (SMB) support for querying normalized file names on a remote volume varies on different Windows 10 versions. See the [MS-SMB2 Protocol](https://learn.microsoft.com/openspecs/windows_protocols/ms-smb2/5606ad47-5ee0-437a-817e-70c366052962) for details.

In create, hard-link, and rename operations, file name tunneling can cause the final component in normalized file name information that a minifilter driver retrieves in a preoperation callback routine to be invalidated. If a minifilter driver retrieves normalized file name information in a preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine by calling a routine such as **FltGetFileNameInformation**, it must call [FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname) from its postoperation callback ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine to retrieve the correct file name information for the file.

For Windows 8.1 and earlier, **FltGetFileNameInformation** can include a [stream type](https://learn.microsoft.com/windows/win32/fileio/file-streams) *only* when called from a filter’s pre-create callback. To distinguish between a file’s default stream and metadata streams, this call should be made in the pre-create operation. The resulting stream type will remain valid across the lifetime of the file.

 Prior to Windows 8, Filter Manager obtained the normalized name for a file or directory by collecting the name information for each component of the file path. This required multiple queries to the file system to compile the complete path. Starting with Windows 8, local file systems support the **FileNormalizedNameInformation** file information class and only a single query is necessary to obtain the normalized name. Remote file systems may not support the **FileNormalizedNameInformation** file information class. When this is the case, a query for each component of the file path is still required to assemble the normalized name. Under certain network conditions, a full name query can require a significant amount of time to complete.

For more information about normalized file name information, see [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information).

> [!NOTE]
>
> File name tunneling affects only create, hard-link, and rename operations in this way. It does not affect other I/O operations, such as read and write.

The following paired operations can cause the file name *name* to be tunneled:

* delete (*name*)/create(*name*)
* delete (*name*)/rename(*source, name*)
* rename (*name, newname*)/create(*name*)
* rename (*name, newname*)/rename(*source,name*)

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information)

[FLT_FILE_NAME_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-file-name-options)

[FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname)

[FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation)

[FltReferenceFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencefilenameinformation)

[FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation)

[IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)