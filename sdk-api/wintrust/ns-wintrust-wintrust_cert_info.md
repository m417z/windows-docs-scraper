# WINTRUST_CERT_INFO structure

## Description

[The **WINTRUST_CERT_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **WINTRUST_CERT_INFO** structure is used when calling
[WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) to verify a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context).

## Members

### `cbStruct`

Count of bytes in this structure.

### `pcwszDisplayName`

String with the name of the memory object pointed to by the **pbMem** member of the
[WINTRUST_BLOB_INFO](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_blob_info) structure.

### `psCertContext`

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) to be verified.

### `chStores`

The number of store handles in **pahStores**.

### `pahStores`

An array of open [certificate stores](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to add to the list of stores that the policy provider looks in to find certificates while building a trust chain.

### `dwFlags`

### `psftVerifyAsOf`