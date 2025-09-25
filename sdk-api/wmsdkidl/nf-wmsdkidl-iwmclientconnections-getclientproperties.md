# IWMClientConnections::GetClientProperties

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetClientProperties** method retrieves information, including the IP address and protocol, about a connected client.

## Parameters

### `dwClientNum` [in]

**DWORD** containing the client's index number.

### `pClientProperties` [out]

Pointer to a [WM_CLIENT_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_client_properties) structure.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | Streaming has not yet begun. |
| **E_INVALIDARG** | *pcClientProperties* has been passed a null value. |
| **NS_E_INVALID_CLIENT** | A client number larger than the number of clients has been passed in.<br><br>OR<br><br>Failed to get client information for unspecified reason. |

## See also

[IWMClientConnections Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmclientconnections)