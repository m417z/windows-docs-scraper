# DUMP_START callback function

## Description

The *Dump_Start* callback routine is called after initializing the dump driver and just before starting the dump write process.

## Parameters

### `FilterExtension` [in]

A pointer to a [FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension) structure.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values that are defined in *Ntstatus.h*.

## See also

[FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension)