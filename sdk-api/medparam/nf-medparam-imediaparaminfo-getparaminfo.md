# IMediaParamInfo::GetParamInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetParamInfo` method retrieves information about a specified parameter.

## Parameters

### `dwParamIndex` [in]

Zero-based index of the parameter.

### `pInfo` [out]

Pointer to an [MP_PARAMINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/medparam/ns-medparam-mp_paraminfo) structure that is filled with the parameter information.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

Call the [GetParamCount](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparaminfo-getparamcount) method to retrieve the number of parameters that the object supports.

## See also

[IMediaParamInfo Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo)