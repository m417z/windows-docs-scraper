# IMediaParams::FlushEnvelope

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FlushEnvelope` method flushes envelope data for a specified parameter over the specified time range.

## Parameters

### `dwParamIndex` [in]

Zero-based index of the parameter, or DWORD_ALLPARAMS to flush envelope data from every parameter.

### `refTimeStart` [in]

Start time of the envelope data to flush.

### `refTimeEnd` [in]

Stop time of the envelope data to flush.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **S_OK** | Success. |

## Remarks

If the time span specified by *refTimeStart* and *refTimeEnd* overlaps an envelope segment, the entire segment is flushed. On the other hand, if it falls on the boundary of an envelope segment, the entire segment is retained. Thus:

* If the start time falls inside an envelope segment, the segment is flushed.
* If the end time falls inside an envelope segment, the segment is flushed.
* If the start time equals the end time of an envelope segment, the segment is retained.
* If the end time equals the start time of an envelope segment, the segment is retained.

To enumerate the parameters supported by this object, along with their index values, use the [IMediaParamInfo](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo) interface.

## See also

[IMediaParams Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparams)