# RtlDecompressBuffer function

## Description

The **RtlDecompressBuffer** function decompresses an entire compressed buffer.

## Parameters

### `CompressionFormat` [in]

A bitmask that specifies the compression format of the compressed buffer. This parameter must be set to COMPRESSION_FORMAT_LZNT1. The meaning of this and other related compression format values are as follows.

| Value | Meaning |
| ----- | ------- |
| COMPRESSION_FORMAT_NONE | Not supported by this function. |
| COMPRESSION_FORMAT_DEFAULT | Not supported by this function. |
| COMPRESSION_FORMAT_LZNT1 | The function will perform LZ compression. |
| COMPRESSION_FORMAT_XPRESS | The function will perform Xpress compression. |

### `UncompressedBuffer` [out]

A pointer to a caller-allocated buffer (allocated from paged or non-paged pool) that receives the decompressed data from **CompressedBuffer**. This parameter is required and cannot be **NULL**.

### `UncompressedBufferSize` [in]

The size, in bytes, of the **UncompressedBuffer** buffer.

### `CompressedBuffer` [in]

A pointer to the buffer that contains the data to decompress. This parameter is required and cannot be **NULL**.

### `CompressedBufferSize` [in]

The size, in bytes, of the **CompressedBuffer** buffer.

### `FinalUncompressedSize` [out]

A pointer to a caller-allocated variable that receives the size, in bytes, of the decompressed data stored in **UncompressedBuffer**. This parameter is required and cannot be **NULL**.

## Return value

**RtlDecompressBuffer** returns an appropriate error status value, such as one of the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The **CompressedBuffer** buffer was successfully decompressed. |
| STATUS_INVALID_PARAMETER | An invalid compression format was specified through the **CompressionFormat** parameter. If **CompressionFormat** is either COMPRESSION_FORMAT_NONE or COMPRESSION_FORMAT_DEFAULT (but not both), this value is returned. |
| STATUS_UNSUPPORTED_COMPRESSION | An invalid compression format was specified through the **CompressionFormat** parameter. If **CompressionFormat** is not one of the following, STATUS_UNSUPPORTED_COMPRESSION is returned: COMPRESSION_FORMAT_LZNT1, COMPRESSION_FORMAT_XPRESS |
| STATUS_BAD_COMPRESSION_BUFFER | **UncompressedBuffer** is not large enough to contain the uncompressed data. |

## Remarks

The **RtlDecompressBuffer** function takes as input an entire compressed buffer and produces its decompressed equivalent provided that the uncompressed data fits within the specified destination buffer.

To decompress only a portion of a compressed buffer (that is, a "fragment" of the buffer), use the [**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment) function.

To compress an uncompressed buffer, use the [**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer) function.

## See also

[**FILE_COMPRESSION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_compression_information)

[**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer)

[**RtlDecompressBufferEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbufferex)

[**RtlDecompressBufferEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbufferex2)

[**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment)

[**RtlDecompressFragmentEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragmentex)