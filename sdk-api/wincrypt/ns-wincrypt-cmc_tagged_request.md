# CMC_TAGGED_REQUEST structure

## Description

The **CMC_TAGGED_REQUEST** structure is used in the
[CMC_DATA_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_data_info) structures to request a certificate. In the future, it may be used for other requests.

## Members

### `dwTaggedRequestChoice`

**DWORD** identifying the union member to be used. CMC_TAGGED_CERT_REQUEST_CHOICE can be used to select the CMC_TAGGED_CERT_REQUEST.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.pTaggedCertRequest`

A pointer to a
[CMC_TAGGED_CERT_REQUEST](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_tagged_cert_request) structure containing the signed [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Remarks

Additional members of the union may be defined in future versions.