# IMediaParamInfo::GetCurrentTimeFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentTimeFormat` method retrieves the current time format.

## Parameters

### `pguidTimeFormat` [out]

Pointer to a variable that receives a time format GUID.

### `pTimeData` [out]

Pointer to a variable that receives an **MP_TIMEDATA** value specifying the unit of measure for the new format.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

The meaning of the value returned in the *pTimeData* parameter depends on the time format GUID. For more information, see [IMediaParams::SetTimeFormat](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparams-settimeformat).

## See also

[IMediaParamInfo Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo)