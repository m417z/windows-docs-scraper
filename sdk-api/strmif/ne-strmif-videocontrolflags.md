# VideoControlFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the video mode of operation for a video device.

## Constants

### `VideoControlFlag_FlipHorizontal:0x1`

Specifies that the picture is flipped horizontally.

### `VideoControlFlag_FlipVertical:0x2`

Specifies that the picture is flipped vertically.

### `VideoControlFlag_ExternalTriggerEnable:0x4`

Sets up a stream to capture a trigger from an external source, for example, a push button on a camera. Buffers can be queued to the driver but will not be passed up from the WDM capture driver (for compression, display, or writing to a file) until the external event happens. See Remarks.

### `VideoControlFlag_Trigger:0x8`

In software, simulates an external trigger when the stream has the VideoControlFlag_ExternalTriggerEnable flag set.

## Remarks

The [IAMVideoControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocontrol) interface uses this enumerated data type.

Multiple capture buffers are queued to a capture driver and are filled at a fixed rate once the stream is put into the "run" state. If the VideoControlFlag_ExternalTriggerEnable flag is set, a filled buffer is not passed up from the WDM capture driver for compression, display, or writing to a file until the external event happens.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMVideoControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocontrol)