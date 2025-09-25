# ClfsFlushBuffers function

## Description

The **ClfsFlushBuffers** routine forces all log I/O blocks in a specified marshalling area to stable storage.

## Parameters

### `pvMarshalContext` [in]

A pointer to an opaque context that represents a marshalling area. The caller previously obtained this pointer by calling [ClfsCreateMarshallingArea](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatemarshallingarea).

## Return value

**ClfsFlushBuffers** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

Calling **ClfsFlushBuffers** is equivalent to calling [ClfsFlushToLsn](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsflushtolsn) with the *plsnFlush* parameter set to CLFS_LSN_NULL.

For an explanation of CLFS concepts and terminology, see [Common Log File System](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-common-log-file-system).

## See also

[ClfsFlushToLsn](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsflushtolsn)