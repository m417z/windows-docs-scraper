# TOC_ENTRY_DESCRIPTOR structure

## Description

The **TOC_ENTRY_DESCRIPTOR** structure holds descriptive information for an entry in a table of contents. An entry in a table of contents describes a portion of a media file. For example, an entry might describe a ten-second chunk of video that starts 90 seconds after the beginning of a video file.

## Members

### `qwStartTime`

The start time, in 100-nanosecond units, of the portion of a media file represented by an entry in a table of contents.

### `qwEndTime`

The end time, in 100-nanosecond units, of the portion of a media file represented by an entry in a table of contents.

### `qwStartPacketOffset`

Not used.

### `qwEndPacketOffset`

Not used.

### `qwRepresentativeFrameTime`

The presentation time, in 100-nanosecond units, of a frame that is a good representation of the entry. This frame could be used for a thumbnail image that represents the entry.

## See also

[Table of Contents Parser Structures](https://learn.microsoft.com/windows/desktop/medfound/toc-parser-structures)