# _FILE_COMPRESSION_INFORMATION structure

## Description

The FILE_COMPRESSION_INFORMATION structure describes the state of a compressed data buffer.

## Members

### `CompressedFileSize`

The size, in bytes, of the compressed file.

### `CompressionFormat`

The compression format. This member must have one of the following values:

| Value | Meaning |
| --- | --- |
| COMPRESSION_FORMAT_NONE | No compression format. |
| COMPRESSION_FORMAT_DEFAULT | Default compression format. |
| COMPRESSION_FORMAT_LZNT1 | LZNT1 compression format. |

### `CompressionUnitShift`

The log, base 2, of the number of clusters per compression

unit. In the NTFS file system, this value is NTFS_CLUSTERS_PER_COMPRESSION.

### `ChunkShift`

The log, base 2, of the number of bytes in a chunk. In other words, the size in bytes of the chunk is 2 ** **ChunkShift**, or (1 << **ChunkShift**).

### `ClusterShift`

The log, base 2, of the minimum number of clusters by which compression must reduce the size of the compression unit. If compression does not reduce the size of the compression unit by at least 2 ** **ClusterShift** clusters (or 1 << **ClusterShift** clusters), compression will not occur. Each compression unit must occupy at least one cluster less than the uncompressed data would occupy.

### `Reserved`

Reserved

## See also

[FLT_PARAMETERS for IRP_MJ_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-information)

[FltQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryinformationfile)

[IRP_MJ_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information)