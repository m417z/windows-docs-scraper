# IAMExtendedSeeking::get_ExSeekCapabilities

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_ExSeekCapabilities` method retrieves the extended seeking capabilities of the filter.

## Parameters

### `pExCapabilities` [out]

Pointer to a variable that receives a bitwise OR of [AMExtendedSeekingCapabilities](https://learn.microsoft.com/windows/desktop/api/qnetwork/ne-qnetwork-amextendedseekingcapabilities) flags.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The Windows Media Source filter sets the extended seeking flags as follows.

|  |  |
| --- | --- |
| Flag | Condition |
| AM_EXSEEK_BUFFERING | Always. |
| AM_EXSEEK_NOSTANDARDREPAINT | Always. |
| AM_EXSEEK_SENDS_VIDEOFRAMEREADY | If the video pin has been created. |
| AM_EXSEEK_CANSCAN, AM_EXSEEK_SCANWITHOUTCLOCK | If the stream supports rates other than 1.0. |
| AM_EXSEEK_CANSEEK | If the stream has been authored to be seekable. |
| AM_EXSEEK_MARKERSEEK | If the stream contains markers. |

## See also

[IAMExtendedSeeking Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iamextendedseeking)