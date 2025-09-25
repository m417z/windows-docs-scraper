# IAMNetworkStatus::get_LostPackets

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_LostPackets` method retrieves the number of packets that have been lost.

## Parameters

### `pLostPackets`

Pointer to a variable that receives the number of lost packets.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This property is only valid for streaming media, and will equal zero when using the HTTP protocol, which is lossless. Packets may be lost for a number of reasons, such as the type and quality of the network connection.

Whenever playback is stopped and restarted, this property is set to zero. It is not reset if playback is paused and restarted.

## See also

[IAMNetworkStatus Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iamnetworkstatus)