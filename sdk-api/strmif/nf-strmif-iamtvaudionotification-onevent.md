# IAMTVAudioNotification::OnEvent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMTVAudioNotification** interface is deprecated.

The `OnEvent` method handles events from a TV tuner card controlled by the [IAMTVAudio](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvaudio) interface.

## Parameters

### `Event` [in]

Flag identifying the type of event. The only value currently defined is AMTVAUDIO_EVENT_CHANGED.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTVAudioNotification Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvaudionotification)