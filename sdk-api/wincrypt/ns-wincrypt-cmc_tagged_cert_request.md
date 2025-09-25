# CMC_TAGGED_CERT_REQUEST structure

## Description

The **CMC_TAGGED_CERT_REQUEST** structure is used in the
[CMC_TAGGED_REQUEST](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_tagged_request) structure.

## Members

### `dwBodyPartID`

**DWORD** identifying the tagged [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `SignedCertRequest`

A [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a signed request for a certificate.