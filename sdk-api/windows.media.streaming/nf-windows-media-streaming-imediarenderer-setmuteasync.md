# IMediaRenderer::streaming

## Description

Instructs the DMR asynchronously to either mute or unmute the audio.

## Parameters

### `mute` [in]

A reference to a boolean value that specifies the mute setting. A value of True specifies that mute is turned on, and a value of False specifies that it is turned off.

### `value` [out]

Receives a reference to a [PlaybackOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/playbackoperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)