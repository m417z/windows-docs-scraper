# IAMNetworkStatus::get_IsBroadcast

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_IsBroadcast` method retrieves a value indicating whether the current stream is a broadcast stream.

## Parameters

### `pIsBroadcast`

Pointer to a variable that receives a Boolean value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

A broadcast stream can be unicast or multicast. In a broadcast connection, the client is passive and does not control when the stream starts or stops. In an on-demand connection, the client is active and controls when the stream is started and stopped.

## See also

[IAMNetworkStatus Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iamnetworkstatus)