# SslImportMasterKey function

The **SslImportMasterKey** function performs a server-side [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) key exchange operation.

## Parameters

*hSslProvider* \[in\]

The handle to the SSL protocol provider instance.

*hPrivateKey* \[in\]

The handle to the [*private key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used in the exchange.

*phMasterKey* \[out\]

A pointer to the handle to receive the [*master key*](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly).

*dwProtocol* \[in\]

One of the [**CNG SSL Provider Protocol Identifier**](https://msdn.microsoft.com/library/Hh971257(v=VS.85).aspx) values.

*dwCipherSuite* \[in\]

One of the [**CNG SSL Provider Cipher Suite Identifiers**](https://msdn.microsoft.com/library/Hh971253(v=VS.85).aspx) values.

*pParameterList* \[in\]

A pointer to an array of **NCryptBuffer** buffers that contain information used as part of the key exchange operation. The precise set of buffers is dependent on the protocol and cipher suite that is used. At the minimum, the list will contain buffers that contain the client and server supplied random values.

*pbEncryptedKey* \[in\]

A pointer to a buffer that contains the encrypted premaster secret key encrypted with the [*public key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the server.

*cbEncryptedKey* \[in\]

The size, in bytes, of the *pbEncryptedKey* buffer.

*dwFlags* \[in\]

Set this parameter to **NCRYPT\_SSL\_SERVER\_FLAG** to indicate that this is a server call.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **NTE\_NO\_MEMORY**<br>0x8009000EL | Not enough memory is available to allocate necessary buffers.<br> |
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | One of the provided handles is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | The *phMasterKey* parameter is **NULL**.<br> |

## Remarks

This function decrypts the premaster secret, computes the SSL master secret, and returns a handle to this object to the caller. This master key can then be used to derive the SSL session key and finish the SSL handshake.

> [!Note]
> This function is used when the [*RSA*](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) key exchange algorithm is being used. When [*DH*](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) is used, then the server code calls [**SslGenerateMasterKey**](https://learn.microsoft.com/windows/win32/seccng/sslgeneratemasterkey) instead.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

