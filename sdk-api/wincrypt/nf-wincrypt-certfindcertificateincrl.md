# CertFindCertificateInCRL function

## Description

The **CertFindCertificateInCRL** function searches the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) for the specified certificate.

## Parameters

### `pCert` [in]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) of the certificate to be searched for in the CRL.

### `pCrlContext` [in]

A pointer to the
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) to be searched.

### `dwFlags` [in]

Reserved for future use. Must be set to zero.

### `pvReserved` [in, optional]

Reserved for future use. Must be set to zero.

### `ppCrlEntry` [out]

If the certificate is found in the CRL, this pointer is updated with a pointer to the entry. Otherwise, it is set to **NULL**. The returned entry is not allocated and must not be freed.

## Return value

**TRUE** if the list was searched; otherwise **FALSE**.