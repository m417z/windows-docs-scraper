# AMVABeginFrameInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMVABeginFrameInfo** structure contains information for the [IAMVideoAccelerator::BeginFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-beginframe) method.

## Members

### `dwDestSurfaceIndex`

The zero-based index of the uncompressed destination surface. The number of uncompressed surfaces is specified in the [IAMVideoAcceleratorNotify::SetUncompSurfacesInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoacceleratornotify-setuncompsurfacesinfo) method.

### `pInputData`

Pointer to a buffer that contains data for the video accelerator.

This buffer must contain a **WORD** value that is equal to the value of **dwDestSurfaceIndex**.

### `dwSizeInputData`

Size, in bytes, of the buffer that **pInputData** points to. The value must be 2.

### `pOutputData`

Pointer to a buffer that the video accelerator can write to.

This member must be **NULL**.

### `dwSizeOutputData`

Size, in bytes, of the buffer that **pOutputData** points to. The value must be zero.

## Remarks

The buffer pointed to by **pInputData** cannot contain pointer values, because their addresses will not be valid in kernel mode, where frame processing occurs.

The video accelerator might not use the same surface memory in two consecutive calls with the same frame index.
Therefore, the decoder should not make any assumption about the initial contents of the frame.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IAMVideoAccelerator::BeginFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-beginframe)