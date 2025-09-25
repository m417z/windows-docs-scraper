# Quality structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Quality` structure describes a quality message by indicating Flood or Famine in the renderer and specifying the percentage of frames to drop or add to optimize the renderer's performance.

## Members

### `Type`

Value from the [QualityMessageType](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-qualitymessagetype) enumeration, indicating whether the downstream filter needs more or less data.

### `Proportion`

Value that specifies the rate at which DirectShow should continue to send media samples. The base value is 1000, which indicates there should be no change. A percentage increase or decrease from 1000 indicates the percentage of frames to add or drop. If this value is 800, for example, DirectShow will drop 20 percent of the incoming frames to match the renderer's speed.

### `Late`

If a famine exists downstream, this is the amount of time by which the stream is lagging.

### `TimeStamp`

Value that specifies the time when DirectShow created this structure, which is usually the start time on a video sample.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)