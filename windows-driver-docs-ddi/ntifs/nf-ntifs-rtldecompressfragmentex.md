# RtlDecompressFragmentEx function

## Description

The **RtlDecompressFragmentEx** function is used to decompress part of a compressed buffer (that is, a buffer "fragment"), using multiple processors where possible.

## Parameters

### `CompressionFormat` [in]

Bitmask specifying the compression format of the compressed buffer. This parameter must be set to COMPRESSION_FORMAT_LZNT1. The meaning of this and other related compression format values are as follows:

| Value | Meaning |
| ----- | ------- |
| COMPRESSION_FORMAT_NONE | Not supported by this function. |
| COMPRESSION_FORMAT_DEFAULT | Not supported by this function. |
| COMPRESSION_FORMAT_LZNT1 | Specifies that compression should be performed. This value is required. |

### `UncompressedFragment` [out]

Pointer to a caller-allocated buffer (allocated from paged or non-paged pool) receiving the decompressed data from **CompressedBuffer**. This parameter is required and cannot be NULL.

### `UncompressedFragmentSize` [in]

The size, in bytes, of the **UncompressedFragment** buffer.

### `CompressedBuffer` [in]

A pointer to the buffer containing the data to decompress. This parameter is required and cannot be NULL.

### `CompressedBufferSize` [in]

The size, in bytes, of the **CompressedBuffer** buffer.

### `FragmentOffset` [in]

The zero-based offset, in bytes, where the uncompressed fragment is being extract from. This offset value is the position within the original uncompressed buffer.

### `UncompressedChunkSize` [in]

The size, in bytes, of each chunk within the compression buffer. Valid values are 512, 1024, 2048 and 4096.

### `FinalUncompressedSize` [out]

A pointer to a caller-allocated variable which receives the size, in bytes, of the decompressed data stored in **UncompressedFragment**. This parameter is required and cannot be NULL.

### `WorkSpace` [in]

A pointer to a caller-allocated work space buffer used by the **RtlDecompressFragmentEx** function during decompression. Use the [**RtlGetCompressionWorkSpaceSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetcompressionworkspacesize) function to determine the correct work space buffer size.

## Return value

**RtlDecompressFragmentEx** returns an appropriate NTSTATUS code, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The **CompressedBuffer** buffer was successfully decompressed into **UncompressedFragment**. |
| STATUS_INVALID_PARAMETER | An invalid compression format was specified via the **CompressionFormat** parameter. If **CompressionFormat** is either COMPRESSION_FORMAT_NONE or COMPRESSION_FORMAT_DEFAULT (but not both), this value is returned. |
STATUS_UNSUPPORTED_COMPRESSION | An invalid compression format was specified via the **CompressionFormat** parameter. If **CompressionFormat** is not one of the following, STATUS_UNSUPPORTED_COMPRESSION is returned: COMPRESSION_FORMAT_LZNT1 |
| STATUS_BAD_COMPRESSION_BUFFER | **UncompressedFragment** is not large enough to contain the uncompressed data. |

## See also

[**FILE_COMPRESSION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_compression_information)

[**RtlCompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcompressbuffer)

[**RtlDecompressBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbuffer)

[**RtlDecompressBufferEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbufferex)

[**RtlDecompressBufferEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressbufferex2)

[**RtlDecompressFragment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldecompressfragment)