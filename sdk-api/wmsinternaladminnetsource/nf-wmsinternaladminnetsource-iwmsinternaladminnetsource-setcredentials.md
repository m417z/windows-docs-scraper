# IWMSInternalAdminNetSource::SetCredentials

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetCredentials** method adds a password to the cache.

This method has been superseded by [IWMSInternalAdminNetSource3::SetCredentialsEx2](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource3-setcredentialsex2). The methods of **IWMSInternalAdminNetSource3** are much more secure than the password caching methods in **IWMSInternalAdminNetSource** and should be used if available.

## Parameters

### `bstrRealm` [in]

String containing the realm name. Realm names are supplied by servers to distinguish different levels of access to their files. Not all servers have realm names, in which case the DNS name should be used.

### `bstrName` [in]

String containing the user name.

### `bstrPassword` [in]

String containing the password.

### `fPersist` [in]

Boolean value that is True if these credentials should be permanently saved. If you set this to False, the credentials will be saved only for the current session.

### `fConfirmedGood` [in]

Boolean value that is True if the server has confirmed the password as correct. You can cache the password before receiving verification from the server, in which case you should set this to False.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMSInternalAdminNetSource Interface](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nn-wmsinternaladminnetsource-iwmsinternaladminnetsource)

[IWMSInternalAdminNetSource::GetCredentials](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource-getcredentials)

[IWMSInternalAdminNetSource::SetCredentialFlags](https://learn.microsoft.com/windows/desktop/api/wmsinternaladminnetsource/nf-wmsinternaladminnetsource-iwmsinternaladminnetsource-setcredentialflags)