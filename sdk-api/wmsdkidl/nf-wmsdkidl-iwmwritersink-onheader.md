# IWMWriterSink::OnHeader

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnHeader** method is called by the writer when the ASF header is ready for the sink.

## Parameters

### `pHeader` [in]

Pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface on an object containing the ASF header.

## Return value

This method is implemented by the application. It should always return S_OK.

## Remarks

The ASF header will always be sent before any data units, as the header is required for reading the content. The writer may send the header more than once for a given file. If possible, your sink should write any headers received.

## See also

[IWMWriterSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwritersink)