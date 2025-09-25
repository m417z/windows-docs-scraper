# IWMSInternalAdminNetSource3::GetCredentialsEx2

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCredentialsEx2** method retrieves a cached password. This improved version of **IWMSInternalAdminNetSource2::GetCredentialsEx** adds a flag (*fClearTextAuthentication*) that indicates whether credentials were sent in unencrypted form over the network.

## Parameters

### `bstrRealm` [in]

String containing the realm name. Realm names are supplied by servers to distinguish different levels of access to their files. Not all servers have realm names, in which case the DNS name is used.

If *fProxy* is False, this realm refers to the host server. If *fProxy* is True, this realm refers to the proxy server.

### `bstrUrl` [in]

String containing the URL to which the credentials apply.

### `fProxy` [in]

Boolean value that is True if the password applies when using a proxy server to access the site specified by *bstrUrl*.

### `fClearTextAuthentication` [in]

Boolean value that is True if the cached credentials were previously sent over the network in an unencrypted form.

### `pdwUrlPolicy` [out]

Pointer to a **DWORD** containing one member of the [NETSOURCE_URLCREDPOLICY_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/ne-wmsinternaladminnetsource-netsource_urlcredpolicy_settings) enumeration type. This value is based on the user's network security settings and determines whether your application can automatically log in to sites for the user if you have credentials cached.

### `pbstrName` [out]

Pointer to a string containing the user name.

### `pbstrPassword` [out]

Pointer to a string containing the password.

### `pfConfirmedGood` [out]

Boolean value that is True if the password was cached after it was confirmed as correct by the server.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMSInternalAdminNetSource3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource3)

[IWMSInternalAdminNetSource3::SetCredentialsEx2](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource3-setcredentialsex2)