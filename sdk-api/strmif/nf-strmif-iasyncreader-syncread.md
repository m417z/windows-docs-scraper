# IAsyncReader::SyncRead

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SyncRead` method performs a synchronous read. The method blocks until the request is completed. The file positions and the buffer address do not have to be aligned. If the request is not aligned, the method performs a buffered read operation.

## Parameters

### `llPosition` [in]

Specifies the byte offset at which to begin reading. The method fails if this value is beyond the end of the file.

### `lLength` [in]

Specifies the number of bytes to read.

### `pBuffer` [out]

Pointer to a buffer that receives the data.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Retrieved fewer bytes than requested. (Probably the end of the file was reached.) |
| **S_OK** | Success. |

## Remarks

This method works even if the filter is stopped.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)

[IAsyncReader::SyncReadAligned](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-syncreadaligned)