# IVideoFrameStep::Step

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Step` method causes the filter graph to step forward by the specified number of frames.

## Parameters

### `dwFrames`

Specifies the number of frames to skip. If *dwFrames* is 1, the graph steps forward one frame. If *dwFrames* is a number *n* greater than 1, the graph skips *n* - 1 frames and shows the *n*th frame.

### `pStepObject`

Pointer to an interface on the filter that will control the stepping operation, or **NULL**. Specify **NULL** to perform the frame stepping using the renderer filter in the graph. If non-**NULL**, the object must implement the [IKsPropertySet](https://learn.microsoft.com/windows/desktop/DirectShow/ikspropertyset) interface and support the AM_KSPROPSETID_FrameStep property. (For more information, see [Frame Stepping Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/frame-stepping-property-set).) If the graph includes a custom filter that implements the frame stepping, *pStepObject* can specify a pointer to that filter.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_FRAME_STEP_UNSUPPORTED** | Frame stepping is not supported. |
| **E_INVALIDARG** | The *pStepObject* parameter is invalid. |

## Remarks

When the step operation is complete, this method sends an [EC_STEP_COMPLETE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-step-complete) event notification to the filter graph manager, which will pass it to the application's event loop and set the filter graph to a paused state.

The frames step in real time, which means that if the movie is playing at 30 frames per second, calling **IVideoFrameStep::Step** with *dwFrames* set to 60 would take 2 seconds to execute. All methods in this interface are asynchronous, so control returns to the application immediately.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoFrameStep Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivideoframestep)