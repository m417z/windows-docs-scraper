# IMediaRenderer::streaming

## Description

\[The feature associated with this page, [Windows Media Streaming API](https://learn.microsoft.com/windows/win32/mediastreaming/media-streaming-api-portal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). **Media Casting** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Media Casting** instead of **Windows Media Streaming API**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Registers an event handler for the [RenderingParametersUpdate](https://learn.microsoft.com/windows/desktop/mediastreaming/renderingparametersupdate) event.

## Parameters

### `handler` [in]

A [RenderingParametersUpdateHandler](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828994(v=vs.85)) event handler function.

### `token` [out, retval]

Reference to a token that can be used to unregister the event handler.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To unregister the event handler that was registered by this method, pass the *token* value to the [remove_RenderingParametersUpdate](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828940(v=vs.85)) method.

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)