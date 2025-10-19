# IAMAsyncReaderTimestampScaling::SetTimestampMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the filter's time-stamping mode.

## Parameters

### `fRaw` [in]

Specifies the units for the source filter's time stamps.

| Value | Meaning |
| --- | --- |
| **TRUE** | Time stamps are in units of bytes. |
| **FALSE** | Time stamps are in units of bytes × 10000000. To get the offset in bytes, divide the sample time by 10000000. |

The default value is **FALSE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To support large files (greater than 850 GB), the downstream parser filter can call this method with the value **TRUE**. For backward compatibility, the default setting is **FALSE**. Call the method when the pins connect.

Applications should never call this method; doing so will cause the parser filter to misinterpret the time stamps.

## See also

[IAMAsyncReaderTimestampScaling](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamasyncreadertimestampscaling)