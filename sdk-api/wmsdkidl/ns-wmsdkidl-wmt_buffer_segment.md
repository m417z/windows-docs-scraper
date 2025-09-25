# WMT_BUFFER_SEGMENT structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_BUFFER_SEGMENT** structure contains the information needed to specify a segment in a buffer. It is used as a member of the [WMT_FILESINK_DATA_UNIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_filesink_data_unit) and [WMT_PAYLOAD_FRAGMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_payload_fragment) structures to specify segments of a packet.

## Members

### `pBuffer`

Pointer to a buffer object containing the buffer segment.

### `cbOffset`

The offset, in bytes, from the start of the buffer to the buffer segment.

### `cbLength`

The length, in bytes, of the buffer segment.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)