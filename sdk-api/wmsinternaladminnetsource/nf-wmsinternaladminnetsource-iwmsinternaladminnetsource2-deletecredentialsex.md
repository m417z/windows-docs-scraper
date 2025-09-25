# IWMSInternalAdminNetSource2::DeleteCredentialsEx

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DeleteCredentialsEx** method removes a password from the cache. This improved version of [IWMSInternalAdminNetSource::DeleteCredentials](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource-deletecredentials) uses the combination of realm, URL, and proxy use to identify the credentials. This is an improvement over using the realm by itself, which can easily be spoofed by malicious code.

## Parameters

### `bstrRealm` [in]

String containing the realm name. Realm names are supplied by servers to distinguish different levels of access to their files. Not all servers will have realm names, in which case the DNS name is used.

### `bstrUrl` [in]

String containing the URL to which the credentials apply.

### `fProxy` [in]

Boolean value that is True if the password applies when using a proxy server to access the site specified by *bstrUrl*.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMSInternalAdminNetSource2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource2)