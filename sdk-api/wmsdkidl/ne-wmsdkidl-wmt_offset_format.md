# WMT_OFFSET_FORMAT enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_OFFSET_FORMAT** enumeration type defines the types of offsets used in this SDK.

## Constants

### `WMT_OFFSET_FORMAT_100NS:0`

An offset into a file is specified by presentation time in 100-nanosecond units.

### `WMT_OFFSET_FORMAT_FRAME_NUMBERS`

An offset into a file is specified by frame number.

### `WMT_OFFSET_FORMAT_PLAYLIST_OFFSET`

An offset of playlist entries.

### `WMT_OFFSET_FORMAT_TIMECODE`

An offset into a file is specified by presentation time as identified by SMTPE time codes.

### `WMT_OFFSET_FORMAT_100NS_APPROXIMATE`

Used to specify approximate seeking. This type of offset seeks to the closest key frame prior to the time specified.

## Remarks

**WMT_OFFSET_FORMAT** is used as an input parameter to [IWMReaderAdvanced3::StartAtPosition](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced3-startatposition). The value passed specifies whether the reader should begin playback at a specified presentation time, frame number, or offset into a playlist.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)