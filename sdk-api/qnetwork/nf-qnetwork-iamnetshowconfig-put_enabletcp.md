# IAMNetShowConfig::put_EnableTCP

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_EnableTCP` method enables or disables TCP-based streaming.

## Parameters

### `EnableTCP`

Specify one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | Enable TCP-based streaming. |
| VARIANT_FALSE | Disable TCP-based streaming. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IAMNetShowConfig Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iamnetshowconfig)

[IAMNetShowConfig::put_EnableUDP](https://learn.microsoft.com/windows/desktop/api/qnetwork/nf-qnetwork-iamnetshowconfig-put_enableudp)