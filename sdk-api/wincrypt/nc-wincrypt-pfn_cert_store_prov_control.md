# PFN_CERT_STORE_PROV_CONTROL callback function

## Description

The **CertStoreProvControl** callback function supports the **CertControlStore** API. All of the API's parameters are passed straight through to the callback. For details, see
[CertControlStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcontrolstore).

## Parameters

### `hStoreProv` [in, out]

**HCERTSTOREPROV** handle to a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) passed from the call to [CertControlStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcontrolstore).

### `dwFlags` [in]

Passed from the call to [CertControlStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcontrolstore).

### `dwCtrlType` [in]

Control action to be taken. Passed from the call to [CertControlStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcontrolstore).

### `pvCtrlPara` [in, optional]

A pointer to a buffer whose structure and content is determined by the values of *dwFlags* and *dwCtrlType*. Passed from the call to [CertControlStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcontrolstore).

## Return value

Returns **TRUE** if the function succeeds or **FALSE** if it fails.