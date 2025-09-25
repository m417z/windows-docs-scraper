# CSV_NAMESPACE_INFO structure

## Description

Contains the output for the [FSCTL_IS_CSV_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_is_csv_file)
control code that retrieves namespace information for a file.

## Members

### `Version`

The version number. This value must be set to **CSV_NAMESPACE_INFO_V1**.

| Value | Meaning |
| --- | --- |
| **CSV_NAMESPACE_INFO_V1** | Version 1. |

### `DeviceNumber`

The device number of the disk.

### `StartingOffset`

The starting offset of the volume.

### `SectorSize`

The sector size of the disk.

## See also

[FSCTL_IS_CSV_FILE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_is_csv_file)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)