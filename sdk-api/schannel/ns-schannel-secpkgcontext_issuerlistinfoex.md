# SecPkgContext_IssuerListInfoEx structure

## Description

The **SecPkgContext_IssuerListInfoEx** structure holds a list of trusted [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CAs). This structure is used by the Schannel [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function.

This attribute is supported only by the Schannel [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP).

This attribute is available only to client applications and can be queried only after a call to the [InitializeSecurityContext (Schannel)](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) function returns the value **SEC_E_INCOMPLETE_CREDENTIALS**.

## Members

### `aIssuers`

A pointer to
an array of [CERT_NAME_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structures that contains a list of the names of CAs that the server trusts.

When you have finished using the data in this array, free it by calling the [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

### `cIssuers`

The number of names in **aIssuers**.