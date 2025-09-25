# IWMWriterAdvanced::GetSinkCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetSinkCount** method retrieves the number of writer sinks associated with the writer object. To obtain a pointer to an interface of an individual sink, call [IWMWriterAdvanced::GetSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsink) using a sink number between 0 and one less than the count returned by this method.

## Parameters

### `pcSinks` [out]

DWORD indicating the total number of sinks associated with the writer object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pcSinks* is **NULL**. |

## Remarks

If you specify a file by calling [IWMWriter::SetOutputFilename](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setoutputfilename), the writer object will automatically create a file sink and add it to the writer. That sink will be included in the count retrieved by this method.

## See also

[Enumerating Sinks](https://learn.microsoft.com/windows/desktop/wmformat/enumerating-sinks)

[IWMWriterAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced)

[IWMWriterAdvanced::GetSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsink)