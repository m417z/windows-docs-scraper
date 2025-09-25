# IWMWriterFileSink3::SetAutoIndexing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAutoIndexing** method enables or disables automatic indexing of the file.

## Parameters

### `fDoAutoIndexing` [in]

Boolean value that is True to automatically index the file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The header has already been received |

## Remarks

The state of automatic indexing must be set before the header is processed. After the header has been processed, any call to **SetAutoIndexing** results in an error.

Files are indexed by default. To disable indexing, you must call this method, passing False as the parameter.

If you generate an ASF file using bit-rate mutual exclusion for audio content (multiple bit-rate audio), the resulting indexed file will not work with Windows Media Services version 4.1. If you want to stream your file using Windows Media Services 4.1, you must disable automatic indexing before writing the file.

## See also

[IWMWriterFileSink3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterfilesink3)

[IWMWriterFileSink3::GetAutoIndexing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-getautoindexing)

[Working with Indexes](https://learn.microsoft.com/windows/desktop/wmformat/working-with-indexes)