# AVISUPERINDEX structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains an AVI 2.0 super index (index of indexes).

## Members

### `fcc`

A **FOURCC** code. The value must be 'indx'.

### `cb`

The size of the structure, not including the initial 8 bytes.

### `wLongsPerEntry`

The size of each index entry, in 4-byte units. The value must be 4.

### `bIndexSubType`

The index subtype. The value must be zero or **AVI_INDEX_SUB_2FIELD**.

### `bIndexType`

The index type. The value must be **AVI_INDEX_OF_INDEXES**.

### `nEntriesInUse`

The number of valid entries in the **adwIndex** array.

### `dwChunkId`

A **FOURCC** that identifies the object that is indexed.

### `dwReserved`

Reserved. Set the array elements to zero.

### `_avisuperindex_entry`

### `_avisuperindex_entry.qwOffset`

### `_avisuperindex_entry.dwSize`

### `_avisuperindex_entry.dwDuration`

### `aIndex`

An array of structures that contain the following members. The number of elements in the array is calculated from the value of **cb**.

#### qwOffset

The offset, in bytes, from the start of the file to the sub-index that this entry points to.

#### dwSize

The size of the sub-index, in bytes.

#### dwDuration

The duration of the file that is covered by the sub-index, in stream ticks.

## Remarks

For more information, see the *OpenDML AVI File Format Extensions*, published by the OpenDML AVI M-JPEG File Format Subcommittee. (This resource may not be available in some languages

and countries.)

## See also

[AVI RIFF File Reference](https://learn.microsoft.com/windows/desktop/DirectShow/avi-riff-file-reference)

[AVIMETAINDEX](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avimetaindex)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)