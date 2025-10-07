# SslGetCipherSuitePRFHashAlgorithm function

The **SslGetCipherSuitePRFHashAlgorithm** function returns the Cryptography API: Next Generation (CNG) Algorithm Identifier of the [*hashing algorithm*](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) that is used for the [*Transport Layer Security protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) (TLS) [*pseudo-random function*](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (PRF) for the input protocol, cipher suite, and key type.

## Parameters

*hSslProvider* \[in\]

The handle of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*dwProtocol* \[in\]

One of the [**CNG SSL Provider Protocol Identifier**](https://msdn.microsoft.com/library/Hh971257(v=VS.85).aspx) values.

*dwCipherSuite* \[in\]

One of the [**CNG SSL Provider Cipher Suite Identifier**](https://msdn.microsoft.com/library/Hh971253(v=VS.85).aspx) values.

*dwKeyType* \[in\]

One of the [**CNG SSL Provider Key Type Identifier**](https://msdn.microsoft.com/library/Hh971256(v=VS.85).aspx) values. For key types that are not [*elliptic curve cryptography*](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (ECC), set this parameter to zero.

*szPRFHash* \[out\]

One of the [**CNG Algorithm Identifiers**](https://learn.microsoft.com/windows/win32/seccng/cng-algorithm-identifiers) for the hash that will be used for the TLS PRF.

*dwFlags* \[in\]

This parameter is reserved for future use and must be set to zero.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | The *hSslProvider* parameter contains a pointer that is not valid.\ | | **NTE\_INVALID\_PARAMETER**

0x80090027L | The *szPRFHash* parameter is set to **NULL**.\ | | **NTE\_NOT\_SUPPORTED**

0x80090029L | The selected function is not supported in the specified version of the interface.\ | | **NTE\_BAD\_FLAGS**

0x80090009L | The *dwFlags* parameter must be set to zero.\ | ## Remarks This **SslGetCipherSuitePRFHashAlgorithm** function is called for TLS 1.2 or later conversations to query the hashing algorithm that will be used in the TLS PRF. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows 7 \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 R2 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |