# ClfsReadNextLogRecord function

## Description

The **ClfsReadNextLogRecord** routine reads the next record in a sequence, relative to the current record in a read context.

## Parameters

### `pvReadContext` [in, out]

A pointer to a read context that the caller previously obtained by calling [ClfsReadLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadlogrecord) or [ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea).

### `ppvBuffer` [out]

A pointer to a variable that receives a pointer to a buffer that contains the record data.

### `pcbBuffer` [out]

A pointer to a ULONG-typed variable that receives the size, in bytes, of the buffer pointed to by **ppvBuffer*. This is the length of the data buffer of the record read.

### `peRecordType` [in, out]

A pointer to a variable of type CLFS_RECORD_TYPE. The caller must set this parameter to one of the following values.

| Value | Record that will be read |
| --- | --- |
| **ClfsDataRecord** | The next data record. |
| **ClfsRestartRecord** | The next restart record. |
| **ClfsClientRecord** | The next record that is either a data record or a restart record. |

### `plsnUser` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies the LSN of the record to be read. The specified record is read instead of the record that would have been read according to the mode (**ClfsContextUndoNext**, **ClfsContextPrevious**, or **ClfsContextForward**) of the read context (*pvReadContext*). The LSN supplied in *plsnUser* must be less than the current LSN of the read context. This parameter can be **NULL**.

### `plsnUndoNext` [out]

A pointer to a **CLFS_LSN** structure that receives the undo-next LSN of the record that is read.

### `plsnPrevious` [out]

A pointer to a **CLFS_LSN** structure that receives the previous LSN of the record that was read.

### `plsnRecord` [out]

A pointer to a **CLFS_LSN** structure that receives the LSN of the record that was read.

## Return value

**ClfsReadNextLogRecord** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

For information about reading records from CLFS streams, see [Reading Data Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-data-records-from-a-clfs-stream) and [Reading Restart Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-restart-records-from-a-clfs-stream).

Read contexts are not thread-safe. Clients are responsible for serializing access to read contexts.

## See also

[CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn)

[ClfsReadLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadlogrecord)

[ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea)