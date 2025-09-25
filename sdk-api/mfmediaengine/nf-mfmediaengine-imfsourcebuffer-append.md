# IMFSourceBuffer::Append

## Description

Appends the specified media segment to the [IMFSourceBuffer](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfsourcebuffer).

## Parameters

### `pData` [in]

The media data to append.

### `len` [in]

The length of the media data stored in *pData*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSourceBuffer](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfsourcebuffer)