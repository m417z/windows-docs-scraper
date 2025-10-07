# SslHashHandshake function

The **SslHashHandshake** function returns a handle to the handshake hash.

## Parameters

*hSslProvider* \[in\]

The handle to the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*hHandshakeHash* \[in, out\]

The handle to the hash object.

*pbInput* \[out\]

The address of a buffer that contains the data to be hashed.

*cbInput* \[in\]

The size, in bytes, of the *pbInput* buffer.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

## Remarks

The **SslHashHandshake** function is one of three functions used to generate a hash to use during the SSL handshake.

1. The [**SslCreateHandshakeHash**](https://learn.microsoft.com/windows/win32/seccng/sslcreatehandshakehash) function is called to obtain a hash handle.
2. The **SslHashHandshake** function is called any number of times with the hash handle to add data to the hash.
3. The [**SslComputeFinishedHash**](https://learn.microsoft.com/windows/win32/seccng/sslcomputefinishedhash) function is called with the hash handle to obtain the digest of the hashed data.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

