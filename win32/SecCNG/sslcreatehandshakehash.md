# SslCreateHandshakeHash function

The **SslCreateHandshakeHash** function obtains a hash handle that is used to hash handshake messages.

## Parameters

*hSslProvider* \[in\]

The handle of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*phHandshakeHash* \[out\]

A hash handle that can be passed to other SSL provider functions.

*dwProtocol* \[in\]

One of the [**CNG SSL Provider Protocol Identifier**](https://msdn.microsoft.com/library/Hh971257(v=VS.85).aspx) values.

> [!Note]
> This function is not used with the SSL 2.0 protocol.

*dwCipherSuite* \[in\]

One of the [**CNG SSL Provider Cipher Suite Identifier**](https://msdn.microsoft.com/library/Hh971253(v=VS.85).aspx) values.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------|
| **NTE\_NO\_MEMORY**<br>0x8009000EL | There is insufficient memory to allocate the hash buffer.<br> |
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | The *hSslProvider* handle is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | The *phHandshakeHash* is null.<br> |

## Remarks

The **SslCreateHandshakeHash** function is one of three functions used to generate a hash to use during the SSL handshake.

1. The **SslCreateHandshakeHash** function is called to obtain a hash handle.
2. The [**SslHashHandshake**](https://learn.microsoft.com/windows/win32/seccng/sslhashhandshake) function is called any number of times with the hash handle to add data to the hash.
3. The [**SslComputeFinishedHash**](https://learn.microsoft.com/windows/win32/seccng/sslcomputefinishedhash) function is called with the hash handle to obtain the digest of the hashed data.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

