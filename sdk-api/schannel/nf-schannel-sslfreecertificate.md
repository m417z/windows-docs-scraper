# SslFreeCertificate function

## Description

[The **SslFreeCertificate** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.]

Frees a certificate that was allocated by a previous call to the [SslCrackCertificate](https://learn.microsoft.com/windows/desktop/api/schannel/nf-schannel-sslcrackcertificate) function.

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Schannel.dll.

## Parameters

### `pCertificate` [in]

The certificate to free.

## See also

[SslCrackCertificate](https://learn.microsoft.com/windows/desktop/api/schannel/nf-schannel-sslcrackcertificate)