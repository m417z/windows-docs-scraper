# IVMRMixerControl9::GetProcAmpControl

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetProcAmpControl` method retrieves the current image adjustment settings for the VMR-9. Image adjustment includes brightness, contrast, hue, and saturation, and is performed by the graphics device. If the graphics driver does not support hardware image adjustment, this method fails.

## Parameters

### `dwStreamID` [in]

Specifies the input stream. This value corresponds to the input pin. For example, the first input pin is stream 0.

### `lpClrControl` [in, out]

Pointer to a [VMR9ProcAmpControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9procampcontrol) structure that receives the image adjustment settings. When the method returns, the **dwFlags** field indicates which properties are supported by the graphics driver. Set the **dwSize** member in the structure before calling this method.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. Possible causes of this error include:<br><br>* The stream number is invalid<br>* The value of **dwSize** in the **VMR9ProcAmpControl** structure is invalid. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The pin is not connected. |
| **VFW_E_VMR_NO_PROCAMP_HW** | The graphics hardware does not support ProcAmp controls. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMixerControl9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmixercontrol9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)