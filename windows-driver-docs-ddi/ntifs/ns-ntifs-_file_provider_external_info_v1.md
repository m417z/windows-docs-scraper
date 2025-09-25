# FILE_PROVIDER_EXTERNAL_INFO_V1 structure

## Description

The **FILE_PROVIDER_EXTERNAL_INFO_V1** structure defines metadata specific to files provided by WOF_PROVIDER_FILE. This provider gives efficient compression for data that won't be modified, such as executable files. If the file is opened for write access, the file will be transparently decompressed.

## Members

### `Version`

The version of the provider to use. Specify FILE_PROVIDER_CURRENT_VERSION.

### `Algorithm`

Specifies the compression algorithm that is used to compress this file. Currently defined algorithms are:

| Algorithm | Description |
| --------- | ----------- |
| FILE_PROVIDER_COMPRESSION_XPRESS4K | The data for the file should be compressed in 4kb chunks with the XPress algorithm. This algorithm is designed to be computationally lightweight, and provides for rapid access to data. |
| FILE_PROVIDER_COMPRESSION_LZX | The data for the file should be compressed in 32kb chunks with the LZX algorithm. This algorithm is designed to be highly compact, and provides for small footprint for infrequently accessed data. |
| FILE_PROVIDER_COMPRESSION_XPRESS8K | The data for the file should be compressed in 8kb chunks with the XPress algorithm. |
| FILE_PROVIDER_COMPRESSION_XPRESS16K | The data for the file should be compressed in 16kb chunks with the XPress algorithm. |

### `Flags`

Specifies flags for the operation. Reserved for future use, should be 0.

## See also

[**FILE_PROVIDER_EXTERNAL_INFO_V0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_provider_external_info_v0)