# AVIMAINHEADER structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AVIMAINHEADER** structure defines global information in an AVI file.

## Members

### `fcc`

Specifies a FOURCC code. The value must be 'avih'.

### `cb`

Specifies the size of the structure, not including the initial 8 bytes.

### `dwMicroSecPerFrame`

Specifies the number of microseconds between frames. This value indicates the overall timing for the file.

### `dwMaxBytesPerSec`

Specifies the approximate maximum data rate of the file. This value indicates the number of bytes per second the system must handle to present an AVI sequence as specified by the other parameters contained in the main header and stream header chunks.

### `dwPaddingGranularity`

Specifies the alignment for data, in bytes. Pad the data to multiples of this value.

### `dwFlags`

Contains a bitwise combination of zero or more of the following flags:

| Value | Meaning |
| --- | --- |
| **AVIF_COPYRIGHTED** | Indicates the AVI file contains copyrighted data and software. When this flag is used, software should not permit the data to be duplicated. |
| **AVIF_HASINDEX** | Indicates the AVI file has an index. |
| **AVIF_ISINTERLEAVED** | Indicates the AVI file is interleaved. |
| **AVIF_MUSTUSEINDEX** | Indicates that application should use the index, rather than the physical ordering of the chunks in the file, to determine the order of presentation of the data. For example, this flag could be used to create a list of frames for editing. |
| **AVIF_WASCAPTUREFILE** | Indicates the AVI file is a specially allocated file used for capturing real-time video. Applications should warn the user before writing over a file with this flag set because the user probably defragmented this file. |

### `dwTotalFrames`

Specifies the total number of frames of data in the file.

### `dwInitialFrames`

Specifies the initial frame for interleaved files. Noninterleaved files should specify zero. If you are creating interleaved files, specify the number of frames in the file prior to the initial frame of the AVI sequence in this member.

To give the audio driver enough audio to work with, the audio data in an interleaved file must be skewed from the video data. Typically, the audio data should be moved forward enough frames to allow approximately 0.75 seconds of audio data to be preloaded. The **dwInitialRecords** member should be set to the number of frames the audio is skewed. Also set the same value for the **dwInitialFrames** member of the [AVISTREAMHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/avifmt/ns-avifmt-avistreamheader) structure in the audio stream header.

### `dwStreams`

Specifies the number of streams in the file. For example, a file with audio and video has two streams.

### `dwSuggestedBufferSize`

Specifies the suggested buffer size for reading the file. Generally, this size should be large enough to contain the largest chunk in the file. If set to zero, or if it is too small, the playback software will have to reallocate memory during playback, which will reduce performance. For an interleaved file, the buffer size should be large enough to read an entire record, and not just a chunk.

### `dwWidth`

Specifies the width of the AVI file in pixels.

### `dwHeight`

Specifies the height of the AVI file in pixels.

### `dwReserved`

Reserved. Set this array to zero.

## Remarks

The header file Vfw.h defines a **MainAVIHeader** structure that is equivalent to this structure, but omits the **fcc** and **cb** members.

## See also

[AVI RIFF File Reference](https://learn.microsoft.com/windows/desktop/DirectShow/avi-riff-file-reference)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)