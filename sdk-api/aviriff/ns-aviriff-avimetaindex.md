# AVIMETAINDEX structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The base structure for an AVI 2.0 index ('indx' format).

## Members

### `fcc`

A **FOURCC** code. The value is either 'indx' or '*nn*ix', where *nn* is the stream number.

### `cb`

The size of the structure, not including the initial 8 bytes.

### `wLongsPerEntry`

The size of each index entry, in 4-byte units.

### `bIndexSubType`

The index subtype. The meaning depends on the value of **bIndexType**.

### `bIndexType`

The index type.

| Value | Meaning |
| --- | --- |
| **AVI_INDEX_OF_INDEXES**<br><br>0x00 | Each index entry points to another index. Treat the **AVIMETAINDEX** structure as an [AVISUPERINDEX](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avisuperindex) structure. The value of **bIndexSubType** must be zero. |
| **AVI_INDEX_OF_CHUNKS**<br><br>0x01 | Each index entry points to a data chunk in the file. <br><br>* If **bIndexSubType** is 0, treat the **AVIMETAINDEX** structure as an [AVISTDINDEX](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avistdindex) structure. Each index entry is an [AVISTDINDEX_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/aviriff/ns-aviriff-avistdindex_entry) structure.<br>* If **bIndexSubType** is **AVI_INDEX_SUB_2FIELD**, the index is a field index chunk.<br><br>  **Note** DirectShow does not support field indexes. |
| **AVI_INDEX_IS_DATA**<br><br>0x80 | The **adwIndex** array contains a table of data, not a list of index entries. |

### `nEntriesInUse`

The number of valid entries in the **adwIndex** array.

### `dwChunkId`

A **FOURCC** that identifies the object that is indexed. If the indexed object is a stream, this member has the same meaning as the **dwChunkId** member of the [AVIOLDINDEX](https://learn.microsoft.com/previous-versions/ms779634(v=vs.85)) structure.

### `dwReserved`

The meaning of this member depends on the index type.

### `adwIndex`

An array of index entries. The format of this data depends on the index type.

## Remarks

For more information, see the *OpenDML AVI File Format Extensions*, published by the OpenDML AVI M-JPEG File Format Subcommittee. (This resource may not be available in some languages

and countries.)

## See also

[AVI RIFF File Reference](https://learn.microsoft.com/windows/desktop/DirectShow/avi-riff-file-reference)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)