# IMediaParams::SetParam

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetParam` method sets the value of a parameter.

## Parameters

### `dwParamIndex` [in]

Zero-based index of the parameter, or DWORD_ALLPARAMS to apply the value to every parameter.

### `value` [in]

New value of the parameter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range, or illegal parameter value. |
| **S_OK** | Success. |

## Remarks

If the parameter is currently within an envelope segment, the envelope segment will overwrite the new value. To remove an envelope segment, call the [FlushEnvelope](https://learn.microsoft.com/windows/desktop/api/medparam/nf-medparam-imediaparams-flushenvelope) method.

To enumerate the parameters supported by this object, along with their index values, use the [IMediaParamInfo](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparaminfo) interface.

## See also

[IMediaParams Interface](https://learn.microsoft.com/windows/desktop/api/medparam/nn-medparam-imediaparams)