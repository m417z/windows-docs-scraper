# WOF_FILE_COMPRESSION_INFO_V1 structure

## Description

 Defines metadata specific to files provided by WOF_PROVIDER_FILE.

## Members

### `Algorithm`

Specifies the compression algorithm that is used to compress this file. Currently defined algorithms are:

|  |  |
| --- | --- |
| FILE_PROVIDER_COMPRESSION_XPRESS4K | Indicates that the data for the file should be compressed in 4kb chunks with the XPress algorithm. This algorithm is designed to be computationally lightweight, and provides for rapid access to data. |
| FILE_PROVIDER_COMPRESSION_LZX | Indicates that the data for the file should be compressed in 32kb chunks with the LZX algorithm. This algorithm is designed to be highly compact, and provides for small footprint for infrequently accessed data. |
| FILE_PROVIDER_COMPRESSION_XPRESS8K | Indicates that the data for the file should be compressed in 8kb chunks with the XPress algorithm. |
| FILE_PROVIDER_COMPRESSION_XPRESS16K | Indicates that the data for the file should be compressed in 16kb chunks with the XPress algorithm. |

### `Flags`

Specifies flags for the operation. Reserved for future use, should be 0.