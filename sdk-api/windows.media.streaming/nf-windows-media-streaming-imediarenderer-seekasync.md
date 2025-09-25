# IMediaRenderer::streaming

## Description

Instructs the DMR asynchronously to seek to a particular time offset.

## Parameters

### `target` [in]

A [TimeSpan](https://learn.microsoft.com/previous-versions/windows/desktop/axe/timespan) value that specifies the seek offset. This value must be 0 (indicating the beginning of the content) or greater, but less than the value of [PositionInformation.TrackDuration](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828991(v=vs.85)) which is obtained by calling [GetPositionInformationAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828931(v=vs.85)).

### `value` [out]

Receives a reference to a [PlaybackOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/playbackoperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)