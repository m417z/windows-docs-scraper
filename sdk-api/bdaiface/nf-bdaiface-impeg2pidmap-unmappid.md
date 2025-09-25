# IMPEG2PIDMap::UnmapPID

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `UnmapPID` method unmaps one or more PIDs.

## Parameters

### `culPID` [in]

The number of elements in the *pulPID* array.

### `pulPID` [in]

Pointer to an array of size *culPID*, allocated by the caller. Each element in the array contains a PID to be unmapped

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

On output pins for audio and video streams, there will typically be only one PID mapped at any given time. On an output pin such as one delivering the PSI stream to the Transport Information Filter, there may be multiple PIDs mapped to a single pin. Use the [IEnumPIDMap](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ienumpidmap) methods to determine which PIDs are mapped to the pin, and then fill in the *pulPID* array with those values.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMPEG2PIDMap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdaiface/nn-bdaiface-impeg2pidmap)