# PstValidate function

## Description

Validates the specified certificate.

## Parameters

### `pTargetName` [in, optional]

The name of the server. If the caller is not the client, this parameter is **NULL**.

### `bIsClient` [in]

**TRUE** if the caller is the client; otherwise, **FALSE**.

### `pRequestedIssuancePolicy` [in, optional]

A pointer to a [CERT_USAGE_MATCH](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_usage_match) structure that specifies identifiers that the certificate must match to be validated.

### `phAdditionalCertStore` [in, optional]

A handle to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that contains additional certificates used for the authentication.

### `pCert` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that specifies the certificate to validate.

### `pProvGUID` [out, optional]

A pointer to a **GUID** structure that receives the [security support provider](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSP) used for the authentication.

## Return value

If the function succeeds, return **STATUS_SUCCESS**.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.