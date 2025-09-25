# WMT_TIMECODE_EXTENSION_DATA structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_TIMECODE_EXTENSION_DATA** structure contains information needed for a single SMPTE time code sample extension. One of these structures will be attached to every video frame that requires a SMPTE time code.

## Members

### `wRange`

**WORD** specifying the range to which the time code belongs. See Remarks.

### `dwTimecode`

### `dwUserbits`

**DWORD** containing any information that the user desires. Typically, this member is used to store shot or take numbers, or other information pertinent to the production process.

### `dwAmFlags`

**DWORD** provided for maintaining any AM_TIMECODE flags that are present in source material. These flags are not used by any of the objects in the Windows Media Format SDK. For more information about AM_TIMECODE flags, refer to the SMPTE time code specification.

#### - Timecode

**DWORD** containing the time code. Time code is stored so that the hexadecimal value is read as if it were a decimal value. That is, the time code value 0x01133512 does not represent decimal 18035986, rather it specifies 1 hour, 13 minutes, 35 seconds, and 12 frames.

## Remarks

One of the more common SMPTE user scenarios is assembling a bunch of clips from their source reels into a prospective edit, and preserving the source reel time code in the edit. The time code in this type of file consists of a set of disjointed SMPTE ranges, where each range corresponds to the linear time code from its source reel.

Because these ranges are not guaranteed to be in any sort of time-related order (in other words, the first range may occur earlier in time than the second range), the concept of a range is supported in the Windows Media Format SDK time code index and interfaces. SMPTE time code MUST increase in time over a given range. Minor discontinuities within the range (such as dropped frames, or drop-frame counting) need not be marked within the range.

Ranges are guaranteed to be monotonically increasing (in other words, 0, 1, 2, 3, … ) with a WMV file. SMPTE time code values are guaranteed to be increasing within a given range in a WMV file, but not across ranges.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)