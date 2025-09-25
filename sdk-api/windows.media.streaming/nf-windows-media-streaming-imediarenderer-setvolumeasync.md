# IMediaRenderer::streaming

## Description

Sets the audio volume level on the DMR asynchronously to the specified value.

## Parameters

### `volume` [in]

A reference to the specified volume value. The value must be in the range of 0 to 100, with 0 being the minimum volume and 100 being the maximum volume.

### `value` [out]

Receives a reference to a [PlaybackOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/playbackoperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)