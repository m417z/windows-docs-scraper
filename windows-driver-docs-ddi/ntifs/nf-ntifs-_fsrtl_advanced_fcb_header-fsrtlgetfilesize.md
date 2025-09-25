# FsRtlGetFileSize function

## Description

The **FsRtlGetFileSize** routine is used to get the size of a file.

## Parameters

### `FileObject` [in]

A pointer to the file object to query.

### `FileSize` [out]

A pointer to a large integer that receives the file size on output.

## Return value

**FsRtlGetFileSize** returns STATUS_SUCCESS or an appropriate error status representing the final completion status of the operation. Possible error status codes include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The memory required for use by this function could not be allocated. |
| **STATUS_FILE_IS_A_DIRECTORY** | The specified *FileObject* refers to a directory. |

## Remarks

The **FsRtlGetFileSize** routine is used to retrieve the file size for a file. Unlike [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile), **FsRtlGetFileSize** does not acquire the file object lock on synchronous file objects. If you already own file system resources, you should call **FsRtlGetFileSize** instead of **ZwQueryInformationFile**, because attempting to acquire the file object lock would violate locking order and lead to deadlocks. The **ZwQueryInformationFile** function should be only if you do not already own file system resources.

**FsRtlGetFileSize** will use fast I/O if it is supported or regular IRP-based query to extract the file size.

## See also

[FltQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)