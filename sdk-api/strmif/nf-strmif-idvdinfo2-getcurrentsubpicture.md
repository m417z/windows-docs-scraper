# IDvdInfo2::GetCurrentSubpicture

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentSubpicture` method retrieves the number of available subpicture streams in the current title, the currently selected subpicture stream number, and the state of the subpicture.

## Parameters

### `pulStreamsAvailable` [out]

Receives the number of available subpicture streams.

### `pulCurrentStream` [out]

Receives the number of the currently selected subpicture stream.

### `pbIsDisabled` [out]

Receives a Boolean value that indicates whether the subpicture display is disabled; **TRUE** means it is disabled.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized or not in the Title domain. |

## Remarks

DVD content authors can specify that any particular subpicture stream on a disc is *forcedly activated*, meaning that the DVD authors require this stream to display whether the viewer wants to watch it or not. The DVD Navigator complies with all such commands from the disc, meaning that forcedly activated streams are displayed even if the application has disabled subpicture display with the [IDvdControl2::SetSubpictureState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setsubpicturestate) method.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[EC_DVD_SUBPICTURE_STREAM_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-subpicture-stream-change)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)