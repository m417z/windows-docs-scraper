# PstGetTrustAnchors function

## Description

Retrieves a list of [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CAs) trusted by the specified server.

## Parameters

### `pTargetName` [in]

The name of the server to check.

### `cCriteria` [in]

The number of elements in the *rgpCriteria* array.

### `rgpCriteria` [in, optional]

A constant pointer to an array of [CERT_SELECT_CRITERIA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_select_criteria) structures that specify the criteria used to select certificate chains.

### `ppTrustedIssuers` [out]

A pointer to an array of [SecPkgContext_IssuerListInfoEx](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_issuerlistinfoex) structures that receive the CAs trusted by the server specified by the *pTargetName* parameter.

## Return value

If the function succeeds, return STATUS_SUCCESS.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.