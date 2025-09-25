# WTHelperCertIsSelfSigned function

## Description

[The **WTHelperCertIsSelfSigned** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For certificate verification, use the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) and [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) functions. For Microsoft [Authenticode](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) technology signature verification, use the .NET Framework.]

The **WTHelperCertIsSelfSigned** function checks whether a certificate is self-signed. This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

### `dwEncoding` [in]

A **DWORD** value that specifies the encoding types of the certificate to check. For information about possible encoding types, see [Certificate and Message Encoding Types](https://learn.microsoft.com/windows/desktop/SecCrypto/certificate-and-message-encoding-types).

### `pCert` [in]

A pointer to a [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) structure that contains information about the certificate to check.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.