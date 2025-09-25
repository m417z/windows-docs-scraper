# IWMWriter::SetOutputFilename

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetOutputFilename** method specifies the name of the file to be written.

## Parameters

### `pwszFilename` [in]

Pointer to a wide-character null-terminated string containing the file name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The method failed for an unspecified reason. |
| **NS_E_INVALID_STATE** | The writer is not in a configurable state. |

## Remarks

This method is equivalent to creating a file sink with an index of 0 and adding it through a call to [IWMWriterAdvanced::AddSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-addsink), and is provided for convenience.

You can obtain a pointer to the [IWMWriterSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwritersink) interface of the file sink created by this method by calling [IWMWriterAdvanced::GetSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsink). This is important because the writer does not deliver status messages for the sinks associated with it. You can call **QueryInterface** on **IWMWriterSink** to obtain a pointer to the [IWMRegisterCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistercallback), which is used to set an [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback method to which the sink will deliver status messages.

## See also

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[Using File Sinks](https://learn.microsoft.com/windows/desktop/wmformat/using-file-sinks)