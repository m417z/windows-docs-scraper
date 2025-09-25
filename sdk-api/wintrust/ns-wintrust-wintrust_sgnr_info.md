# WINTRUST_SGNR_INFO structure

## Description

[The **WINTRUST_SGNR_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **WINTRUST_SGNR_INFO** structure is used when calling
[WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) to verify a
[CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_info) structure.

## Members

### `cbStruct`

Count of bytes in this structure.

### `pcwszDisplayName`

String with the name representing the signer to be checked.

### `psSignerInfo`

A pointer to a
[CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_info) structure that includes the [signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) to be verified.

### `chStores`

Number of store handles in **pahStores**.

### `pahStores`

An array of open [certificate stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to be added to the list of stores that the policy provider uses to find certificates while building a trust chain.