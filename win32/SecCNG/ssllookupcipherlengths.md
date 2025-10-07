# SslLookupCipherLengths function

The **SslLookupCipherLengths** function returns an [**NCRYPT\_SSL\_CIPHER\_LENGTHS**](https://www.bing.com/search?q=**NCRYPT/_SSL/_CIPHER/_LENGTHS**) structure that contains the header and trailer lengths of the input protocol, cipher suite, and key type.

## Parameters

*hSslProvider* \[in\]

The handle of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*dwProtocol* \[in\]

One of the [**CNG SSL Provider Protocol Identifier**](https://msdn.microsoft.com/library/Hh971257(v=VS.85).aspx) values.

*dwCipherSuite* \[in\]

One of the [**CNG SSL Provider Cipher Suite Identifier**](https://msdn.microsoft.com/library/Hh971253(v=VS.85).aspx) values.

*dwKeyType* \[in\]

One of the [**CNG SSL Provider Key Type Identifier**](https://msdn.microsoft.com/library/Hh971256(v=VS.85).aspx) values. For key types that are not [*elliptic curve cryptography*](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (ECC), set this parameter to zero.

*pCipherLengths* \[out\]

A pointer to a buffer to receive the [**NCRYPT\_SSL\_CIPHER\_LENGTHS**](https://www.bing.com/search?q=**NCRYPT/_SSL/_CIPHER/_LENGTHS**) structure.

*cbCipherLengths* \[in\]

The length, in bytes, of the buffer pointed to by the *pCipherLengths* parameter.

*dwFlags* \[in\]

This parameter is reserved for future use and must be set to zero.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | The *hSslProvider* parameter contains a pointer that is not valid.\ | | **NTE\_INVALID\_PARAMETER**

0x80090027L | The *pCipherLengths* parameter is set to **NULL** or the buffer length specified by the *cbCipherLengths* is too short.\ | | **NTE\_BAD\_FLAGS**

0x80090009L | The *dwFlags* parameter must be set to zero.\ | ## Remarks The **SslLookupCipherLengths** function is called for [*Transport Layer Security protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) (TLS) 1.1 or later conversations to query the header and trailer lengths for the requested protocol, cipher suite, and key type. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows 7 \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 R2 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |