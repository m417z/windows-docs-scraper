# WMT_STREAM_SELECTION enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_STREAM_SELECTION** enumeration type defines the playback status of a stream.

## Constants

### `WMT_OFF:0`

No samples will be delivered for the stream.

### `WMT_CLEANPOINT_ONLY:1`

Only samples with [cleanpoints](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) will be delivered for the stream.

### `WMT_ON:2`

All samples will be delivered for the stream.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)