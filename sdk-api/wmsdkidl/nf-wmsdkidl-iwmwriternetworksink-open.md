# IWMWriterNetworkSink::Open

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Open** method opens a network port, and starts listening for network connections.

## Parameters

### `pdwPortNum` [in, out]

On input, pointer to a variable that specifies the port number. Set this value to zero if you want the network sink to select a suitable port. On output, the variable receives the port number that was used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pdwPortNum* parameter is **NULL**. |
| **NS_E_INVALID_REQUEST** | The network sink is already open. |
| **NS_E_NETWORK_RESOURCE_FAILURE** | The port number specified is already in use. |

## Remarks

This method binds the port. To release the port, call [IWMWriterNetworkSink::Close](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriternetworksink-close).

See the Remarks and Example Code sections for [IWMWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-beginwriting).

## See also

[IWMWriterNetworkSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriternetworksink)