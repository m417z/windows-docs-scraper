# WMT_ATTR_DATATYPE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_ATTR_DATATYPE** enumeration defines the data type for a variably typed property.

## Constants

### `WMT_TYPE_DWORD:0`

The property is a 4-byte **DWORD** value.

### `WMT_TYPE_STRING:1`

The property is a null-terminated Unicode string.

### `WMT_TYPE_BINARY:2`

The property is an array of bytes.

### `WMT_TYPE_BOOL:3`

The property is a 4-byte Boolean value.

### `WMT_TYPE_QWORD:4`

The property is an 8-byte **QWORD** value.

### `WMT_TYPE_WORD:5`

The property is a 2-byte **WORD** value.

### `WMT_TYPE_GUID:6`

The property is a 128-bit (6-byte) GUID.

## See also

[Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes)

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)