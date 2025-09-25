# IMFByteStream::Seek

## Description

Moves the current position in the stream by a specified offset.

## Parameters

### `SeekOrigin` [in]

Specifies the origin of the seek as a member of the [MFBYTESTREAM_SEEK_ORIGIN](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfbytestream_seek_origin) enumeration. The offset is calculated relative to this position.

### `llSeekOffset` [in]

Specifies the new position, as a byte offset from the seek origin.

### `dwSeekFlags` [in]

Specifies zero or more flags. The following flags are defined.

| Value | Meaning |
| --- | --- |
| **MFBYTESTREAM_SEEK_FLAG_CANCEL_PENDING_IO** | All pending I/O requests are canceled after the seek request completes successfully. |

### `pqwCurrentPosition` [out]

Receives the new position after the seek.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

 **Implementation notes:** This method should update the current position in the stream by adding the *qwSeekOffset* to the seek *SeekOrigin* position. This should be the same value passed back in the *pqwCurrentPosition* parameter.
Other methods that can update the current position are [Read](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-read), [BeginRead](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginread), [Write](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-write), [BeginWrite](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-beginwrite), and [SetCurrentPosition](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfbytestream-setcurrentposition).

## See also

[IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream)