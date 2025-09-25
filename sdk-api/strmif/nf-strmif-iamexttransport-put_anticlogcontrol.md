# IAMExtTransport::put_AntiClogControl

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_AntiClogControl` method enables or disables anti-headclog control on the transport.

This method is not implemented.

## Parameters

### `Enable` [in]

Specifies whether to enable anti-headclog control.

| Value | Description |
| --- | --- |
| OATRUE | Enable transport anti-headclog control. |
| OAFALSE | Disable transport anti-headclog control. |

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

Use this method to unclog video heads on VCRs that have an automatic head-cleaning feature.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::get_AntiClogControl](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-get_anticlogcontrol)