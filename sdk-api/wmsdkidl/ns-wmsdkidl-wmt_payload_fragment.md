# WMT_PAYLOAD_FRAGMENT structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_PAYLOAD_FRAGMENT** structure contains the information needed to extract a payload fragment from a buffer and identifies the payload to which the fragment belongs. An array of **WMT_PAYLOAD_FRAGMENT** structures is used as a member of the **WMT_FILESINK_DATA_UNIT** structure to provide access to each payload fragment in a packet.

## Members

### `dwPayloadIndex`

**DWORD** containing the payload index. This identifies the payload item to which this fragment belongs.

### `segmentData`

A **WMT_BUFFER_SEGMENT** structure specifying the buffer segment containing the payload fragment.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)