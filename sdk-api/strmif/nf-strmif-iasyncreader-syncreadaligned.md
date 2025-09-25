# IAsyncReader::SyncReadAligned

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SyncReadAligned` method performs a synchronous read. The method blocks until the request is completed. The file positions and the buffer address must be aligned; check the allocator properties for the required alignment.

## Parameters

### `pSample`

Pointer to the [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface of a media sample provided by the caller.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **VFW_E_BADALIGN** | Invalid alignment. |
| **S_FALSE** | Retrieved fewer bytes than requested. (Probably the end of the file was reached.) |
| **S_OK** | Success. |

## Remarks

Before calling this method, retrieve a media sample from the pin's allocator. Time stamp the sample with the byte offsets you are requesting, first and last inclusive, multiplied by 10,000,000. Byte offsets are relative to the start of the stream.

The start and stop positions should match the alignment that was decided when the pins connected. Otherwise, the method returns VFW_E_BADALIGN. If the agreed alignment is coarser than the actual alignment of the stream, the stop position might exceed the real duration. If so, the method rounds the stop position down to the actual alignment.

This method performs an unbuffered read, so it might be faster than the [IAsyncReader::SyncRead](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iasyncreader-syncread) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)