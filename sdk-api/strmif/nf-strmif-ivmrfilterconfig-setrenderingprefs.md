# IVMRFilterConfig::SetRenderingPrefs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRenderingPrefs` method sets various application preferences related to video rendering.

## Parameters

### `dwRenderFlags` [in]

Double word containing a bitwise OR of [VMRRenderPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmrrenderprefs) values specifying the rendering preferences.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **VFW_E_WRONG_STATE** | No allocator-presenter is present. |
| **E_INVALIDARG** | *dwRenderFlags* is invalid. |

## Remarks

This method calls through to the allocator-presenter's [IVMRImagePresenterConfig::SetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrimagepresenterconfig-setrenderingprefs) method. (The default allocator-presenter exposes [IVMRImagePresenterConfig](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagepresenterconfig). Custom allocator-presenters can also expose this interface if desired.) If the VMR-7 has not yet created the default allocator-presenter, or if the application provided a custom allocator-presenter which does not support **IVMRImagePresenterConfig**, this method returns VFW_E_WRONG_STATE. To create the default allocator-presenter, call [IVMRFilterConfig::SetRenderingMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-setrenderingmode) with the value VMRMode_Windowed or VMRMode_Windowed.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRFilterConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrfilterconfig)

[IVMRFilterConfig::GetRenderingPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-getrenderingprefs)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)