# SslComputeFinishedHash function

The **SslComputeFinishedHash** function computes the [*hash*](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) sent in the finished message of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) handshake.

## Parameters

*hSslProvider* \[in\]

The handle of the SSL protocol provider instance.

*hMasterKey* \[in\]

The handle of the [*master key*](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) object.

*hHandshakeHash* \[in\]

The handle of the hash of the handshake messages.

*pbOutput* \[out\]

A pointer to a buffer that receives the hash for the finish message.

*cbOutput* \[in\]

The length, in bytes, of the *pbOutput* buffer.

*dwFlags* \[in\]

One of the following constants.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------|
| **NCRYPT\_SSL\_CLIENT\_FLAG**

0x00000001 | Specifies that this is a client call.\ | | **NCRYPT\_SSL\_SERVER\_FLAG**

0x00000002 | Specifies that this is a server call.\ |

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

2148073510 (0x80090026) | One of the supplied handles is not valid.\ | ## Remarks The **SslComputeFinishedHash** function is one of three functions used to generate a hash to use during the SSL handshake. 1. The [**SslCreateHandshakeHash**](https://learn.microsoft.com/windows/win32/seccng/sslcreatehandshakehash) function is called to obtain a hash handle. 2. The [**SslHashHandshake**](https://learn.microsoft.com/windows/win32/seccng/sslhashhandshake) function is called any number of times with the hash handle to add data to the hash. 3. The **SslComputeFinishedHash** function is called with the hash handle to obtain the digest of the hashed data. The hash value is computed by hashing the master secret with a hash of all previous handshake messages sent or received. The value of *cbOutput* determines the length of the hash data. When the [*Transport Layer Security protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) (TLS) 1.0 protocol is used, this should always be 12 (bytes). For more information, see [The TLS Protocol Version 1.0](https://www.ietf.org/rfc/rfc2246.txt). ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |