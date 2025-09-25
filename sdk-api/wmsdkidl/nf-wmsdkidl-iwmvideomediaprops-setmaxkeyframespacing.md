# IWMVideoMediaProps::SetMaxKeyFrameSpacing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetMaxKeyFrameSpacing** method specifies the maximum interval between key frames.

## Parameters

### `llTime` [in]

Maximum key-frame spacing in 100-nanosecond units.

## Return value

This method always returns S_OK.

## Remarks

A key frame is a video frame that can be rendered without any information being required from any previous frame. A delta frame is a frame that is dependent on a previous frame. The application can seek to a key frame, but not to a delta frame. The SDK does not enforce any limit on the time between key frames. In general, times longer than 30 seconds can adversely affect seek times both when the content is streamed over a network, and when it is played back locally. For recommended values, see [Configuring Video Streams for Seeking Performance](https://learn.microsoft.com/windows/desktop/wmformat/configuring-video-streams-for-seeking-performance).

## See also

[IWMVideoMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmvideomediaprops)

[IWMVideoMediaProps::GetMaxKeyFrameSpacing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmvideomediaprops-getmaxkeyframespacing)