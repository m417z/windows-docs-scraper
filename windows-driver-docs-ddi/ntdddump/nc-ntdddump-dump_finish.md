# DUMP_FINISH callback function

## Description

The *Dump_Finish* callback routine is called after writing all the dump data. The dump port driver generally flushes the cache to ensure the data is stored on the storage media before the system powers down.

## Parameters

### `FilterExtension` [in]

A pointer to a [FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension) structure.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in *Ntstatus.h*.

## See also

[FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension)