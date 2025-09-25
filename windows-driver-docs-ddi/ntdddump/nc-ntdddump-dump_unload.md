# DUMP_UNLOAD callback function

## Description

The *Dump_Unload* callback routine is called when the dump stack is unloaded. For the dump stack, this routine is called when the crash dump functionality is disabled. For the hibernation stack, this routine is called after the system resumes from hibernation. This gives the filter driver an opportunity to free any resources that it may have allocated or do any clean-up required by the filter driver.

## Parameters

### `FilterExtension` [in]

A pointer to a [FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension) structure.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in *Ntstatus.h*.

## See also

[FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension)