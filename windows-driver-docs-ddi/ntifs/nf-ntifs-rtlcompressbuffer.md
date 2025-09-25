# RtlCompressBuffer function

## Description

The **RtlCompressBuffer** function compresses a buffer and can be used by a file system driver to facilitate the implementation of file compression.

## Parameters

### `CompressionFormatAndEngine` [in]

A bitmask that specifies the compression format and engine type. This parameter must be set to a valid bitwise OR combination of one format type and one engine type. For example, COMPRESSION_FORMAT_LZNT1 | COMPRESSION_ENGINE_STANDARD.

The meanings of these, and other related values, are as follows.

| Value | Meaning |
| ----- | ------- |
| COMPRESSION_FORMAT_NONE | Not supported by this function. |
| COMPRESSION_FORMAT_DEFAULT | Not supported by this function. |
| COMPRESSION_FORMAT_LZNT1 | The function will perform LZ compression. |
| COMPRESSION_FORMAT_XPRESS | The function will perform Xpress compression. |
| COMPRESSION_FORMAT_XPRESS_HUFF | The function will perform Xpress Huffman compression. |
| COMPRESSION_ENGINE_STANDARD | The **UncompressedBuffer** buffer is compressed using an algorithm that provides a balance between data compression and performance. This value cannot be used with COMPRESSION_ENGINE_MAXIMUM. |
| COMPRESSION_ENGINE_MAXIMUM | The **UncompressedBuffer** buffer is compressed using an algorithm that provides maximum data compression but with relatively slower performance. This value cannot be used with COMPRESSION_ENGINE_STANDARD. |
| COMPRESSION_ENGINE_HIBER | Not supported by this function. |

### `UncompressedBuffer` [in]

A pointer to a caller-allocated buffer (allocated from paged or non-paged pool) that contains the data to be compressed. This parameter is required and cannot be NULL.

### `UncompressedBufferSize` [in]

The size, in bytes, of the **UncompressedBuffer** buffer.

### `CompressedBuffer` [out]

A pointer to a caller-allocated buffer (allocated from paged or non-paged pool) that receives the compressed data. This parameter is required and cannot be NULL.

### `CompressedBufferSize` [in]

The size, in bytes, of the **CompressedBuffer** buffer.

### `UncompressedChunkSize` [in]

The chunk size to use when compressing the **UncompressedBuffer** buffer. This parameter must be one of the following values: 512, 1024, 2048, or 4096. The operating system uses 4096, and the recommended value for this parameter is also 4096.

### `FinalCompressedSize` [out]

A pointer to a caller-allocated variable that receives the size, in bytes, of the compressed data stored in **CompressedBuffer**. This parameter is required and cannot be NULL.

### `WorkSpace` [in]

A pointer to a caller-allocated work space buffer used by the **RtlCompressBuffer** function during compression. Use the [**RtlGetCompressionWorkSpaceSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetcompressionworkspacesize) function to determine the correct work space buffer size.

## Return value

**RtlCompressBuffer** returns an appropriate error status value, such as one of the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The **UncompressedBuffer** buffer was successfully compressed. |
| STATUS_BUFFER_ALL_ZEROS | The **UncompressedBuffer** buffer was successfully compressed, but this buffer contains only zeros. |
| STATUS_INVALID_PARAMETER | An invalid compression format was specified through the **CompressionFormat** parameter. If **CompressionFormat** is either COMPRESSION_FORMAT_NONE or COMPRESSION_FORMAT_DEFAULT (but not both), this value is returned. |
| STATUS_UNSUPPORTED_COMPRESSION | An invalid compression format was specified through the **CompressionFormat** parameter. If **CompressionFormat** is not one of the following, STATUS_UNSUPPORTED_COMPRESSION is returned: COMPRESSION_FORMAT_LZNT1, COMPRESSION_FORMAT_XPRESS, COMPRESSION_FORMAT_XPRESS_HUFF |
| STATUS_NOT_SUPPORTED | An invalid compression engine was specified through the **CompressionFormatAndEngine** parameter. If **CompressionFormatAndEngine** is not COMPRESSION_ENGINE_STANDARD or COMPRESSION_ENGINE_MAXIMUM (but not both), this value is returned. |
| STATUS_BUFFER_TOO_SMALL | The compressed buffer is too small to hold the compressed data. That is, **FinalCompressedSize** is greater than **CompressedBufferSize**. |

## Remarks

The **RtlCompressBuffer** function takes as input an uncompressed buffer and produces its compressed equivalent provided that the compressed data fits within the specified destination buffer.

To determine the correct buffer size for the **WorkSpace** parameter, use the [**RtlGetCompressionWorkSpaceSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetcompressionworkspacesize) function.

To decompress a compressed buffer, use the [**RtlDecompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbuffer) function.

To extract an uncompressed fragment from a compressed buffer, use the [**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment) function.

## See also

[**FILE_COMPRESSION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_compression_information)

[**RtlDecompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbuffer)

[**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment)

[**RtlGetCompressionWorkSpaceSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetcompressionworkspacesize)