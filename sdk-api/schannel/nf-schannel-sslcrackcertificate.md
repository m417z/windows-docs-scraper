# SslCrackCertificate function

## Description

[The **SslCrackCertificate** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [CertCreateCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatecertificatecontext) function.]

Returns an [X509Certificate](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-x509certificate) structure with the information contained in the specified certificate [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Schannel.dll.

## Parameters

### `pbCertificate` [in]

The certificate BLOB from which to create the new [X509Certificate](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-x509certificate) structure.

### `cbCertificate` [in]

The length, in bytes, of the BLOB contained in the *pbCertificate* parameter.

### `dwFlags` [in]

Set this value to **CF_CERT_FROM_FILE** to specify that the certificate BLOB contained in the *pbCertificate* parameter is from a file.

### `ppCertificate` [out]

On return, receives the address of a pointer to the [X509Certificate](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-x509certificate) structure that this function creates.

When you have finished using the [X509Certificate](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-x509certificate) structure, free it by calling [SslFreeCertificate](https://learn.microsoft.com/windows/desktop/api/schannel/nf-schannel-sslfreecertificate).

## Return value

Returns nonzero if this function successfully created an [X509Certificate](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-x509certificate) structure or zero otherwise.