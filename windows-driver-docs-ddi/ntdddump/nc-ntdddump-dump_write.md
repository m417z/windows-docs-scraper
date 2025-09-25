# DUMP_WRITE callback function

## Description

The *Dump_Write* callback routine is called before the write to the dump port driver. The filter driver can access the dump data at this time.

## Parameters

### `FilterExtension` [in]

A pointer to a [FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension) structure.

### `DiskByteOffset` [in, out]

The value, in bytes, relative to the destination partition for the crash dump or hibernation. Filter drivers should not modify this field.

### `Mdl` [in, out]

A pointer to an [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) structure that describes the data buffer. If the **MDL** is modified, the size of the write operation cannot change.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in *Ntstatus.h*.

## Remarks

Filter drivers can read the data that needs to be written. However, filter drivers cannot write to the buffer, as this could change the contents of the code or data that is being used by the crash dump process. Also, filter drivers are not allowed to change the size of the data.

To safely modify the data for the dump write, a filter driver should allocate a secondary buffer. The buffer's size will be the value of the **MaxPagesPerWrite** member of [FILTER_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_initialization_data) multiplied by **PAGE_SIZE**. The data for the current buffer described by *Mdl* is copied into the secondary buffer and processed. After the filter is finished handling the dump data in the secondary buffer, the [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) pointed to by *Mdl* is updated with the address of the secondary buffer. The starting address of the secondary buffer set in the **MDL** must be page aligned.

## See also

[Dump_Read](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/nc-ntdddump-dump_read)

[FILTER_EXTENSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_extension)

[FILTER_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddump/ns-ntdddump-_filter_initialization_data)