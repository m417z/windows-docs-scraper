# IAMAsyncReaderTimestampScaling::GetTimestampMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the filter's time-stamping mode.

## Parameters

### `pfRaw` [out]

Receives a Boolean value.

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Time stamps are in units of bytes. |
| ****FALSE**** | Time stamps are in units of bytes × 10000000. To get the offset in bytes, divide the sample time by 10000000. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAMAsyncReaderTimestampScaling](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamasyncreadertimestampscaling)