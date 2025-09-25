# IWMCredentialCallback::AcquireCredentials

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AcquireCredentials** method acquires the credentials of the user, to verify that the user has permission to access a remote site.

## Parameters

### `pwszRealm` [in]

Pointer to a wide-character null-terminated string that contains the name of the realm.

### `pwszSite` [in]

Pointer to a wide-character null-terminated string containing the name of the site. The site is the name of the remote server.

### `pwszUser` [in, out]

Pointer to a buffer for the user name. The application should copy the user name into this buffer. When this method is first called, the buffer is empty. If the method is called again — for example, if the user typed his or her credentials incorrectly — the buffer may contain the name from the previous invocation.

### `cchUser` [in]

Specifies the size of the *pwszUser* buffer, in number of wide characters.

### `pwszPassword` [in, out]

Pointer to a buffer for the password. The application should copy the user's password into this buffer.

### `cchPassword` [in]

Specifies the size of the *pwszPassword* buffer, in number of wide characters.

### `hrStatus` [in]

Specifies an **HRESULT** return code.

### `pdwFlags` [in, out]

Pointer to a **DWORD** containing a bitwise **OR** of zero or more flags from the [WMT_CREDENTIAL_FLAGS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_credential_flags) enumeration type. On input, the caller sets whichever flags are relevant. On output, the application should clear the flags that were set by the caller, and set any additional flags, as appropriate. For details, see **WMT_CREDENTIAL_FLAGS**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method is used when a request for a remote URL requires authentication.

The reader object calls the **AcquireCredentials** method on the application to retrieve the user name and password of the user.

## See also

[Authentication](https://learn.microsoft.com/windows/desktop/wmformat/authentication)

[IWMCredentialCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcredentialcallback)