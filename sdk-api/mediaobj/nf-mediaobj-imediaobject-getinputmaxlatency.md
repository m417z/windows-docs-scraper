# IMediaObject::GetInputMaxLatency

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetInputMaxLatency` method retrieves the maximum latency on a specified input stream.

## Parameters

### `dwInputStreamIndex`

Zero-based index of an input stream on the DMO.

### `prtMaxLatency` [out]

Pointer to a variable that receives the maximum latency.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **DMO_E_INVALIDSTREAMINDEX** | Invalid stream index. |
| **E_FAIL** | Failure. |
| **E_NOTIMPL** | Not implemented. Assume zero latency. |
| **S_OK** | Success. |

## Remarks

The latency is the difference between a time stamp on the input stream and the corresponding time stamp on the output stream. The maximum latency is the largest possible difference in the time stamps. For a DMO, determine the maximum latency as follows:

* Process input buffers until the DMO can produce output.
* Process as many output buffers as possible.
* The maximum latency is the largest delta between input time stamps and output time stamps (taken as an absolute value).

Under this definition, latency does not include the time that it takes to process samples. Nor does it include any latency introduced by the size of the input buffer.

For the special case where a DMO processes exactly one sample at a time, the maximum latency is simply the difference in time stamps.

Latency is defined only when samples have time stamps, and the time stamps increase or decrease monotonically. Maximum latency might depend on the media types for the input and output streams.

## See also

[IMediaObject Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediaobject)