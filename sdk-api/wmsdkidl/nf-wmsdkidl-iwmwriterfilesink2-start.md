# IWMWriterFileSink2::Start

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Start** method starts recording at the specified time.

## Parameters

### `cnsStartTime` [in]

Start time in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The requested start time precedes the last stop time. |
| **E_OUTOFMEMORY** | Not enough memory to complete the task. |

## Remarks

It is not necessary to call this method unless the sink has been stopped. The sink automatically starts (at time 0) when it is added to the writer by using [IWMWriterAdvanced::AddSink](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-addsink).

Because of interleaving of streams with slightly different time stamps at any particular point in the file, the actual start time might not be exactly as specified in *cnsStartTime*. To increase the precision, call [IWMWriterFileSink3::SetControlStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-setcontrolstream).

## See also

[IWMWriterFileSink2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterfilesink2)

[IWMWriterFileSink2::Close](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink2-close)

[IWMWriterFileSink2::Stop](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink2-stop)