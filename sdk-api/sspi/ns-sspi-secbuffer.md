# SecBuffer structure

## Description

The **SecBuffer** structure describes a buffer allocated by a transport application to pass to a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Members

### `cbBuffer`

Specifies the size, in bytes, of the buffer pointed to by the **pvBuffer** member.

### `BufferType`

Bit flags that indicate the type of buffer. **BufferType** must be one of the following flags.

| Value | Meaning |
| --- | --- |
| **SECBUFFER_ALERT**<br><br>17 (0x11) | The buffer contains an alert message. |
| **SECBUFFER_ATTRMASK**<br><br>4026531840 (0xF0000000) | The buffer contains a bitmask for a SECBUFFER_READONLY_WITH_CHECKSUM buffer. |
| **SECBUFFER_CHANNEL_BINDINGS**<br><br>14 (0xE) | The buffer contains channel binding information. |
| **SECBUFFER_CHANGE_PASS_RESPONSE**<br><br>15 (0xF) | The buffer contains a [DOMAIN_PASSWORD_INFORMATION](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-domain_password_information) structure. |
| **SECBUFFER_DATA**<br><br>1 (0x1) | The buffer contains common data. The security package can read and write this data, for example, to encrypt some or all of it. |
| **SECBUFFER_DTLS_MTU**<br><br>24 (0x18) | The buffer contains the setting for the maximum transmission unit (MTU) size for DTLS only. The default value is 1096 and the valid configurable range is between 200 and 64*1024. |
| **SECBUFFER_EMPTY**<br><br>0 (0x0) | This is a placeholder in the buffer array. The caller can supply several such entries in the array, and the security package can return information in them. For more information, see [SSPI Context Semantics](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-context-semantics). |
| **SECBUFFER_EXTRA**<br><br>5 (0x5) | The security package uses this value to indicate the number of extra or unprocessed bytes in a message. |
| **SECBUFFER_MECHLIST**<br><br>11 (0xB) | The buffer contains a protocol-specific list of [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs). It is not usually of interest to callers. |
| **SECBUFFER_MECHLIST_SIGNATURE**<br><br>12 (0xC) | The buffer contains a signature of a **SECBUFFER_MECHLIST** buffer. It is not usually of interest to callers. |
| **SECBUFFER_MISSING**<br><br>4 (0x4) | The security package uses this value to indicate the number of missing bytes in a particular message. The **pvBuffer** member is ignored in this type. |
| **SECBUFFER_PKG_PARAMS**<br><br>3 (0x3) | These are transport-to-package–specific parameters. For example, the NetWare redirector may supply the server [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly), while DCE RPC can supply an association **UUID**, and so on. |
| **SECBUFFER_PRESHARED_KEY**<br><br>22 (0x16) | The buffer contains the preshared key. The maximum allowed PSK buffer size is 256 bytes. |
| **SECBUFFER_PRESHARED_KEY_IDENTITY**<br><br>23 (0x17) | The buffer contains the preshared key identity. |
| **SECBUFFER_SRTP_MASTER_KEY_IDENTIFIER**<br><br>20 (0x14) | The buffer contains the SRTP master key identifier. |
| **SECBUFFER_SRTP_PROTECTION_PROFILES**<br><br>19 (0x13) | The buffer contains the list of SRTP protection profiles, in descending order of preference. |
| **SECBUFFER_STREAM_HEADER**<br><br>7 (0x7) | The buffer contains a protocol-specific header for a particular record. It is not usually of interest to callers. |
| **SECBUFFER_STREAM_TRAILER**<br><br>6 (0x6) | The buffer contains a protocol-specific trailer for a particular record. It is not usually of interest to callers. |
| **SECBUFFER_TARGET**<br><br>13 (0xD) | This flag is reserved. Do not use it. |
| **SECBUFFER_TARGET_HOST**<br><br>16 (0x10) | The buffer specifies the [service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPN) of the target.<br><br>This value is supported by the Digest security package when used with channel bindings.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECBUFFER_TOKEN**<br><br>2 (0x2) | The buffer contains the security token portion of the message. This is read-only for input parameters or read/write for output parameters. |
| **SECBUFFER_TOKEN_BINDING**<br><br>21 (0x15) | The buffer contains the supported token binding protocol version and key parameters, in descending order of preference. |
| **SECBUFFER_APPLICATION_PROTOCOLS**<br><br>18 | The buffer contains a list of application protocol IDs, one list per application protocol negotiation extension type to be enabled. |

In addition, **BufferType** can combine the following flags with any of the flags in the preceding table by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **SECBUFFER_READONLY**<br><br>2147483648 (0x80000000) | The buffer is read-only with no checksum. This flag is intended for sending header information to the security package for computing the checksum. The package can read this buffer, but cannot modify it. |
| **SECBUFFER_READONLY_WITH_CHECKSUM**<br><br>268435456 (0x10000000) | The buffer is read-only with a checksum. |

### `pvBuffer.size_is`

### `pvBuffer.size_is.cbBuffer`

### `pvBuffer`

A pointer to a buffer.

## See also

[SecBufferDesc](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secbufferdesc)