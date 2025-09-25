# IWMStreamConfig2::SetTransportType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetTransportType** method sets the type of data communication protocol (reliable or unreliable) used for the stream.

## Parameters

### `nTransportType` [in]

One member of the [WMT_TRANSPORT_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_transport_type) enumeration type specifying the transport type for the stream.

## Return value

The method always returns S_OK.

## Remarks

The new value will not take effect in the profile until you call [IWMProfile::ReconfigStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-reconfigstream).

## See also

[IWMStreamConfig2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig2)

[IWMStreamConfig2::GetTransportType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig2-gettransporttype)