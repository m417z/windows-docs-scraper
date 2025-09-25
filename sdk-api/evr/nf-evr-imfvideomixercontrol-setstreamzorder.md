# IMFVideoMixerControl::SetStreamZOrder

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Sets the z-order of a video stream.

## Parameters

### `dwStreamID` [in]

Identifier of the stream. For the EVR media sink, the stream identifier is defined when the [IMFMediaSink::AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink) method is called. For the DirectShow EVR filter, the stream identifier corresponds to the pin index. The reference stream is always stream 0.

### `dwZ` [in]

Z-order value. The z-order of the reference stream must be zero. The maximum z-order value is the number of streams minus one.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value of *dwZ* is larger than the maximum z-order value. |
| **MF_E_INVALIDREQUEST** | Invalid z-order for this stream. For the reference stream, *dwZ* must be zero. For all other streams, *dwZ* must be greater than zero. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |

## Remarks

The EVR draws the video streams in the order of their z-order values, starting with zero. The reference stream must be first in the z-order, and the remaining streams can be in any order.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoMixerControl](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideomixercontrol)