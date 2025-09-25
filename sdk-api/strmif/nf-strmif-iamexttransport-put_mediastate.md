# IAMExtTransport::put_MediaState

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_MediaState` method sets the current state of the media.

## Parameters

### `State` [in]

Specifies the media state as a **long** integer. Use one of the following:

| Value | Description |
| --- | --- |
| ED_MEDIA_SPIN_DOWN | For disk media: Stop spinning. For tape media: Unthread the tape. |
| ED_MEDIA_SPIN_UP | For disk media: Start spinning. For tape media: Thread the tape. |
| ED_MEDIA_UNLOAD | Eject the media from the drive. |

These constants are for disk and tape media. Other devices might need to define new constants.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::get_MediaState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-get_mediastate)