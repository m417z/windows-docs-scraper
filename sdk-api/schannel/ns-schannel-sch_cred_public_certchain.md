# SCH_CRED_PUBLIC_CERTCHAIN structure

## Description

[The **SCH_CRED_PUBLIC_CERTCHAIN** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials) structure.]

The **SCH_CRED_PUBLIC_CERTCHAIN** structure contains a single certificate. A certification chain can be built from this certificate.

## Members

### `dwType`

Must always be set to SCH_CRED_X509_CERTCHAIN.

### `cbCertChain`

Size of the [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate, in bytes.

### `pCertChain`

Pointer to an X.509 leaf certificate.

## Remarks

This structure does not directly support certificate chains. If a server needs to use certificate chains, the intermediate certificates can be placed in the [certification authority's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and Schannel will automatically pick them up from there.