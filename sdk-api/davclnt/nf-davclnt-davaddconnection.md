# DavAddConnection function

## Description

Creates a secure connection to a WebDAV server or to a remote file or directory on a WebDAV server.

## Parameters

### `ConnectionHandle` [in, out]

A pointer to a variable that receives the connection handle.

### `RemoteName` [in]

A pointer to a **null**-terminated Unicode string that contains the path to the remote file or directory. This string must begin with the "https://" prefix.

### `UserName` [in, optional]

A pointer to a **null**-terminated Unicode string that contains the user name to be used for the connection. This parameter is optional and can be **NULL**.

### `Password` [in, optional]

A pointer to a **null**-terminated Unicode string that contains the password to be used for the connection. This parameter is optional and can be **NULL**.

### `ClientCert` [in]

A pointer to a buffer that contains the client certificate to be used for the connection. The certificate must be in a serialized form.

### `CertSize` [in]

Size, in bytes, of the client certificate.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

To close the connection, use the [DavDeleteConnection](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davdeleteconnection) function.

Use this function when you are connecting to a WebDAV server using the Secure Sockets Layer (SSL) protocol and therefore must specify a certificate. To connect to a WebDAV server without specifying a certificate, use a Windows networking function such as [WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) or [WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a).

## See also

[CertOpenSystemStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopensystemstorea)