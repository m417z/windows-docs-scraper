# FltGetFileNameInformationUnsafe function

## Description

The **FltGetFileNameInformationUnsafe** routine returns name information for an open file or directory.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file or directory. The file object must be currently open. This parameter is required and cannot be set to **NULL**.

### `Instance` [in, optional]

Instance pointer for the caller. This parameter can be set to **NULL**.

### `NameOptions` [in]

A [FLT_FILE_NAME_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-file-name-options) value containing flags that specify the format of the name information to be returned, as well as the query method to be used by the Filter Manager. This parameter is required and cannot be set to **NULL**.

The following table describes the name format flag values. Only one of the flags can be specified. For more information about these formats, see [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information).

| Value | Meaning |
| --- | --- |
| FLT_FILE_NAME_NORMALIZED | The *FileNameInformation* parameter receives the address of a structure containing the normalized name for the file. |
| FLT_FILE_NAME_OPENED | The *FileNameInformation* parameter receives the address of a structure containing the name that was used when the file was opened. |
| FLT_FILE_NAME_SHORT | The *FileNameInformation* parameter receives the address of a structure containing the short (8.3) name for the file. The short name consists of up to 8 characters, followed immediately by a period and up to 3 more characters. The short name for a file does not include the volume name, directory path, or stream name. |

The following table describes the query method flag values. Only one of the flags can be specified.

| Value | Meaning |
| --- | --- |
| FLT_FILE_NAME_QUERY_DEFAULT | **FltGetFileNameInformationUnsafe** queries the Filter Manager's name cache for the file name information. If the name is not found in the cache, **FltGetFileNameInformationUnsafe** queries the file system and caches the result. |
| FLT_FILE_NAME_QUERY_CACHE_ONLY | **FltGetFileNameInformationUnsafe** queries the Filter Manager's name cache for the file name information. **FltGetFileNameInformationUnsafe** does not query the file system. |
| FLT_FILE_NAME_QUERY_FILESYSTEM_ONLY | **FltGetFileNameInformationUnsafe** queries the file system for the file name information. **FltGetFileNameInformationUnsafe** does not query the Filter Manager's name cache, and does not cache the result of the file system query. |
| FLT_FILE_NAME_QUERY_ALWAYS_ALLOW_CACHE_LOOKUP | **FltGetFileNameInformationUnsafe** queries the Filter Manager's name cache for the file name information. If the name is not found in the cache, and it is currently safe to do so, **FltGetFileNameInformationUnsafe** queries the file system for the file name information and caches the result. |

### `FileNameInformation` [out]

Pointer to a caller-allocated variable that receives the address of a system-allocated FLT_FILE_NAME_INFORMATION structure. **FltGetFileNameInformationUnsafe** allocates this structure from paged pool. When this information is no longer needed, the caller must release the structure by calling [FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation). This parameter is required and cannot be set to **NULL**.

## Return value

**FltGetFileNameInformationUnsafe** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_INVALID_NAME_REQUEST** | The file object that the *FileObject* parameter points to is not currently open. This is an error code. |
| **STATUS_INVALID_PARAMETER** | An invalid value was passed for the *FileNameInformation* parameter. This is an error code. |

## Remarks

The **FltGetFileNameInformationUnsafe** routine is provided so that you can query the name of a file object outside of the context of an I/O operation on that file object; otherwise, you must call [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation).

Unlike the **FltGetFileNameInformation** routine, **FltGetFileNameInformationUnsafe** does not protect the caller against the following types of circumstances, where querying the file system for name information can cause deadlocks for query methods other than FLT_FILE_NAME_QUERY_CACHE_ONLY:

* In the paging I/O path.

* When the **TopLevelIrp** field of the current thread is not **NULL**. For more information, see [IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp).

* After an [IRP_MJ_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup) operation is completed; that is, in the post-clean up, pre-close, or post-close path (the target file object has the FO_CLEANUP_COMPLETE flag set).

* In a preoperation ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) or postoperation ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) callback routine for any of the following operations:

  * IRP_MJ_ACQUIRE_FOR_CC_FLUSH
  * IRP_MJ_ACQUIRE_FOR_MOD_WRITE
  * IRP_MJ_RELEASE_FOR_CC_FLUSH
  * IRP_MJ_RELEASE_FOR_MOD_WRITE
  * IRP_MJ_RELEASE_FOR_SECTION_SYNCHRONIZATION

* In a postoperation callback routine for IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION.

* When all APCs are disabled; that is, when [KeAreAllApcsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keareallapcsdisabled) returns TRUE.

For Windows Vista / Server 2008 and later, if a minifilter does not yet have a filter instance, such as in its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_initialize) routine, it can use `NULL` for the *Instance* parameter. This allows *DriverEntry* routines to access file name information. Except for this case, a `NULL` value for the instance parameter is reserved for system use.

In create, hard-link, and rename operations, file name tunneling can invalidate the final component in normalized file name information that a minifilter driver retrieves in a preoperation callback routine. If a minifilter driver retrieves normalized file name information in a preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine by calling a routine such as **FltGetFileNameInformationUnsafe**, it must call [FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname) from its postoperation callback ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine to retrieve the correct file name information for the file.

For more information about normalized file name information, see [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information).

## See also

[FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information)

[FLT_FILE_NAME_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-file-name-options)

[FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation)

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname)

[FltReferenceFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencefilenameinformation)

[FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation)

[IRP_MJ_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup)

[IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)