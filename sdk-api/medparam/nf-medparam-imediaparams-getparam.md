# IMediaParams::GetParam

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetParam` method retrieves the current value of the specified parameter. If the parameter is currently within an envelope segment, the returned value is the value on the most recently processed sample.

## Parameters

### `dwParamIndex` [in]

Zero-based index of the parameter.

### `pValue` [out]

Pointer to a variable of type **MP_DATA** that receives the parameter value.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

To enumerate the parameters supported by this object, along with their index values, use the [IMediaParamInfo](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo) interface.

## See also

[IMediaParams Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparams)