# CRL_FIND_ISSUED_FOR_PARA structure

## Description

The **CRL_FIND_ISSUED_FOR_PARA** structure contains the certificate contexts of both a subject and a certificate issuer. For more information, see
[CertFindCRLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcrlinstore).

## Members

### `pSubjectCert`

A pointer to a subject's certificate context.

### `pIssuerCert`

A pointer to a certificate issuer's certificate context.