# ALLOCATOR_PROPERTIES structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The ALLOCATOR_PROPERTIES structure describes an allocator's count, size, alignment, and prefix properties.

## Members

### `cBuffers`

Number of buffers created by the allocator.

### `cbBuffer`

Size of each buffer in bytes, excluding any prefix.

### `cbAlign`

Alignment of the buffer; buffer start will be aligned on a multiple of this value.

### `cbPrefix`

Each buffer is preceded by a prefix of this many bytes.

## Remarks

The [IMediaSample::GetPointer](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-getpointer) method returns a pointer to the beginning of the buffer, not including the prefix bytes designated by *cbPrefix*.

The alignment is applied to the prefix data, if any. If a nonzero prefix is used, the beginning of the prefix is aligned according to *cbAlign*.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)