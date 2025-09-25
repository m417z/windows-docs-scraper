# IVMRImagePresenterExclModeConfig::SetXlcModeDDObjAndPrimarySurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetXlcModeDDObjAndPrimarySurface` method informs the VMR of the DirectDraw object and primary surface that were created by the application.

## Parameters

### `lpDDObj` [in]

Specifies the Exclusive Mode DirectDraw object created by the application.

### `lpPrimarySurf` [in]

Specifies the primary surface associated with the DirectDraw object.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The procedure for configuring and using an application-defined DirectDraw Exclusive Mode object is described in [DirectDraw Exclusive Mode](https://learn.microsoft.com/windows/desktop/DirectShow/directdraw-exclusive-mode).

## See also

[IVMRImagePresenterExclModeConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrimagepresenterexclmodeconfig)

[IVMRImagePresenterExclModeConfig::GetXlcModeDDObjAndPrimarySurface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrimagepresenterexclmodeconfig-getxlcmodeddobjandprimarysurface)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)