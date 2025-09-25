# IVMRFilterConfig9::GetRenderingPrefs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetRenderingPrefs** method retrieves the current set of rendering preferences being used by the VMR-9.

## Parameters

### `pdwRenderFlags` [out]

Receives a [VMR9RenderPrefs](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9renderprefs) value indicating the current rendering preferences.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **VFW_E_WRONG_STATE** | The VMR has not created an allocator-presenter, or the allocator-presenter does not implement the [IVMRImagePresenterConfig9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagepresenterconfig9) interface. |

## Remarks

If the allocator-presenter implements the [IVMRImagePresenterConfig9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagepresenterconfig9) interface, this method calls the [IVMRImagePresenterConfig9::GetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrimagepresenterconfig9-getrenderingprefs) method on the allocator-presenter.

The default allocator-presenter implements [IVMRImagePresenterConfig9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagepresenterconfig9). Custom allocator-presenters can also implements this interface if desired.

If the VMR-9 has not yet created the allocator-presenter, or if a custom allocator-presenter does not support [IVMRImagePresenterConfig9](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrimagepresenterconfig9), this method returns **VFW_E_WRONG_STATE**. To create the default allocator-presenter, call [IVMRFilterConfig9::SetRenderingMode](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrfilterconfig9-setrenderingmode) with the value **VMR9Mode_Windowed** or **VMR9Mode_Windowless**.

## See also

[IVMRFilterConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrfilterconfig9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)