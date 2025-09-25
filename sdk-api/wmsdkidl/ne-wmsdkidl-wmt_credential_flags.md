# WMT_CREDENTIAL_FLAGS enumeration

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_CREDENTIAL_FLAGS** enumeration type contains values used in the [IWMCredentialCallback::AcquireCredentials](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcredentialcallback-acquirecredentials) method.

## Constants

### `WMT_CREDENTIAL_SAVE:0x1`

The application can set this flag to indicate that the caller should save the credentials in a persistent manner.

### `WMT_CREDENTIAL_DONT_CACHE:0x2`

The application can set this flag to indicate that the caller should not cache the credentials in memory.

### `WMT_CREDENTIAL_CLEAR_TEXT:0x4`

If this flag is set when the **AcquireCredentials** method is called, it indicates that the credentials will be sent over the network unencrypted. Applications should not set this flag.

### `WMT_CREDENTIAL_PROXY:0x8`

If this flag is set when the **AcquireCredentials** method is called, it indicates that the credentials are for a proxy server. Applications should not set this flag.

### `WMT_CREDENTIAL_ENCRYPT:0x10`

If this flag is set when the **AcquireCredentials** method is called, it indicates that the caller can handle encrypted credentials. When this flag is set, the application has the option of encrypting the credentials. To encrypt the credentials, use the **CryptProtectData** function, which is described in the Platform SDK documentation. The application can also return the credentials in plain text. In that case, the caller automatically encrypts the credentials, unless the WMT_CREDENTIAL_CLEAR_TEXT flag was set when the **AcquireCredentials** method was called.

If the application encrypts the credentials, it must set the WMT_CREDENTIAL_ENCRYPT flag before the method returns. If the application returns the credentials in clear text, clear this flag before the method returns.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/wmformat/enumeration-types)