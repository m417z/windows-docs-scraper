# CRYPT_SMART_CARD_ROOT_INFO structure

## Description

The **CRYPT_SMART_CARD_ROOT_INFO** structure contains the smart card and session IDs associated with a certificate context. The certificate propagation service uses this structure to transfer smart card data between a smart card and a virtual root certificate store on a computer.

## Members

### `rgbCardID`

An array of bytes that specify the smart card IDs retrieved by using the [CryptGetProvParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgetprovparam) function with the *dwParam* parameter set to **PP_SMARTCARD_GUID**.

### `luid`

A [ROOT_INFO_LUID](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-root_info_luid) structure that specifies a session authentication ID from an access token.

## Remarks

The **luid** member value comes from the **AuthenticationId** member of the [TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics) structure retrieved by calling the [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function.

A certificate context can include an array of multiple **CRYPT_SMART_CARD_ROOT_INFO** structures, one for each [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) ([LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)) that the certificate propagation service has added to a root certificate.