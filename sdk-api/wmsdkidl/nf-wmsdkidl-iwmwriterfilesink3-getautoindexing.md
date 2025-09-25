# IWMWriterFileSink3::GetAutoIndexing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAutoIndexing** method retrieves the current state of automatic indexing for the file.

The writer object creates a time-based index for all new files by default. If you generate an ASF file using bit-rate mutual exclusion for audio content (multiple bit-rate audio), the resulting indexed file will not work with Windows Media Services version 4.1. If you want to stream your file using Windows Media Services 4.1, you must make sure that automatic indexing has been disabled before writing the file.

## Parameters

### `pfAutoIndexing` [out]

Pointer to a Boolean value that is True if automatic indexing is enabled for the file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pfAutoIndexing* is **NULL**. |

## See also

[IWMWriterFileSink3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterfilesink3)

[IWMWriterFileSink3::SetAutoIndexing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-setautoindexing)