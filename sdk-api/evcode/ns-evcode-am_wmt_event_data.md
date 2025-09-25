# AM_WMT_EVENT_DATA structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_WMT_EVENT_DATA** structure contains information pertaining to an [EC_WMT_EVENT](https://learn.microsoft.com/windows/desktop/wmformat/ec-wmt-event) and the associated status code returned by the Windows Media Format SDK.

## Members

### `hrStatus`

The status code returned by the Windows Media Format SDK.

### `pData`

Pointer whose data is dependent on the value of the **WMT_STATUS** message in *lParam1* of the **EC_WMT_EVENT** event. For more information, see [EC_WMT_EVENT](https://learn.microsoft.com/windows/desktop/wmformat/ec-wmt-event).

## Remarks

This structure is relevant when using the [WM ASF Reader](https://learn.microsoft.com/windows/desktop/wmformat/wm-asf-reader-filter) filter to read files protected with Digital Rights Management.