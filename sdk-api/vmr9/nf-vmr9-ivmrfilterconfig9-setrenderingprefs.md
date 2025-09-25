# IVMRFilterConfig9::SetRenderingPrefs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRenderingPrefs` method sets various application preferences related to video rendering.

## Parameters

### `dwRenderFlags` [in]

Double word containing a bitwise OR of [VMR9RenderPrefs](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ne-vmr9-vmr9renderprefs) values specifying the rendering preferences.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **VFW_E_WRONG_STATE** | No allocator-presenter is present. |
| **E_INVALIDARG** | *dwRenderFlags* is invalid. |

## Remarks

This method calls through to the allocator-presenter's [IVMRImagePresenterConfig9::SetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrimagepresenterconfig9-setrenderingprefs) method. (The default allocator-presenter exposes **IVMRImagePresenterConfig9**. Custom allocator-presenters can also expose this interface if desired.) If the VMR-9 has not yet created the default allocator-presenter, or if the application provided a custom allocator-presenter which does not support **IVMRImagePresenterConfig9**, this method returns VFW_E_WRONG_STATE. To create the default allocator-presenter, call [IVMRFilterConfig9::SetRenderingMode](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrfilterconfig9-setrenderingmode) with the value VMR9Mode_Windowed or VMR9Mode_Windowed.

## See also

[IVMRFilterConfig9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/nn-vmr9-ivmrfilterconfig9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)