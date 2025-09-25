# IAMMediaTypeSample::SetTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `SetTime` method sets the stream times at which the sample should start and stop.

## Parameters

### `pTimeStart` [in]

Pointer to a variable that contains the start time.

### `pTimeEnd` [in]

Pointer to a variable that contains the stop time.

## Return value

Returns S_OK.

## See also

[IAMMediaTypeSample Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediatypesample)