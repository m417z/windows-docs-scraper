# WMT_FILESINK_DATA_UNIT structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_FILESINK_DATA_UNIT** structure is used by **IWMWriterFileSink3::OnDataUnitEx** to deliver information about a packet.

## Members

### `packetHeaderBuffer`

A [WMT_BUFFER_SEGMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_buffer_segment) structure specifying the buffer segment that contains the packet header.

### `cPayloads`

Count of payloads in this packet. This is also the number of elements in the array specified in **pPayloadHeaderBuffers**.

### `pPayloadHeaderBuffers`

Pointer to an array of **WMT_BUFFER_SEGMENT** structures. Each element specifies a buffer segment that contains a payload header. The number of elements is specified by **cPayloads**.

### `cPayloadDataFragments`

Count of payload data fragments in this packet. This is also the number of elements in the array pointed to by **pPayloadDataFragments**.

### `pPayloadDataFragments`

Pointer to an array of [WMT_PAYLOAD_FRAGMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_payload_fragment) structures. Each element specifies a buffer segment that contains a payload fragment. The number of elements is specified by **cPayloadDataFragments**.

## See also

[IWMWriterFileSink3::OnDataUnitEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-ondataunitex)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)