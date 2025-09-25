# IMediaRenderer::streaming

## Description

Unregisters an event handler for the [RenderingParametersUpdate](https://learn.microsoft.com/windows/desktop/mediastreaming/renderingparametersupdate) event.

## Parameters

### `token` [in]

A reference to a token obtained from the [add_RenderingParametersUpdate](https://learn.microsoft.com/previous-versions/windows/desktop/api/windows.media.streaming/nf-windows-media-streaming-imediarenderer-add_renderingparametersupdate) method when the event handler was registered.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)