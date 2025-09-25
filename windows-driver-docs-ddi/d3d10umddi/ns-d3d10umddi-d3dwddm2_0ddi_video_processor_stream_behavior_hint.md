# D3DWDDM2_0DDI_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT structure

## Description

**D3DWDDM2_0DDI_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT** is used to describe behavior hints for the stream.

## Members

### `Enable`

Specifies whether this input stream is enabled. If **TRUE**, [VideoProcessorGetBehaviorHints](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorgetbehaviorhints) uses this stream to compute the behavior hints. Otherwise, this stream is not used.

### `Width`

Specifies the width of the input stream.

### `Height`

Specifies the height of the input stream.

### `Format`

Indicates the input format for the specific stream.

## See also

[VideoProcessorGetBehaviorHints](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3dwddm2_0ddi_videoprocessorgetbehaviorhints)