# NTFS_VOLUME_DATA_BUFFER structure

## Description

Represents volume data. This structure is passed to the
[FSCTL_GET_NTFS_VOLUME_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data) control code.

## Members

### `VolumeSerialNumber`

The serial number of the volume. This is a unique number assigned to the volume media by the operating system.

### `NumberSectors`

The number of sectors in the specified volume.

### `TotalClusters`

The number of used and free clusters in the specified volume.

### `FreeClusters`

The number of free clusters in the specified volume.

### `TotalReserved`

The number of reserved clusters in the specified volume.

### `BytesPerSector`

The number of bytes in a sector on the specified volume.

### `BytesPerCluster`

The number of bytes in a cluster on the specified volume. This value is also known as the cluster factor.

### `BytesPerFileRecordSegment`

The number of bytes in a file record segment.

### `ClustersPerFileRecordSegment`

The number of clusters in a file record segment.

### `MftValidDataLength`

The length of the master file table, in bytes.

### `MftStartLcn`

The starting logical cluster number of the master file table.

### `Mft2StartLcn`

The starting logical cluster number of the master file table mirror.

### `MftZoneStart`

The starting logical cluster number of the master file table zone.

### `MftZoneEnd`

The ending logical cluster number of the master file table zone.

## Remarks

Reserved clusters are the free clusters reserved for later use by Windows.

The **NTFS_VOLUME_DATA_BUFFER** structure represents the basic information returned by [FSCTL_GET_NTFS_VOLUME_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data). For extended volume information, pass a buffer that is the combined size of the **NTFS_VOLUME_DATA_BUFFER** and **NTFS_EXTENDED_VOLUME_DATA** structures. Upon success, the buffer returned by **FSCTL_GET_NTFS_VOLUME_DATA** will contain the information associated with both structures. The **NTFS_VOLUME_DATA_BUFFER** structure will always be filled starting at the beginning of the buffer, with the **NTFS_EXTENDED_VOLUME_DATA** structure immediately following. The **NTFS_EXTENDED_VOLUME_DATA** structure is defined as follows:

| C++ |
| --- |
| ``` typedef struct {     ULONG ByteCount;     USHORT MajorVersion;     USHORT MinorVersion; } NTFS_EXTENDED_VOLUME_DATA, *PNTFS_EXTENDED_VOLUME_DATA; ``` |

This structure contains the major and minor version information for an NTFS volume. The **ByteCount** member will return the total bytes of the output buffer used for this structure by the call to [FSCTL_GET_NTFS_VOLUME_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data). This value should be `sizeof(NTFS_EXTENDED_VOLUME_DATA)` if the buffer passed was large enough to hold it, otherwise the value will be less than `sizeof(NTFS_EXTENDED_VOLUME_DATA)`.

## See also

[FSCTL_GET_NTFS_VOLUME_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_ntfs_volume_data)