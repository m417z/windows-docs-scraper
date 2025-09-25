# IStreamInterleave::Initialize

## Description

Initialize this interleaved stream from an array of input streams and interleave sizes.

## Parameters

### `streams` [in]

Array of **IStream** interfaces of the streams to add to this stream.

### `interleaveSizes` [in]

Array of interleave sizes, in bytes, with one entry per stream. The interleave size array is the number of contiguous bytes of a given stream to write on the disc before writing starts for the next stream.

### `streamCount` [in]

Number of streams in *streams*.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## See also

[IStreamInterleave](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-istreaminterleave)