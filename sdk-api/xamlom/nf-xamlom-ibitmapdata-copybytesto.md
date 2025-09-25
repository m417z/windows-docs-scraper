# IBitmapData::CopyBytesTo

## Description

Copies up to the specified maximum number of bytes from the given offset in the bitmap data into the caller’s buffer (*pvBytes*), and returns the number of bytes copied.

## Parameters

### `sourceOffsetInBytes` [in]

The place in the bitmap data to start copying from, in bytes.

### `maxBytesToCopy` [in]

The maximum number of bytes to copy.

### `pvBytes` [out]

The buffer into which the bytes are copied.

### `numberOfBytesCopied` [out]

The number of bytes copied.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBitmapData](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ibitmapdata)