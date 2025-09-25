# ClfsReadLogRecord function

## Description

The **ClfsReadLogRecord** routine reads a target record in a CLFS stream and returns a read context that the caller can use to read the records preceding or following it in the stream.

## Parameters

### `pvMarshalContext` [in]

A pointer to an opaque context that represents a marshalling area. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `plsnFirst` [in, out]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that supplies the LSN of the target record in the log.

### `peContextMode` [in]

A value from the [CLFS_CONTEXT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_clfs_context_mode) enumeration that specifies the initial mode (ClfsContextUndoNext, ClfsContextPrevious, or ClfsContextForward) of the read context returned in *ppvReadContext*.

### `ppvReadBuffer` [out]

A pointer to a variable that receives a pointer to the data buffer of the target record.

### `pcbReadBuffer` [out]

A pointer to a ULONG-typed variable that receives the size, in bytes, of the buffer pointed to by **ppvReadBuffer*. This is the length of the data buffer of the target record.

### `peRecordType` [out]

A pointer to a variable of type CLFS_RECORD_TYPE that receives one of the following values.

| Value | Meaning |
| --- | --- |
| **ClfsDataRecord** | The target record is a data record. |
| **ClfsRestartRecord** | The target record is a restart record. |

### `plsnUndoNext` [out]

A pointer to a **CLFS_LSN** structure that receives the undo-next LSN of the target record.

### `plsnPrevious` [out]

A pointer to a **CLFS_LSN** structure that receives the previous LSN of the target record.

### `ppvReadContext` [out]

A pointer to a variable that receives a pointer to an opaque read context. The client repeatedly passes this context to [ClfsReadNextLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadnextlogrecord) to read the remaining records in a sequence. After the client has read all the records in the sequence, it calls [ClfsTerminateReadLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsterminatereadlog) to free the read context.

## Return value

**ClfsReadLogRecord** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

You must call **ClfsTerminateReadLog** when you have finished using the read context in order to avoid a memory leak.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

For information about reading records from CLFS streams, see [Reading Data Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-data-records-from-a-clfs-stream) and [Reading Restart Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-restart-records-from-a-clfs-stream).

Read contexts are not thread-safe. Clients are responsible for serializing access to read contexts.

## See also

[ClfsReadNextLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadnextlogrecord)

[ClfsTerminateReadLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsterminatereadlog)