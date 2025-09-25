# IMFSourceBuffer::AppendByteStream

## Description

Appends the media segment from the specified byte stream to the [IMFSourceBuffer](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfsourcebuffer).

## Parameters

### `pStream` [in]

The media segment data.

### `pMaxLen` [in]

The maximum length of the media segment data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSourceBuffer](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfsourcebuffer)