# STARTING_LCN_INPUT_BUFFER structure

## Description

Contains the starting LCN to the
[FSCTL_GET_VOLUME_BITMAP](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_volume_bitmap) control code.

## Members

### `StartingLcn`

The LCN from which the operation should start when describing a bitmap. This member will be rounded down to a file-system-dependent rounding boundary, and that value will be returned. Its value should be an integral multiple of eight.

## See also

[Defragmentation](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files)

[FSCTL_GET_VOLUME_BITMAP](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_volume_bitmap)