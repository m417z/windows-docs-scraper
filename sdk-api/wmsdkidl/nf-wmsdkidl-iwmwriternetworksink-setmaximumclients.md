# IWMWriterNetworkSink::SetMaximumClients

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetMaximumClients** method sets the maximum number of clients that can connect to this sink. Call this method before streaming begins.

## Parameters

### `dwMaxClients` [in]

Specifies the maximum number of clients. The value must be from 0 to 50, inclusive. The default value is 5.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | Streaming has already begun, or the value of *dwMaxClients* is invalid. |

## See also

[IWMWriterNetworkSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriternetworksink)

[IWMWriterNetworkSink::GetMaximumClients](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriternetworksink-getmaximumclients)