# SslCreateEphemeralKey function

The **SslCreateEphemeralKey** function creates an ephemeral key for use during the authentication that occurs during the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) handshake.

## Parameters

*hSslProvider* \[in\]

The handle of the SSL protocol provider instance.

*phEphemeralKey* \[out\]

The handle of the ephemeral key.

*dwProtocol* \[in\]

One of the [**CNG SSL Provider Protocol Identifier**](https://msdn.microsoft.com/library/Hh971257(v=VS.85).aspx) values.

*dwCipherSuite* \[in\]

One of the [**CNG SSL Provider Cipher Suite Identifier**](https://msdn.microsoft.com/library/Hh971253(v=VS.85).aspx) values.

*dwKeyType* \[in\]

One of the [**CNG SSL Provider Key Type Identifier**](https://msdn.microsoft.com/library/Hh971256(v=VS.85).aspx) values. Set this parameter to zero for key types that are not [*elliptic curve cryptography*](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (ECC).

*dwKeyBitLen* \[in\]

The length, in bits, of the key.

*pbParams* \[in\]

A pointer to a buffer to contain parameters for the key that is to be created. If a [*Diffie-Hellman (ephemeral) key-exchange algorithm*](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DHE) cipher suite is not used, set the *pbParams* parameter to **NULL** and the *cbParams* parameter to zero.

*cbParams* \[in\]

The length, in bytes, of the data in the *pbParams* buffer.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------|
| **NTE\_NO\_MEMORY**<br>0x8009000EL | There is insufficient memory to allocate the buffer.<br> |
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | The *hSslProvider* handle is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | One of the supplied parameters is not valid.<br> |

## Remarks

When using a DHE cipher suite, the internal SSL implementation passes server *p* and *g* parameters to the **SslCreateEphemeralKey** function in the *pbParams* and *cbParams* parameters.

The format of the data in the *pbParams* buffer is the same as that used when setting the [**BCRYPT\_DH\_PARAMETERS**](https://learn.microsoft.com/windows/win32/seccng/cng-property-identifiers) property, and it starts with a [**BCRYPT\_DH\_PARAMETER\_HEADER**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/ns-bcrypt-bcrypt_dh_parameter_header) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

