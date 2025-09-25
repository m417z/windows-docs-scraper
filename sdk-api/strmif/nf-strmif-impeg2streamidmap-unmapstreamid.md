# IMPEG2StreamIdMap::UnmapStreamId

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `UnmapStreamId` method unmaps the Stream ID mapping created in a previous call to **MapStreamId**.

## Parameters

### `culStreamId` [in]

The number of elements in the *pulStreamID* array.

### `pulStreamId` [in]

Array of Stream IDs mapped for this pin.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

There is typically only one stream ID mapped to a given pin, therefore *pulStreamID* will typically contain a single element.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2StreamIdMap Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-impeg2streamidmap)