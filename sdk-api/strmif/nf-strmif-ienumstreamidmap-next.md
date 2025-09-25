# IEnumStreamIdMap::Next

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Next` method retrieves the next *n* elements in the collection.

## Parameters

### `cRequest` [in]

The number of elements to retrieve.

### `pStreamIdMap` [in, out]

Address of a user-allocated array containing *cRequest* elements that will receive the retrieved [STREAM_ID_MAP](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-stream_id_map) structures.

### `pcReceived` [out]

Receives the number of elements actually retrieved.

## Return value

Returns S_OK if successful. If the method fails,an **HRESULT** error code is returned.

## Remarks

If *cRequest* >= 0 and *pcReceived* is not **NULL**, upon return *pcReceived* contains the number of stream ID maps remaining in the collection.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumStreamIdMap Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumstreamidmap)