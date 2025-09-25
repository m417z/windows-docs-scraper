# IMediaRenderer::streaming

## Description

Instructs the DMR asynchronously to play the content that was specified by calling the [SetSourceFromUriAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828949(v=vs.85)), [SetSourceFromStreamAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828948(v=vs.85)), or [SetSourceFromMediaSourceAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828947(v=vs.85)) method at the specified rate.

## Parameters

### `playSpeed` [in]

The rate at which the DMR will be instructed to play the content. This value must correspond to one of the values returned by the [IMediaRendererActionInformation::PlaySpeeds](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarendereractioninformation-playspeeds) method.

### `value` [out]

Receives a reference to a [PlaybackOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/playbackoperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before this method is called, you must call [SetSourceFromUriAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828949(v=vs.85)), [SetSourceFromStreamAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828948(v=vs.85)), or [SetSourceFromMediaSourceAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828947(v=vs.85)) first to specify the content.

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)