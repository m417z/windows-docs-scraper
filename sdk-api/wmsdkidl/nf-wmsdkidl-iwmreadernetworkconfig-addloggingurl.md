# IWMReaderNetworkConfig::AddLoggingUrl

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddLoggingUrl** method specifies a server that receive logging information from the reader object.

## Parameters

### `pwszUrl` [in]

Specifies a string containing the URL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Null value passed in to *pwszUrl* |
| **E_OUTOFMEMORY** | Unable to create or add the URL. |

## Remarks

When the reader streams content from a server, it automatically sends logging information to that server. Use the **AddLoggingUrl** method to specify additional servers that will receive the logging information.

## See also

[Client Logging](https://learn.microsoft.com/windows/desktop/wmformat/client)

[IWMReaderNetworkConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadernetworkconfig)