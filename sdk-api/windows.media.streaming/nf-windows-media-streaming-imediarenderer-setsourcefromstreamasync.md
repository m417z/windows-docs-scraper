# IMediaRenderer::streaming

## Description

Instructs the DMR asynchronously to prepare the specified media stream for playing.

## Parameters

### `stream` [in]

A reference to an [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) interface implementing [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate). The **IMFActivate** interface is used to query for an [IMFByteStream](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfbytestream) interface that represents the media stream.

### `value` [out]

Receives a reference to a [PlaybackOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/playbackoperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the DMR is not currently playing anything, the [PlayAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828938(v=vs.85)) or [PlayAtSpeedAsync](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828939(v=vs.85)) method must be used to instruct the DMR to start playing.
If the DMR is already playing content, it will automatically switch to the content provided by the *stream* parameter.

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)