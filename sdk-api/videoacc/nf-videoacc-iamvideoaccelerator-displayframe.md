# IAMVideoAccelerator::DisplayFrame

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DisplayFrame** method causes the video renderer to display a decoded frame.

## Parameters

### `dwFlipToIndex` [in]

The surface index of the decoded frame to display.

### `pMediaSample` [in]

Pointer to the [IMediaSample](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample) interface of a media sample. This sample does not contain a video frame, but is used to specify the time stamp and any sample flags. (For more information about sample flags, see [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties).

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. **HRESULT** can include one of the following standard constants, or other values not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Argument is invalid. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_INVALIDSUBTYPE** | The decoder did not use a DXVA decoding type when it connected to the video renderer. |
| **VFW_E_NOT_CONNECTED** | The pins on the decoder and video renderer filters are not connected. |

## Remarks

If the filter's pins are not connected, the method returns **VFW_E_NOT_CONNECTED**.

The method blocks until the video renderer finishes displaying the video frame.

The video decoder calls this method after calling [IAMVideoAccelerator::EndFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-endframe) for the surface whose index is given in *dwFlipToIndex*. The index value must match the value of **AMVABeginFrameInfo.dwDestSurfaceIndex** in a previous call to [IAMVideoAccelerator::BeginFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-beginframe).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoaccelerator)