# IVMRDeinterlaceControl::GetDeinterlaceModeCaps

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDeinterlaceModeCaps** method retrieves the capabilities of a specific deinterlacing mode supported by the graphics device driver.

## Parameters

### `lpDeinterlaceMode` [in]

Pointer to a GUID that identifies the deinterlacing mode. Call the [GetNumberOfDeinterlaceModes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrdeinterlacecontrol-getnumberofdeinterlacemodes) method to obtain a list of GUIDs supported by the driver.

### `lpVideoDescription` [in]

Pointer to a [VMRVideoDesc](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-vmrvideodesc) structure describing the video to deinterlace. Set the **dwSize** member of the structure before calling the method.

### `lpDeinterlaceCaps` [out]

Pointer to a [VMRDeinterlaceCaps](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrdeinterlacecaps) structure. Set the **dwSize** member of the structure before calling the method. The method fills the structure with information about the specified deinterlacing mode.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **VFW_E_DDRAW_CAPS_NOT_SUITABLE** | The video card does not support hardware deinterlacing. |
| **VFW_E_VMR_NO_DEINTERLACE_HW** | The video card does not support hardware deinterlacing. |
| **VFW_E_VMR_NOT_IN_MIXER_MODE** | The VMR is not in mixer mode. |

## Remarks

The method returns [VMRVideoDesc](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-vmrvideodesc) and [VMRDeinterlaceCaps](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-vmrdeinterlacecaps) structures.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRDeinterlaceControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrdeinterlacecontrol)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)