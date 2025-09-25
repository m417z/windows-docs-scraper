# ClfsReadPreviousRestartArea function

## Description

The **ClfsReadPreviousRestartArea** routine reads the previous restart record relative to the current record in a read context.

## Parameters

### `pvReadContext` [in]

A pointer to a read context obtained by a previous call to [ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea).

### `ppvRestartBuffer` [out]

A pointer to a variable that receives a pointer to the data buffer of the restart record that is read.

### `pcbRestartBuffer` [out]

A pointer to a ULONG-typed variable that receives the size, in bytes, of the buffer pointed to by **ppvRestartBuffer*. This is the length of the data buffer of the restart record that is read.

### `plsnRestart` [out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that receives the previous LSN of the restart record that was read.

## Return value

**ClfsReadPreviousRestartArea** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h. If there are no previous restart areas, the return value is STATUS_LOG_START_OF_LOG.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

For information about reading records from CLFS streams, see [Reading Data Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-data-records-from-a-clfs-stream) and [Reading Restart Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-restart-records-from-a-clfs-stream).

Read contexts are not thread-safe. Clients are responsible for serializing access to read contexts.

Clients append restart records to a CLFS log by calling [ClfsWriteRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfswriterestartarea).

With the **ReadPreviousLogRestartArea** routine, clients can implement a form of fuzzy checkpointing. For example, the checkpoint state could consist of the log records delimited by two or more restart records.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn)

[ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea)

[ClfsWriteRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfswriterestartarea)