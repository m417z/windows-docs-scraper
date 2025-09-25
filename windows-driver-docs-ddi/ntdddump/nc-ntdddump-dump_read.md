# DUMP_READ callback function

## Description

The *Dump_Read* callback routine is called after the read from the dump port driver. The filter driver can access the dump data during the call to this routine.

## Parameters

### `FilterExtension` [in]

A pointer to a [FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension) structure.

### `DiskByteOffset` [in]

The value, in bytes, relative to the source partition for the crash dump or hibernation. Filter drivers should not modify this field.

### `Mdl` [in]

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the data buffer containing the dump data. Filter drivers should not modify this field.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in *Ntstatus.h*.

## Remarks

Filter drivers can read the data that was read by the crashdump process.

Filter drivers can modify the contents of the data buffer contained in **Mdl** to revert any changes made to the data when it was written to disk.

## See also

[Dump_Write](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/nc-ntdddump-dump_write)

[FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension)