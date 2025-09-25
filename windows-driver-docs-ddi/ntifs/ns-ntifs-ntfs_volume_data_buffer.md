## Description

The **NTFS_VOLUME_DATA_BUFFER** structure contains information about an NTFS volume. It's used with the [**FSCTL_GET_NTFS_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_volume_data) control code.

## Members

### `VolumeSerialNumber`

The serial number of the volume. This is a unique number assigned to the volume media by the operating system.

### `NumberSectors`

Number of sectors in the specified volume.

### `TotalClusters`

Number of used and free clusters in the specified volume.

### `FreeClusters`

Number of free clusters in the specified volume.

### `TotalReserved`

Number of reserved clusters in the specified volume.

### `BytesPerSector`

Number of bytes in a sector on the specified volume.

### `BytesPerCluster`

Number of bytes in a cluster on the specified volume. This value is also known as the cluster factor.

### `BytesPerFileRecordSegment`

Number of bytes in a file record segment.

### `ClustersPerFileRecordSegment`

Number of clusters in a file record segment.

### `MftValidDataLength`

Length of the master file table (MFT) in bytes.

### `MftStartLcn`

Starting logical cluster number (LCN) of the MFT.

### `Mft2StartLcn`

Starting LCN of the MFT mirror.

### `MftZoneStart`

Starting LCN of the MFT zone.

### `MftZoneEnd`

Ending LCN of the MFT zone.

## Remarks

Reserved clusters are the free clusters reserved for later use by Windows.

The **NTFS_VOLUME_DATA_BUFFER** structure represents the basic information returned by [**FSCTL_GET_NTFS_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_volume_data). For extended volume information, pass a buffer that is the combined size of the **NTFS_VOLUME_DATA_BUFFER** and [**NTFS_EXTENDED_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_extended_volume_data) structures. Upon success, the buffer returned by **FSCTL_GET_NTFS_VOLUME_DATA** will contain the information associated with both structures. The NTFS_VOLUME_DATA_BUFFER structure will always be filled starting at the beginning of the buffer, with the **NTFS_EXTENDED_VOLUME_DATA** structure immediately following.

## See also

[**FSCTL_GET_NTFS_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_ntfs_volume_data)

[**NTFS_EXTENDED_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-ntfs_extended_volume_data)