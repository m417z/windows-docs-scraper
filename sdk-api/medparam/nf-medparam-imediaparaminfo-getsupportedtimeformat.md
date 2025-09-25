# IMediaParamInfo::GetSupportedTimeFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetSupportedTimeFormat` method retrieves a supported time format.

## Parameters

### `dwFormatIndex` [in]

Index of the time format to retrieve.

### `pguidTimeFormat` [out]

Pointer to a variable that receives a time format GUID.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

Call the [GetNumTimeFormats](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparaminfo-getnumtimeformats) method to retrieve the number of time formats that the object supports.

## See also

[IMediaParamInfo Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo)

[Time Format GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/time-format-guids)