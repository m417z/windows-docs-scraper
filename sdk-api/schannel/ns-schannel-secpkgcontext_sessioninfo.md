# SecPkgContext_SessionInfo structure

## Description

Specifies whether the session is a reconnection and retrieves a value that identifies the session.

## Members

### `dwFlags`

Bit flags that specify the type of session. The following value is defined.

| Value | Meaning |
| --- | --- |
| **SSL_SESSION_RECONNECT**<br><br>1 | The session is a reconnection. |

### `cbSessionId`

The size, in bytes, of the **rgbSessionId** array.

### `rgbSessionId`

An array of up to 32 bytes that identifies the session.

## See also

[QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw)