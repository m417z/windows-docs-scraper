# IAMExtTransport::SetTransportVideoParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTransportVideoParameters` method assigns video parameters for external transport.

This method is not implemented.

## Parameters

### `Param` [in]

Specifies the video parameter to set. Must be one of the following values.

| Value | Description |
| --- | --- |
| ED_TRANSVIDEO_SET_OUTPUT | Sets the output mode. |
| ED_TRANSVIDEO_SET_SOURCE | Sets the input pin. |

### `Value` [in]

Specifies the value of the video parameter. See Remarks for more information.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

If *Param* equals ED_TRANSVIDEO_SET_OUTPUT, *Value* must be one of the following constants.

| Constant | Description |
| --- | --- |
| ED_E2E | Input video is displayed on the device's output regardless of the transport mode. |
| ED_OFF | Video output is disabled. |
| ED_PLAYBACK | Video playing from media is displayed on the device's output. |

If *Param* equals ED_TRANSVIDEO_SET_SOURCE, *Value* specifies the index of the input pin to use for the video input. The pin index is zero-based.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::GetTransportVideoParameters](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-gettransportvideoparameters)