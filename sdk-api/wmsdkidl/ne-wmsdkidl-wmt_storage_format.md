# WMT_STORAGE_FORMAT enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_STORAGE_FORMAT** enumeration type defines the file types that can be manipulated with this SDK.

## Constants

### `WMT_Storage_Format_MP3:0`

The file is encoded in MP3 format.

### `WMT_Storage_Format_V1`

The file is encoded in Windows Media Format.

## Remarks

Storage format MP3 is supported for reading, but not writing.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)