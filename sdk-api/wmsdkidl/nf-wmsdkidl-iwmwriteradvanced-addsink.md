# IWMWriterAdvanced::AddSink

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddSink** method adds a writer sink to receive writer output. The Windows Media Format SDK supports *file sinks*, which create ASF files on disk; *network sinks*, which stream ASF content across a network; and *push sinks*, which deliver ASF content to other media servers. To create a sink object, call one of the following functions:

| Sink | Function |
| --- | --- |
| File sink | [WMCreateWriterFileSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-wmcreatewriterfilesink) |
| Network sink | [WMCreateWriterNetworkSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-wmcreatewriternetworksink) |
| Push sink | [WMCreateWriterPushSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-wmcreatewriterpushsink) |

New sinks must be added to the writer with this method before they can be used.

## Parameters

### `pSink` [in]

Pointer to an [IWMWriterSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwritersink) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pSink* parameter is **NULL**. |
| **NS_E_INVALID_STATE** | The writer is not in a configurable state. |

## Remarks

If you only need to write to a single file, you can let the writer object handle the creation and management of a default file sink. To use a default file sink, pass a file name to the writer by calling [IWMWriter::SetOutputFilename](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setoutputfilename).

## See also

[Adding Sinks to the Writer](https://learn.microsoft.com/windows/desktop/wmformat/adding-sinks-to-the-writer)

[IWMWriterAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced)

[IWMWriterAdvanced::GetSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsink)

[IWMWriterAdvanced::RemoveSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-removesink)