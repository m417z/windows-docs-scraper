# SslGenerateMasterKey function

The **SslGenerateMasterKey** function computes the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) master secret key.

## Parameters

*hSslProvider* \[in\]

The handle to the SSL protocol provider instance.

*hPrivateKey* \[in\]

The handle to the [*private key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used in the exchange.

*hPublicKey* \[in\]

The handle to the [*public key*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used in the exchange.

*phMasterKey* \[out\]

A pointer to the handle to the generated [*master key*](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly).

*dwProtocol* \[in\]

One of the [**CNG SSL Provider Protocol Identifier**](https://msdn.microsoft.com/library/Hh971257(v=VS.85).aspx) values.

*dwCipherSuite* \[in\]

One of the [**CNG SSL Provider Cipher Suite Identifier**](https://msdn.microsoft.com/library/Hh971253(v=VS.85).aspx) values.

*pParameterList* \[in\]

A pointer to an array of **NCryptBuffer** buffers that contain information used as part of the key exchange operation. The precise set of buffers is dependent on the protocol and cipher suite that is used. At the minimum, the list will contain buffers that contain the client and server supplied random values.

*pbOutput* \[out\]

The address of a buffer that receives the premaster secret encrypted with the public key of the server. The *cbOutput* parameter contains the size of this buffer. If this parameter is **NULL**, this function returns the required size, in bytes, in the **DWORD** pointed to by the *pcbResult* parameter.

> [!Note]
> This buffer is used when performing a RSA key exchange.

*cbOutput* \[in\]

The size, in bytes, of the *pbOutput* buffer.

*pcbResult* \[out\]

A pointer to a **DWORD** value in which to place number of bytes written to the *pbOutput* buffer.

*dwFlags* \[in\]

Specifies whether this function is being used for client-side or server-side key exchange.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------|
| **NCRYPT\_SSL\_CLIENT\_FLAG**

0x00000001 | Specifies a client-side key exchange.\ | | **NCRYPT\_SSL\_SERVER\_FLAG**

0x00000002 | Specifies a server-side key exchange.\ |

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **NTE\_NO\_MEMORY**

0x8009000EL | Not enough memory is available to allocate necessary buffers.\ | | **NTE\_INVALID\_HANDLE**

0x80090026L | One of the provided handles is not valid.\ | | **NTE\_INVALID\_PARAMETER**

0x80090027L | The *phMasterKey* or *hPublicKey* parameter is not valid.\ | ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |