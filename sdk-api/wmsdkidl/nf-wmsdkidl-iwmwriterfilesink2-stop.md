# IWMWriterFileSink2::Stop

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Stop** method stops recording at the specified time.

## Parameters

### `cnsStopTime` [in]

Stop time in 100-nanosecond units.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Because of interleaving of streams with slightly different time stamps at any particular point in the file, the actual stop time might not be exactly as specified in *cnsStopTime*. To increase the precision, call [IWMWriterFileSink3::SetControlStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-setcontrolstream).

## See also

[IWMWriterFileSink2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterfilesink2)

[IWMWriterFileSink2::Close](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink2-close)

[IWMWriterFileSink2::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink2-start)