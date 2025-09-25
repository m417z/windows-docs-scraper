# IPSEC_TOKEN0 structure

## Description

The **IPSEC_TOKEN0** structure contains various information about an IPsec-specific access token.

## Members

### `type`

An [IPSEC_TOKEN_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_token_type) value that specifies the type of token.

### `principal`

An [IPSEC_TOKEN_PRINCIPAL](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_token_principal) value that specifies the token principal.

### `mode`

An [IPSEC_TOKEN_MODE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_token_mode) value that indicates in which mode the token was obtained.

### `token`

Handle to the access token. An **IPSEC_TOKEN_HANDLE** is of type **UINT64**.

## Remarks

**IPSEC_TOKEN0** is a specific implementation of IPSEC_TOKEN. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.