## Description

The **NTFS_EXTENDED_VOLUME_DATA** structure contains extended information about an NTFS volume. It's used with the [**FSCTL_GET_NTFS_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_volume_data) control code.

## Members

### `ByteCount`

Total bytes of the structure.

### `MajorVersion`

Major version for an NTFS volume.

### `MinorVersion`

Minor version for an NTFS volume.

### `BytesPerPhysicalSector`

Number of bytes per physical sector on the device.

### `LfsMajorVersion`

Major version of the Log File Service (LFS) used by NTFS.

### `LfsMinorVersion`

Minor version of the LFS used by NTFS.

### `MaxDeviceTrimExtentCount`

Maximum number of trim extents that the device can handle in a single trim operation.

### `MaxDeviceTrimByteCount`

Maximum number of bytes that can be trimmed in a single device trim operation.

### `MaxVolumeTrimExtentCount`

Maximum number of trim extents that the volume can handle in a single trim operation.

### `MaxVolumeTrimByteCount`

Maximum number of bytes that can be trimmed in a single volume trim operation.

## See also

[**FSCTL_GET_NTFS_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_volume_data)

[**NTFS_VOLUME_DATA_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_volume_data_buffer)