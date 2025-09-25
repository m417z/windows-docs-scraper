## Description

The **REFS_VOLUME_DATA_BUFFER_CONTAINS_DRIVER_VERSION** macro determines whether a [**REFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-refs_volume_data_buffer) structure contains valid driver version information.

## Parameters

### `VOLUME_DATA_BUFFER`

Pointer to a [**REFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-refs_volume_data_buffer) structure that is being checked for the presence of driver version fields.

## Remarks

This macro helps maintain compatibility with different versions of the [**REFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-refs_volume_data_buffer) structure, especially when new fields are added in later versions.

## See also

[**REFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-refs_volume_data_buffer)