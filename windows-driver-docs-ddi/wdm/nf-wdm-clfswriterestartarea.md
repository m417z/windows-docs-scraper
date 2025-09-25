# ClfsWriteRestartArea function

## Description

The **ClfsWriteRestartArea** routine atomically appends a new restart record to a CLFS stream, flushes the restart record to stable storage, and optionally updates the base LSN of the stream.

## Parameters

### `pvMarshalContext` [in, out]

A pointer to an opaque context that represents a marshalling area associated with a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `pvRestartBuffer` [in]

A pointer to a buffer that contains the data for the restart record.

### `cbRestartBuffer` [in]

The size, in bytes, of the buffer pointed to by *pvRestartBuffer*. This is the size of the restart data.

### `plsnBase` [in, optional]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that specifies a new base LSN for the stream. If this parameter is **NULL**, the base LSN is not changed.

### `fFlags` [in]

This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The restart record is placed in newly allocated space in an I/O block. The number of reserved records in the marshalling area is not changed. |
| CLFS_FLAG_USE_RESERVATION | The restart record is placed in previously reserved space in an I/O block. The number of reserved records in the marshalling area is reduced by one. |

### `pcbWritten` [out, optional]

A pointer to a ULONG-typed variable that receives the number of bytes actually forced to stable storage. This parameter can be **NULL**.

### `plsnNext` [out, optional]

A pointer to a **CLFS_LSN** structure that receives the LSN of the newly written restart record.

## Return value

**ClfsWriteRestartArea** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

Typically ClfsWriteRestartArea is called as the last act of a client checkpoint.

ClfsWriteRestartArea is a relatively expensive operation because it causes a flush of all records currently in the marshalling area along with a flush of stream and log metadata.

At any one time, only one marshalling area should be used to write data to a stream. Having two marshalling areas writing into the stream might result in stream corruption.

If you just want to set the base LSN of a stream, use [ClfsAdvanceLogBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsadvancelogbase), which does not necessarily flush any data to stable storage.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn)

[ClfsAdvanceLogBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsadvancelogbase)

[ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea)

[ClfsReadPreviousRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadpreviousrestartarea)

[ClfsReadRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsreadrestartarea)