# IVMRMixerControl9::GetProcAmpControlRange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetProcAmpControlRange` method retrieves the range of values for an image adjustment setting, such as brightness, contrast, hue, or saturation. Image adjustment is performed by the graphics device, so the valid range depends on the graphics driver. If the driver does not support hardware image adjustment, this method fails.

## Parameters

### `dwStreamID` [in]

Specifies the input stream. This value corresponds to the input pin. For example, the first input pin is stream 0.

### `lpClrControl` [in, out]

Pointer to a [VMR9ProcAmpControlRange](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9procampcontrolrange) structure that receives the range. The caller must set the **dwSize** and **dwProperty** fields.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. Possible causes of this error include:<br><br>* The stream number is invalid<br>* The value of **dwSize** or **dwProperty** in the **VMR9ProcAmpControl** structure is invalid. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The pin is not connected. |
| **VFW_E_VMR_NO_PROCAMP_HW** | The graphics hardware does not support ProcAmp controls. |

## Remarks

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[IVMRMixerControl9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrmixercontrol9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)