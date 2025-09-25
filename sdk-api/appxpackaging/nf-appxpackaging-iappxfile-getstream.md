# IAppxFile::GetStream

## Description

Gets a read-only stream that contains the uncompressed content of the file.

## Parameters

### `stream` [out, retval]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

A read-only stream that contains the uncompressed content of the file.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**.

[Fatal] OPC error codes (0x8051xxxx) if the file’s local file header or data descriptor in the zip archive is invalid. This failure causes the entire OPC zip consumer to enter an invalid state, no other file can be accessed from the [IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader) object after this error occurs.

HRESULT_FROM_WIN32(ERROR_CRC) (0x80070017) if the stream has been previously read and its CRC was invalid.

**Return value from the returned IStream’s Read and CopyTo methods**

[Fatal] HRESULT_FROM_WIN32(ERROR_CRC) (0x80070017) if the entire stream has been read and its CRC is found to be invalid

APPX_E_CORRUPT_CONTENT (0x80080206) if the file content can't be decompressed (due to corruption of the zip file)

HRESULT_FROM_WIN32(ERROR_INVALID_DATA) (0x8007000d) if a block in the file can't be read completely or the size of the block is unexpected

APPX_E_BLOCK_HASH_INVALID (0x80080207) if the content of this file’s blocks is inconsistent with its hash in the block map

## Remarks

The *stream* returned is read-only and cloneable.

Validation of payload files is "lazy." On the first call to the file’s **GetStream** method, the corresponding zip file item’s local file header and data descriptor is validated and might cause **GetStream** to fail. Subsequent calls to **GetStream** on the same file don't repeat these validations. The zip file item’s CRC checksum is only validated if the stream is read in its entirety in sequential order.

Instances of [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that are returned for payload files are optimized for sequential access. While random access to the stream is supported, that random access might be slower and more CPU-intensive. We recommend a single sequential read of these streams whenever possible. Reading the same range multiple times is supported but not recommended for performance; consider caching such ranges if their usage scenario demands it.

## See also

[IAppxFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfile)

[IAppxPackageReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagereader)