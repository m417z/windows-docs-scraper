# IEnroll4::getCertContextFromResponseBlob

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **getCertContextFromResponseBlob** method retrieves the certificate from a [certification authority's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) response.This method was first defined by the [IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4) interface.

## Parameters

### `pblobResponse` [in]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that represents the response.

### `ppCertContext` [out]

A pointer to a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that receives the certificate retrieved from the response.

## Remarks

The response contained in *pblobResponse* must contain exactly one certificate; a child certificate cannot be present.

The response may be either a PKCS #7 or a full [Certificate Management over CMS](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CMC) response. However, to accept a full CMC response, the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) must support [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding of CMC structures.

## See also

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)