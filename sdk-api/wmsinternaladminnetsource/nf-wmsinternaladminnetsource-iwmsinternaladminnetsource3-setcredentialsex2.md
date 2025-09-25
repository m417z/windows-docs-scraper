# IWMSInternalAdminNetSource3::SetCredentialsEx2

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetCredentialsEx2** method adds a password to the cache. This improved version of **IWMSInternalAdminNetSource2::SetCredentialsEx** adds a flag (*fClearTextAuthentication*) that indicates whether credentials were sent in unencrypted form over the network.

## Parameters

### `bstrRealm` [in]

String containing the realm name. Realm names are supplied by servers to distinguish different levels of access to their files. Not all servers have realm names, in which case the DNS name should be used.

If *fProxy* is False, this realm refers to the host server. If *fProxy* is True, this realm refers to the proxy server.

### `bstrUrl` [in]

String containing the URL to which the credentials apply.

### `fProxy` [in]

Boolean value that is True if the password applies when using a proxy server to access the site specified by *bstrUrl*.

### `bstrName` [in]

String containing the user name.

### `bstrPassword` [in]

String containing the password.

### `fPersist` [in]

Boolean value that is True if these credentials should be permanently saved. If you set this to False, the credentials will only be persisted for the current session.

### `fConfirmedGood` [in]

Boolean value that is True if the server has confirmed the password as correct. You can cache the password before receiving verification from the server, in which case you should set this to False.

### `fClearTextAuthentication` [in]

Boolean value that is True if the credentials were obtained using an authentication scheme where credentials are sent over the network in an unencrypted form (such as HTTP Basic authentication).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMSInternalAdminNetSource3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource3)

[IWMSInternalAdminNetSource3::GetCredentialsEx2](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource3-getcredentialsex2)