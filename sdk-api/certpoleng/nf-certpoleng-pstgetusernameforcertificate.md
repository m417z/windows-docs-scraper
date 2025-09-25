# PstGetUserNameForCertificate function

## Description

Retrieves the user name associated with the specified certificate.

## Parameters

### `pCertContext` [in]

A constant pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that specifies the certificate for which to obtain the user name.

### `UserName` [out]

The user name associated with the certificate specified by the *pCertContext* parameter.

## Return value

If the function succeeds, return **STATUS_SUCCESS**.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.