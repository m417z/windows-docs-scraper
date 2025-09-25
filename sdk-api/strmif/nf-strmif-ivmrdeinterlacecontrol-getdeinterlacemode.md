# IVMRDeinterlaceControl::GetDeinterlaceMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDeinterlaceMode** method retrieves the deinterlacing mode for the specified video stream.

## Parameters

### `dwStreamID` [in]

Index of the video stream to check.

### `lpDeinterlaceMode` [out]

Pointer to a variable that receives a GUID. The GUID identifies the deinterlacing mode currently in use. If no deinterlacing mode was set, the value is GUID_NULL.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid stream number. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_FALSE** | No deinterlacing mode was set. |
| **S_OK** | Success. |
| **VFW_E_VMR_NOT_IN_MIXER_MODE** | The VMR is not in mixer mode. |

## Remarks

The VMR may not be able to use the requested mode, in which case it falls back to another deinterlace mode, as specified in the [IVMRDeinterlaceControl::SetDeinterlacePrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrdeinterlacecontrol-setdeinterlaceprefs) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRDeinterlaceControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrdeinterlacecontrol)

[IVMRDeinterlaceControl::SetDeinterlaceMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrdeinterlacecontrol-setdeinterlacemode)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)