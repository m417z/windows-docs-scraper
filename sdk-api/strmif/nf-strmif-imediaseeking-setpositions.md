# IMediaSeeking::SetPositions

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetPositions` method sets the current position and the stop position.

## Parameters

### `pCurrent` [in, out]

[in,out] Pointer to a variable that specifies the current position, in units of the current time format.

### `dwCurrentFlags` [in]

Bitwise combination of flags. See Remarks.

### `pStop` [in, out]

[in,out] Pointer to a variable that specifies the stop time, in units of the current time format.

### `dwStopFlags` [in]

Bitwise combination of flags. See Remarks.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | No position change. (Both flags specify no seeking.) |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

The *dwCurrentFlags* and *dwStopFlags* parameters define the type of seek. The following flags are defined.

| Positioning Flags | Description |
| --- | --- |
| AM_SEEKING_NoPositioning | No change in position. (The time parameter can be **NULL**.) |
| AM_SEEKING_AbsolutePositioning | The specified position is absolute. |
| AM_SEEKING_RelativePositioning | The specified position is relative to the previous value. |
| AM_SEEKING_IncrementalPositioning | The stop position (*pStop*) is relative to the current position (*pCurrent*). |

| Modifier Flags | Description |
| --- | --- |
| AM_SEEKING_SeekToKeyFrame | Seek to the nearest key frame. This might be faster, but less accurate. None of the filters that ship with DirectShow support this flag. Decoders are the most likely type of filter to support it. |
| AM_SEEKING_ReturnTime | Return the equivalent reference times. |
| AM_SEEKING_Segment | Use segment seeking. |
| AM_SEEKING_NoFlush | Do not flush. |

For each parameter, use one positioning flag. Optionally, include one or more modifier flags.

If the AM_SEEKING_ReturnTime flag is specified, the method converts the position value to a reference time and returns it in the *pCurrent* or *pStop* variable. This flag is useful if you are using another time format, such as frames.

The AM_SEEKING_Segment and AM_SEEKING_NoFlush flags support seamless looping:

* If the AM_SEEKING_Segment flag is present, the source filter sends an [EC_END_OF_SEGMENT](https://learn.microsoft.com/windows/desktop/DirectShow/ec-end-of-segment) event when it reaches the stop position, instead of calling [IPin::EndOfStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-endofstream). The application can wait for this event and then issue another seek command.
* If the AM_SEEKING_NoFlush flag is present, the graph does not flush data during the seek. Use this flag with AM_SEEKING_Segment.

To perform looping, the graph must report AM_SEEKING_CanDoSegments in the [IMediaSeeking::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-getcapabilities) method. Currently, only the [WAVE Parser Filter](https://learn.microsoft.com/windows/desktop/DirectShow/wave-parser-filter) supports this feature.

The incoming values of *pCurrent* and *pStop* are expressed in the current time format. The default time format is [REFERENCE_TIME](https://learn.microsoft.com/windows/desktop/DirectShow/reference-time) units (100 nanoseconds). To change time formats, use the [IMediaSeeking::SetTimeFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediaseeking-settimeformat) method. If the AM_SEEKING_ReturnTime flag is present, the method converts the outgoing value to **REFERENCE_TIME** units.

### Filter Developers

If you implement this method, you can check whether the caller is requesting a change in the current or stop position, by using the value AM_SEEKING_PositioningBitsMask to mask out the modifier flags. For example:

|  |
| --- |
| ``` DWORD dwCurrentPos = dwCurrentFlags & AM_SEEKING_PositioningBitsMask if (dwCurrentPos == AM_SEEKING_AbsolutePositioning) {      // Set new position to pCurrent.     m_rtStart = *pCurrent; } else if (dwCurrentPos == AM_SEEKING_RelativePositioning) {     // Increment current position by pCurrent.     m_rtStart += *pCurrent; } ``` |

For more information, see the source code for the [CSourceSeeking::SetPositions](https://learn.microsoft.com/windows/desktop/DirectShow/csourceseeking-setpositions) method in the base class library.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)