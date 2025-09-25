# IMFVideoMixerControl::SetStreamOutputRect

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets the position of a video stream within the composition rectangle.

## Parameters

### `dwStreamID` [in]

Identifier of the stream. For the EVR media sink, the stream identifier is defined when the [IMFMediaSink::AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink) method is called. For the DirectShow EVR filter, the stream identifier corresponds to the pin index. The reference stream is always stream 0.

### `pnrcOutput` [in]

Pointer to an [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure that defines the bounding rectangle for the video stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The coordinates of the bounding rectangle given in *pnrcOutput* are not valid. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |

## Remarks

The mixer draws each video stream inside a bounding rectangle that is specified relative to the final video image. This bounding rectangle is given in *normalized* coordinates. For more information, see [MFVideoNormalizedRect](https://learn.microsoft.com/windows/desktop/api/evr/ns-evr-mfvideonormalizedrect) structure.

The coordinates of the bounding rectangle must fall within the range [0.0, 1.0]. Also, the X and Y coordinates of the upper-left corner cannot exceed the X and Y coordinates of the lower-right corner. In other words, the bounding rectangle must fit entirely within the composition rectangle and cannot be flipped vertically or horizontally.

The following diagram shows how the EVR mixes substreams.

![Diagram showing an image, then that image inside a larger output rectangle, then a portion of the image in a source rectangle](https://learn.microsoft.com/windows/win32/api/evr/images/d87d365f-a004-4896-ad03-48cd28449403.gif)
The output rectangle for the stream is specified by calling **SetStreamOutputRect**. The source rectangle is specified by calling [IMFVideoDisplayControl::SetVideoPosition](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-setvideoposition). The mixer applies the output rectangle first, when it mixes the streams into a single bounding rectangle. This bounding rectangle is called *composition space*. Then the presenter applies the source rectangle to the composited image.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoMixerControl](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideomixercontrol)