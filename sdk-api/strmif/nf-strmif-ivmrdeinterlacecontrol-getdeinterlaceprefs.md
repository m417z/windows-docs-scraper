# IVMRDeinterlaceControl::GetDeinterlacePrefs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDeinterlacePrefs** method queries how the VMR will select a deinterlacing mode if it cannot use the preferred deinterlacing mode.

## Parameters

### `lpdwDeinterlacePrefs` [in]

Pointer to a variable that receives a member of the [VMRDeinterlacePrefs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmrdeinterlaceprefs) enumeration.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_VMR_NOT_IN_MIXER_MODE** | The VMR is not in mixer mode. |

## Remarks

By default, the preferred deinterlacing mode is the first mode reported by the driver. The application can set the preferred mode by calling the [IVMRDeinterlaceControl::SetDeinterlaceMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrdeinterlacecontrol-setdeinterlacemode) method. If the VMR cannot use the preferred mode, it will fall back to another mode as specified by the *dwDeinterlacePrefs* parameter.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRDeinterlaceControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrdeinterlacecontrol)

[IVMRDeinterlaceControl::SetDeinterlacePrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrdeinterlacecontrol-setdeinterlaceprefs)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)