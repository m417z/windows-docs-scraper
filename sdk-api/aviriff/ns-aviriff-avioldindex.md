# AVIOLDINDEX structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AVIOLDINDEX** structure describes an AVI 1.0 index ('idx1' format). New AVI files should use an AVI 2.0 index ('indx' format).

## Members

### `fcc`

Specifies a FOURCC code. The value must be 'idx1'.

### `cb`

Specifies the size of the structure, not including the initial 8 bytes.

### `_avioldindex_entry`

### `_avioldindex_entry.dwChunkId`

### `_avioldindex_entry.dwFlags`

### `_avioldindex_entry.dwOffset`

### `_avioldindex_entry.dwSize`

### `aIndex`

Array of structures that contain the following members.

#### dwChunkId

Specifies a FOURCC that identifies a stream in the AVI file. The FOURCC must have the form 'xxyy' where *xx* is the stream number and *yy* is a two-character code that identifies the contents of the stream:

##### db (Uncompressed video frame)

##### dc (Compressed video frame)

##### pc (Palette change)

##### wb (Audio data)

#### dwFlags

Specifies a bitwise combination of zero or more of the following flags:

| Value | Meaning |
| --- | --- |
| **AVIIF_KEYFRAME** | The data chunk is a key frame. |
| **AVIIF_LIST** | The data chunk is a 'rec ' list. |
| **AVIIF_NO_TIME** | The data chunk does not affect the timing of the stream. For example, this flag should be set for palette changes. |

#### dwOffset

Specifies the location of the data chunk in the file. The value should be specified as an offset, in bytes, from the start of the 'movi' list; however, in some AVI files it is given as an offset from the start of the file.

#### dwSize

Specifies the size of the data chunk, in bytes.

## Remarks

This structure consists of the initial RIFF chunk (the **fcc** and **cb** members) followed by one index entry for each data chunk in the 'movi' list.

## See also

[AVI RIFF File Reference](https://learn.microsoft.com/windows/desktop/DirectShow/avi-riff-file-reference)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)