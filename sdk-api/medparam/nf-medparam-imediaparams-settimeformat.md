# IMediaParams::SetTimeFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTimeFormat` method specifies the time format for the object.

## Parameters

### `guidTimeFormat` [in]

Time format GUID that specifies the time format.

### `mpTimeData` [in]

Value of type **MP_TIMEDATA** that specifies the unit of measure for the new format.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Object does not support this time format. |
| **S_OK** | Success. |

## Remarks

Objects can support more than one time format. Every object must support reference time, in which each unit of time is 100 nanoseconds (ns). Other formats are optional. The application must ensure that time stamps on the input buffers match whatever time format was set using this method.

The meaning of the *mpTimeData* parameter depends on the value of the *guidTimeFormat* parameter.

| Time Format | Meaning of Time Data |
| --- | --- |
| GUID_TIME_MUSIC | Parts per quarter note. |
| GUID_TIME_REFERENCE | Ignored. |
| GUID_TIME_SAMPLES | Samples per second. |

When you call this method, also call the [FlushEnvelope](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparams-flushenvelope) method, to flush any envelopes that were set using the previous time format.

To determine what time formats an object supports, call the [IMediaParamInfo::GetSupportedTimeFormat](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparaminfo-getsupportedtimeformat) method. To retrieve the current format, call the [IMediaParamInfo::GetCurrentTimeFormat](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparaminfo-getcurrenttimeformat) method.

## See also

[IMediaParams Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparams)

[Time Format GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/time-format-guids)