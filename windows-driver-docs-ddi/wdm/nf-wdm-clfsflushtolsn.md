## Description

The **ClfsFlushToLsn** routine forces, to stable storage, all records that have an LSN less than or equal to a specified LSN.

## Parameters

### `pvMarshalContext` [in]

A pointer to an opaque context associated with a marshalling area. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `plsnFlush` [in]

A pointer to a [**CLFS_LSN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure. All records that have an LSN less than or equal to *plsnFlush* are guaranteed to be forced to stable storage. If *plsnFlush* is equal to CLFS_LSN_NULL, then all records in the marshalling area are forced to stable storage.

### `plsnLastFlushed` [out, optional]

A pointer to a **CLFS_LSN** structure that receives the LSN of the oldest record that was not flushed. This is the LSN of the record immediately following the last record flushed.

On successful return, *plsnLastFlushed* is greater than the value supplied in *plsnFlush*. However, *plsnLastFlushed* does not necessarily point to a record in the stream. For example, if all records in the stream were flushed, *plsnLastFlushed* is the LSN that will be assigned to the next record written to the stream.

## Return value

**ClfsFlushToLsn** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsFlushBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsflushbuffers)