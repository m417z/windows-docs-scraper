# WMT_FILESINK_MODE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_FILESINK_MODE** enumeration type defines the types of input accepted by the file sink.

## Constants

### `WMT_FM_SINGLE_BUFFERS:0x1`

The file sink accepts normal buffers through calls to [IWMWriterSink::OnDataUnit](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwritersink-ondataunit). This is the default behavior.

### `WMT_FM_FILESINK_DATA_UNITS:0x2`

The file sink accepts data as [WMT_FILESINK_DATA_UNIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_filesink_data_unit) structures delivered by [IWMWriterFileSink3::OnDataUnitEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-ondataunitex).

### `WMT_FM_FILESINK_UNBUFFERED:0x4`

The file sink accepts unbuffered data. A call to [IWMWriterFileSink3::SetUnbufferedIO](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-setunbufferedio) will succeed.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)