# RtlGetCompressionWorkSpaceSize function

## Description

The **RtlGetCompressionWorkSpaceSize** function is used to determine the correct size of the **WorkSpace** buffer for the [**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer) and [**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment) functions.

## Parameters

### `CompressionFormatAndEngine` [in]

Bitmask specifying the compression format and engine type. This parameter must be set to a valid bitwise OR combination of one format type and one engine type. For example, COMPRESSION_FORMAT_LZNT1 | COMPRESSION_ENGINE_STANDARD.

The meanings of these, and other related values, are as follows:

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

### `CompressBufferWorkSpaceSize` [out]

A pointer to a caller-allocated buffer receiving the size, in bytes, required to compress a buffer. This value is used to determine the correct size of [**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer)'s **WorkSpace** buffer.

### `CompressFragmentWorkSpaceSize` [out]

A pointer to a caller-allocated buffer receiving the size, in bytes, required to decompress a compressed buffer to a fragment. This value is used to determine the correct size of [**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment)'s **WorkSpace** buffer. Note that the **RtlCompressFragment** function does not currently exist.

## Return value

**RtlGetCompressionWorkSpaceSize**returns an appropriate error status, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The required buffer sizes, in bytes, were successfully returned. |
| STATUS_INVALID_PARAMETER | An invalid compression format was specified via the **CompressionFormatAndEngine** parameter. If **CompressionFormatAndEngine** is either COMPRESSION_FORMAT_NONE or COMPRESSION_FORMAT_DEFAULT (but not both), this value is returned. |
| STATUS_UNSUPPORTED_COMPRESSION | An invalid compression format was specified via the **CompressionFormatAndEngine** parameter. If **CompressionFormatAndEngine** is not one of the following, STATUS_UNSUPPORTED_COMPRESSION is returned: COMPRESSION_FORMAT_LZNT1, COMPRESSION_FORMAT_XPRESS, COMPRESSION_FORMAT_XPRESS_HUF |
| STATUS_NOT_SUPPORTED | An invalid compression engine was specified via the **CompressionFormatAndEngine** parameter. If **CompressionFormatAndEngine** is not COMPRESSION_ENGINE_STANDARD or COMPRESSION_ENGINE_MAXIMUM (but not both), this value is returned. |

## Remarks

The [**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer) and [**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment) functions require an appropriately sized work space buffer to compress and decompress successfully. To determine the correct work space buffer size, in bytes, call the **RtlGetCompressionWorkSpaceSize** function.

As an example, the **WorkSpace** parameter of the [**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer) function must point to an adequately sized work space buffer. The **CompressBufferWorkSpaceSize** parameter of the **RtlGetCompressionWorkSpaceSize** provides this size.

To compress an uncompressed buffer, use the [**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer) function.

To decompress a compressed buffer, use the [**RtlDecompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbuffer) function.

To decompress only a portion of a compressed buffer (that is, a "fragment" of the buffer), use the [**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment) function.

## See also

[**FILE_COMPRESSION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_compression_information)

[**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer)

[**RtlDecompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbuffer)

[**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment)