# AVISTDINDEX_ENTRY structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains one index entry for an AVI 2.0 standard index. This structure is contained in the [AVISTDINDEX](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avistdindex) structure.

## Members

### `dwOffset`

The offset, in bytes, to the start of the data. The offset is relative to the value of the **qwBaseOffset** member of the [AVISTDINDEX](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avistdindex). The value is the offset of the actual audio/video data in the chunk, not the offset of the start of the chunk.

### `dwSize`

The lower 31 bits contain the size of the data. The high bit is set to 1 if the frame is delta frame, or zero otherwise.

## Remarks

For more information, see the *OpenDML AVI File Format Extensions*, published by the OpenDML AVI M-JPEG File Format Subcommittee. (This resource may not be available in some languages

and countries.)

## See also

[AVI RIFF File Reference](https://learn.microsoft.com/windows/desktop/DirectShow/avi-riff-file-reference)

[AVISTDINDEX](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avistdindex)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)