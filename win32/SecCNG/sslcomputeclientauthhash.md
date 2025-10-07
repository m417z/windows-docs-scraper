# SslComputeClientAuthHash function

The **SslComputeClientAuthHash** function computes a [*hash*](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) to use during [*certificate*](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) authentication.

## Parameters

*hSslProvider* \[in\]

The handle of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*hMasterKey* \[in\]

The handle of the [*master key*](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) object.

*hHandshakeHash* \[in\]

The handle of the hash of the handshake computed so far.

*pszAlgId* \[in\]

A pointer to a null-terminated Unicode string that identifies the requested [*cryptographic algorithm*](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This can be one of the standard [**CNG Algorithm Identifiers**](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-identifiers) or the identifier for another registered algorithm.

*pbOutput* \[out\]

The address of a buffer that receives the [*key BLOB*](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly). The *cbOutput* parameter contains the size of this buffer. If this parameter is **NULL**, this function will place the required size, in bytes, in the **DWORD** pointed to by the *pcbResult* parameter.

*cbOutput* \[in\]

The length, in bytes, of the *pbOutput* buffer.

*pcbResult* \[out\]

A pointer to a **DWORD** value that specifies the length, in bytes, of the hash written to the *pbOutput* buffer.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | One of the supplied handles is not valid.\ | ## Remarks The **SslComputeClientAuthHash** function computes the hash that is sent in the certificate verification message of the SSL handshake. The hash value is computed by creating a hash that contains the master secret with a hash of all previous handshake messages sent or received. The manner in which the hash is computed depends on the protocol and cipher suite used. In addition, the hash depends on the type of client authentication key used; the *pszAlgId* parameter indicates the type of key used for client authentication. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |