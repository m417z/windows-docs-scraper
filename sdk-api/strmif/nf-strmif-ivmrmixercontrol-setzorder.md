# IVMRMixerControl::SetZOrder

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetZOrder` method sets this video stream's position in the Z-order; larger values are further away.

## Parameters

### `dwStreamID` [in]

Specifies the input stream.

### `dwZ` [in]

Double word containing the stream's position within the Z-order.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **VFW_E_NOT_CONNECTED** | The pin is not connected. |

## Remarks

The default Z-order is the order in which the pins were created. You only need to use this method if you wish to modify the default Z-order.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRMixerControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrmixercontrol)

[IVMRMixerControl::GetZOrder](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixercontrol-getzorder)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)