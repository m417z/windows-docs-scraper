## Description

The **REFS_VOLUME_DATA_BUFFER** structure contains information about an ReFS volume.

## Members

### `ByteCount`

Size in bytes of this structure.

### `MajorVersion`

Major version number of the ReFS volume.

### `MinorVersion`

Minor version number of the ReFS volume.

### `BytesPerPhysicalSector`

Number of bytes per physical sector on the volume.

### `VolumeSerialNumber`

Unique serial number of the volume.

### `NumberSectors`

Total number of sectors on the volume.

### `TotalClusters`

Total number of clusters on the volume.

### `FreeClusters`

Number of free clusters available on the volume.

### `TotalReserved`

Total number of reserved clusters on the volume.

### `BytesPerSector`

Number of bytes per sector.

### `BytesPerCluster`

Number of bytes per cluster.

### `MaximumSizeOfResidentFile`

Maximum size of a file that can reside entirely within a single cluster.

### `FastTierDataFillRatio`

Fill ratio for the fast tier, expressed as a value between 0 and 10000.

### `SlowTierDataFillRatio`

Fill ratio for the slow tier, expressed as a value between 0 and 10000.

### `DestagesFastTierToSlowTierRate`

Rate at which data is destaged from the fast tier to the slow tier, measured in clusters per second.

### `MetadataChecksumType`

Type of checksum used for metadata.

### `Reserved0[6]`

Reserved0: Reserved for future use.

### `DriverMajorVersion`

Major version number of the file system driver.

### `DriverMinorVersion`

Minor version number of the file system driver.

### `Reserved[7]`

Reserved for future use.

## Remarks

## See also

[**FSCTL_GET_REFS_VOLUME_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_get_refs_volume_data)