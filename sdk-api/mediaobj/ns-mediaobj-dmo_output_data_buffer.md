# DMO_OUTPUT_DATA_BUFFER structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DMO_OUTPUT_DATA_BUFFER` structure describes an output buffer used by a Microsoft DirectX Media Object (DMO).

## Members

### `pBuffer`

Pointer to the [IMediaBuffer](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-imediabuffer) interface of a buffer allocated by the application.

### `dwStatus`

Status flags. After processing output, the DMO sets this member to a bitwise combination of zero or more [DMO_OUTPUT_DATA_BUFFER_FLAGS](https://learn.microsoft.com/windows/desktop/api/mediaobj/ne-mediaobj-_dmo_output_data_buffer_flags) flags.

### `rtTimestamp`

Time stamp that specifies the start time of the data in the buffer. If the buffer has a valid time stamp, the DMO sets this member and also sets the DMO_OUTPUT_DATA_BUFFERF_TIME flag in the **dwStatus** member. Otherwise, ignore this member.

### `rtTimelength`

Reference time specifying the length of the data in the buffer. If the DMO sets this member to a valid value, it also sets the DMO_OUTPUT_DATA_BUFFERF_TIMELENGTH flag in the **dwStatus** member. Otherwise, ignore this member.

## See also

[DMO Structures](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-structures)

[IMediaObject::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processoutput)