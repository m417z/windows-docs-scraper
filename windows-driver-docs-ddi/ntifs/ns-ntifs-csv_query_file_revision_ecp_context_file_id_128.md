## Description

The **CSV_QUERY_FILE_REVISION_ECP_CONTEXT_FILE_ID_128** structure contains the extra create parameter (ECP) context that can be sent to the Cluster Share Volumes (CSV) file system to request a file revision number.

## Members

### `FileId`

The 128-bit file ID.

### `FileRevision`

* FileRevision[0] increases each time the CSV MDS stack is rebuilt and CSVFLT loses its state.
* FileRevision[1] increases each time the CSV MDS stack purges the cached revision number for the file.
* FileRevision[2] increases each time CSV MDS observes that file sizes might have changed or the file might have been written to. It also is incremented when one of the nodes performs the first direct IO on a stream associated with this file after opening this stream.

## Remarks

The file revision number is tracked by the Metadata Node.

The system-defined GUID_ECP_CSV_QUERY_FILE_REVISION_FILE_ID_128 value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.