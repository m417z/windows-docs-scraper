# IVMRDeinterlaceControl9::GetDeinterlaceModeCaps

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDeinterlaceModeCaps** method gets the capabilities of a deinterlacing mode supported by the graphics device driver.

## Parameters

### `lpDeinterlaceMode` [in]

Pointer to a GUID that identifies the deinterlacing mode. Call the [IVMRDeinterlaceControl9::GetNumberOfDeinterlaceModes](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrdeinterlacecontrol9-getnumberofdeinterlacemodes) method to obtain a list of GUIDs supported by the driver.

### `lpVideoDescription` [in]

Pointer to a [VMR9VideoDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9videodesc) structure describing the video to deinterlace.
Set the **dwSize** member of the structure before calling the method.

### `lpDeinterlaceCaps` [out]

Pointer to a [VMR9DeinterlaceCaps](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9deinterlacecaps) structure. Set the **dwSize** member of the structure before calling the method. The method fills the structure with information about the specified deinterlacing mode.

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

The method returns **E_INVALIDARG** if you do not set the **dwSize** member in the [VMR9VideoDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9videodesc) and [VMR9DeinterlaceCaps](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9deinterlacecaps) structures.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRDeinterlaceControl9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrdeinterlacecontrol9)

[Setting Deinterlace Preferences](https://learn.microsoft.com/windows/desktop/DirectShow/setting-deinterlace-preferences)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[Video Mixing Renderer Filter 9](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-9)