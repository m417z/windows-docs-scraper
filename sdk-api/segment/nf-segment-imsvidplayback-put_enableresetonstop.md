# IMSVidPlayback::put_EnableResetOnStop

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_EnableResetOnStop** method indicates how playback will resume if the graph is rebuilt.

## Parameters

### `newVal` [in]

Specifies one of the following values.

| Value | Description |
| --- | --- |
| **VARIANT_FALSE** | The Video Control attempts to start from position where playback was interrupted. (Default) |
| **VARIANT_TRUE** | The Video Control seeks back to the start before resuming playback. |

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

In some situations, the filter graph may be torn down and rebuilt during play. For example, this can happen if the monitor resolution changes or the screen saver starts. The **put_EnableResetOnStop** property specifies whether the Video Control should resume playback where it was interrupted, or should restart at the beginning of the source.

By default, playback resumes from the point where it was interrupted. If *newVal* is VARIANT_TRUE, however, the Video Control will issue a seek command back to time zero. Note that setting this parameter to VARIANT_TRUE does not guarantee that the seek command will succeed. The seek command might fail, depending on the source.

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)