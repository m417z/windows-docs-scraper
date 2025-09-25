# ClfsAdvanceLogBase function

## Description

The **ClfsAdvanceLogBase** routine sets the base LSN of a CLFS stream.

## Parameters

### `pvMarshalContext` [in, out]

A pointer to an opaque context that represents a marshalling area associated with a CLFS stream. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

### `plsnBase` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that contains the new base LSN. This parameter must be the LSN of one of the records in the stream. Also, this parameter must be greater than or equal to the stream's current base LSN and less than or equal to the stream's current last LSN.

### `fFlags` [in]

This parameter is reserved for system use. Callers must set this parameter to zero.

## Return value

**ClfsAdvanceLogBase** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

**ClfsAdvanceLogBase** does not write any records to the CLFS log; the only updates to the log are in the metadata. If you want to update the base LSN and write a restart record to a stream at the same time, call [ClfsWriteRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfswriterestartarea).

Whenever possible, CLFS avoids writing queued log records that have LSNs less than the new base LSN to stable storage.

**ClfsAdvanceLogBase** does not check to see whether the LSN supplied in *plsnBase* is actually the LSN of one of the records in the stream. If the caller sets *plsnBase* to an LSN that is not the LSN of one of the records in the stream, the stream's base LSN will be set to a meaningless value.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsWriteRestartArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfswriterestartarea)