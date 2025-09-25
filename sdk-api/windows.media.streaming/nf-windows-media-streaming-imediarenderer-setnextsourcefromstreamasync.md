# IMediaRenderer::streaming

## Description

Instructs the DMR asynchronously to prepare the specified media stream for playing once the current content has finished playing.

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

Once the DMR finishes playing the current content, it will automatically switch to the content specified by the *stream* parameter.

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)