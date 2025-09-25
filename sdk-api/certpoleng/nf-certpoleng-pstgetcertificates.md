# PstGetCertificates function

## Description

Retrieves certificate chains that specify certificates that can be used to authenticate a user on the specified server.

## Parameters

### `pTargetName` [in]

The name of the server to check.

### `cCriteria` [in]

The number of elements in the *rgpCriteria* array.

### `rgpCriteria` [in, optional]

A constant pointer to an array of [CERT_SELECT_CRITERIA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_select_criteria) structures that specify the criteria used to select certificate chains.

### `bIsClient` [in]

**TRUE** if the caller is the client; otherwise, **FALSE**.

### `pdwCertChainContextCount` [out]

The number of elements in the *ppCertChainContexts* array.

### `ppCertChainContexts` [out]

The address of a pointer to an array of [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structures that specifies the certificate chains of certificates that can be used to authenticate a user on the server specified by the *pTargetName* parameter.

## Return value

If the function succeeds, return **STATUS_SUCCESS**.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.