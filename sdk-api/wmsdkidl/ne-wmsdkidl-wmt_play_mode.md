# WMT_PLAY_MODE enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_PLAY_MODE** enumeration type defines the playback options of the reader.

## Constants

### `WMT_PLAY_MODE_AUTOSELECT:0`

The reader will select the most appropriate play mode based on the location of the content.

### `WMT_PLAY_MODE_LOCAL:1`

The reader will read files from a local storage location.

### `WMT_PLAY_MODE_DOWNLOAD:2`

The reader will download files from network locations.

### `WMT_PLAY_MODE_STREAMING:3`

The reader will stream files from network locations.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)

[IWMReaderAdvanced2::GetDownloadProgress](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-getdownloadprogress)

[IWMReaderAdvanced2::GetPlayMode](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-getplaymode)

[IWMReaderAdvanced2::SaveFileAs](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-savefileas)

[IWMReaderAdvanced2::SetPlayMode](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-setplaymode)