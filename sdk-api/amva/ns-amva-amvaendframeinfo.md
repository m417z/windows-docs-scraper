# AMVAEndFrameInfo structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AMVAEndFrameInfo** structure contains information for the [IAMVideoAccelerator::EndFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-endframe) method.

## Members

### `dwSizeMiscData`

Size, in bytes, of the buffer that **pMiscData** points to. The value must be 2.

### `pMiscData`

Pointer to a buffer that contains data for the video accelerator.

This buffer must contain a **WORD** value equal to the same surface index that passed to the corresponding [IAMVideoAccelerator::BeginFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-beginframe) method.

## Remarks

The buffer pointed to by **pMiscData** cannot contain pointer values, because their addresses will not be valid in kernel mode, where frame processing occurs.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IAMVideoAccelerator::EndFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-endframe)