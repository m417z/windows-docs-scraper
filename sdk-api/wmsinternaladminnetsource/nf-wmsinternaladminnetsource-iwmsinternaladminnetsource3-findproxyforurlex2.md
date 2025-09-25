# IWMSInternalAdminNetSource3::FindProxyForURLEx2

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **FindProxyForURLEx2** method finds a proxy server name and port to use for the user.

## Parameters

### `bstrProtocol` [in]

String containing the protocol for which to find the proxy server. Typically, this is either "http" or "mms".

### `bstrHost` [in]

String containing the DNS name, or IP address, of the server with which you want to communicate. Depending upon the server, the proxy might be different.

### `bstrUrl` [in]

String containing the full URL of the site to which you want to connect.

### `pfProxyEnabled` [out]

Pointer to a Boolean value that is set to True if the user has enabled a proxy that applies to the specified protocol, host, and site.

### `pbstrProxyServer` [out]

Pointer to a string containing the proxy server DNS name.

### `pdwProxyPort` [out]

Pointer to a **DWORD** containing the proxy port number.

### `pqwProxyContext` [in, out]

**QWORD** representing the proxy server returned. You can make multiple calls to **FindProxyForURL** to find all configured proxy servers. On your first call, set the context to zero. When the call returns, the context is set to a value representing the proxy for which information was returned. On the next call, set the context to the context value retrieved on the first call. Continue this process until the call returns S_FALSE.

This method has internal algorithms that determine how it looks for proxy servers. You can override this and make it find the proxy server set by the client's Web browser, by setting the context to 3.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | When calling this method multiple times to find all proxies configured, this value is returned when there are no more configured proxy servers. |

## See also

[IWMSInternalAdminNetSource3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource3)