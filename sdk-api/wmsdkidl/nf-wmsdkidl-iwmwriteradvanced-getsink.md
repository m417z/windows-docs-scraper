# IWMWriterAdvanced::GetSink

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetSink** method retrieves a writer sink object. Used in conjunction with [IWMWriterAdvanced::GetSinkCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsinkcount), this method can be used to enumerate the sinks associated with a writer object.

## Parameters

### `dwSinkNum` [in]

**DWORD** containing the sink number (its index). This is a number between 0 and one less than the total number of sinks associated with the file as obtained with **IWMWriterAdvanced::GetSinkCount**.

### `ppSink` [out]

Pointer to a pointer to an [IWMWriterSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwritersink) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Either the *ppSink* parameter is **NULL**, or the *dwSinkNum* parameter is greater than the number of sinks. |

## Remarks

You can use **GetSink** to gain access to the file sink that is automatically created when you call [IWMWriter::SetOutputFilename](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setoutputfilename). If you are only writing to the automatically created file sink, it will always be sink number 0.

## See also

[Enumerating Sinks](https://learn.microsoft.com/windows/desktop/wmformat/enumerating-sinks)

[IWMWriterAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced)

[IWMWriterAdvanced::AddSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-addsink)

[IWMWriterAdvanced::GetSinkCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsinkcount)

[IWMWriterAdvanced::RemoveSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-removesink)