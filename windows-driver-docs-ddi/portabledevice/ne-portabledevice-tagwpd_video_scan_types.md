# tagWPD_VIDEO_SCAN_TYPES enumeration

## Description

The **WPD_VIDEO_SCAN_TYPES** enumeration type describes how the fields in a video file are encoded.

## Constants

### `WPD_VIDEO_SCAN_TYPE_UNUSED`

The scan type has not been defined for this video file, or is not applicable.

### `WPD_VIDEO_SCAN_TYPE_PROGRESSIVE`

A progressive scan video file.

### `WPD_VIDEO_SCAN_TYPE_FIELD_INTERLEAVED_UPPER_FIRST`

An interleaved video file where the fields alternate and the upper field (with line 1) is drawn first. For more information, see the Remarks section.

### `WPD_VIDEO_SCAN_TYPE_FIELD_INTERLEAVED_LOWER_FIRST`

An interleaved video file where the fields alternate and the lower field (with line 2) is drawn first. For more information, see **Remarks**, following this section.

### `WPD_VIDEO_SCAN_TYPE_FIELD_SINGLE_UPPER_FIRST`

An interleaved video file where the fields are sent as contiguous samples and the upper field (with line 1) is drawn first. For more information, see **Remarks**, following this section.

### `WPD_VIDEO_SCAN_TYPE_FIELD_SINGLE_LOWER_FIRST`

An interleaved video file where the fields are sent as contiguous samples and the lower field (with line 2) is sent first.

### `WPD_VIDEO_SCAN_TYPE_MIXED_INTERLACE`

A video file with a mix of interlacing modes.

### `WPD_VIDEO_SCAN_TYPE_MIXED_INTERLACE_AND_PROGRESSIVE`

A video file with a mix of interlaced and progressive modes.

## Remarks

This enumeration is used by the [WPD_VIDEO_SCAN_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597900(v=vs.85)) property.

There are two types of interleaved file formats that are specified by this enumeration. WPD_VIDEO_SCAN_TYPE_FIELD_INTERLEAVED refers to a file format where frames are delivered as they were scanned—fields alternate and data goes line by line, as shown here:

**Frame 1**

Field 1: Line 1

Field 2: Line 1

Field 1: Line 2

Field 2: Line 2

Field 1: Line 3

Field 2: Line 3

...

WPD_VIDEO_SCAN_TYPE_FIELD_SINGLE refers to a file format where each field is stored in a single block of scan lines, and fields are stored sequentially, as shown here:

**Frame 1**

Field 1: Line 1

Field 1: Line 2

Field 1: Line 3

...

Followed by

Field 2: Line 1

Field 2: Line 2

Field 2: Line 3

...

## See also

[Structures and Enumeration Types](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597672(v=vs.85))