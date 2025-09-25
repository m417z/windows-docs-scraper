# ClfsReadRestartArea function

## Description

The **ClfsReadRestartArea** routine reads the restart record that was most recently written to a specified CLFS stream.

## Parameters

### `pvMarshalContext` [in, out]

A pointer to an opaque context that represents a marshalling area associated with a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `ppvRestartBuffer` [out]

A pointer to a variable that receives a pointer to the data buffer of the restart record.

### `pcbRestartBuffer` [out]

A pointer to a ULONG-typed variable that receives the size, in bytes, of the data buffer pointed to by *pcbRestartBuffer*. This is the length of the data buffer of the restart record.

### `plsn` [out]

A pointer to a CLFS_LSN structure that receives the LSN of the restart record that was read.

### `ppvReadContext` [out]

A pointer to a variable that receives a pointer to an opaque read context. The caller can pass this context to [ClfsReadPreviousRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadpreviousrestartarea) or [ClfsReadNextLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadnextlogrecord). When the caller has finished using the read context, it must free the context by calling [ClfsTerminateReadLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsterminatereadlog).

## Return value

**ClfsReadRestartArea** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

For information about reading records from CLFS streams, see [Reading Data Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-data-records-from-a-clfs-stream) and [Reading Restart Records from a CLFS Stream](https://learn.microsoft.com/windows-hardware/drivers/kernel/reading-restart-records-from-a-clfs-stream).

Read contexts are not thread-safe. Clients are responsible for serializing access to read contexts.

## See also

[ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea)

[ClfsReadNextLogRecord](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadnextlogrecord)

[ClfsReadPreviousRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadpreviousrestartarea)

[ClfsTerminateReadLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsterminatereadlog)