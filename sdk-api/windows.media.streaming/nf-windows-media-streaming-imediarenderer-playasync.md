# IMediaRenderer::streaming

## Description

Instructs the DMR asynchronously to play the content that was specified by calling the [SetSourceFromUriAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828949(v=vs.85)), [SetSourceFromStreamAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828948(v=vs.85)), or [SetSourceFromMediaSourceAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828947(v=vs.85)) method.

## Parameters

### `value` [out]

Receives a reference to a [PlaybackOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/playbackoperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before this method is called, you must call [SetSourceFromUriAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828949(v=vs.85)), [SetSourceFromStreamAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828948(v=vs.85)), or [SetSourceFromMediaSourceAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828947(v=vs.85)) first to specify the content.

The content will be played at the normal playback rate of "1".
A different playback rate can be specified by calling the [PlayAtSpeedAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828939(v=vs.85)) method.

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)