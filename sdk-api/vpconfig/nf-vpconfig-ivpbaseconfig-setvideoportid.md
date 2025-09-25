# IVPBaseConfig::SetVideoPortID

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetVideoPortID` method specifies the ID of the hardware video port to use.

## Parameters

### `dwVideoPortID` [in]

Specifies the video port ID. This value corresponds to the **dwVideoPortID** member of the **DDVIDEOPORTDESC** structure, which is documented in the Windows DDK.

## Return value

Returns an **HRESULT** value.

## Remarks

This method sets the DirectDraw video port ID on the mini driver to enable it to communicate with the video port directly.

Include Dvp.h and Vptype.h before Vpconfig.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPBaseConfig Interface](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpbaseconfig)