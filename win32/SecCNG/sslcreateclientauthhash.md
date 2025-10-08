# SslCreateClientAuthHash function

The **SslCreateClientAuthHash** function retrieves a handle to the handshake [*hash*](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) that is used for client authentication.

## Parameters

*hSslProvider* \[in\]

The handle of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*phHandshakeHash* \[out\]

A pointer to an **NCRYPT\_HASH\_HANDLE** variable to receive the hash handle.

*dwProtocol* \[in\]

One of the [**CNG SSL Provider Protocol Identifier**](https://msdn.microsoft.com/library/Hh971257(v=VS.85).aspx) values.

*dwCipherSuite* \[in\]

One of the [**CNG SSL Provider Cipher Suite Identifier**](https://msdn.microsoft.com/library/Hh971253(v=VS.85).aspx) values.

*pszHashAlgId* \[in\]

One of the [**CNG Algorithm Identifiers**](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-identifiers) values.

*dwFlags* \[in\]

This parameter is reserved for future use and must be set to zero.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | The *hSslProvider* parameter contains a pointer that is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | The *phHandshakeHash* parameter is set to **NULL**.<br> |
| **NTE\_NOT\_SUPPORTED**<br>0x80090029L | The selected function is not supported in the specified version of the interface.<br> |
| **NTE\_NO\_MEMORY**<br>0x8009000EL | Insufficient memory to allocate buffers.<br> |
| **NTE\_BAD\_FLAGS**<br>0x80090009L | The *dwFlags* parameter must be set to zero.<br> |

## Remarks

The **SslCreateClientAuthHash** function is called for [*Transport Layer Security protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) (TLS) 1.2 or later conversations to create hash objects that are used to hash handshake messages. It is called once for each possible [*hashing algorithm*](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) that can be used in the client authentication signature.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

