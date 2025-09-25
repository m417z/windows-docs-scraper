# PstMapCertificate function

## Description

Retrieves a structure that specifies information that can be used to create a user token associated with the specified certificate.

## Parameters

### `pCert` [in]

A constant pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that specifies the certificate for which to obtain token information.

### `pTokenInformationType` [out]

A pointer to a value of the [LSA_TOKEN_INFORMATION_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ne-ntsecpkg-lsa_token_information_type) enumeration that indicates the type of structure pointed to by the *ppTokenInformation* parameter.

### `ppTokenInformation` [out]

The address of a pointer to a structure that specifies information that can be used to create a user token.

## Return value

If the function succeeds, return **STATUS_SUCCESS**.

If the function fails, return an **NTSTATUS** code that indicates the reason it failed.