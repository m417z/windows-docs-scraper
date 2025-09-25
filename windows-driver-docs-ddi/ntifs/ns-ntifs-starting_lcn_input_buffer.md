## Description

The **STARTING_LCN_INPUT_BUFFER** structure contains the starting logical cluster number (LCN) for the [**FSCTL_GET_VOLUME_BITMAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_volume_bitmap).
control code.

## Members

### `StartingLcn`

The LCN from which the operation should start when describing a bitmap. This member will be rounded down to a file-system-dependent rounding boundary, and that value will be returned. Its value should be an integral multiple of eight.

## See also

[**FSCTL_GET_VOLUME_BITMAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_volume_bitmap)