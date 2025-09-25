# IAMMediaStream::JoinFilterGraph

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `JoinFilterGraph` method connects a media stream filter to a filter graph.

## Parameters

### `pFilterGraph` [in]

Pointer to the current media stream filter to add to the specified filter graph.

## Return value

Returns S_OK if successful or E_POINTER if *pGraph* is **NULL**.

## Remarks

Don't increment the reference count of the specified filter graph.

Applications should not call this method.

## See also

[IAMMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediastream)