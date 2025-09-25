# IPSEC_SA_AUTH_AND_CIPHER_INFORMATION0 structure

## Description

The **IPSEC_SA_AUTH_AND_CIPHER_INFORMATION0** structure stores information about the authentication and encryption algorithms of an IPsec security association (SA).

## Members

### `saCipherInformation`

Encryption algorithm information as specified by [IPSEC_SA_CIPHER_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_cipher_information0).

### `saAuthInformation`

Authentication algorithm information as specified by [IPSEC_SA_AUTH_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_auth_information0).

## Remarks

**IPSEC_SA_AUTH_AND_CIPHER_INFORMATION0** is a specific implementation of IPSEC_SA_AUTH_AND_CIPHER_INFORMATION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_SA_AUTH_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_auth_information0)

[IPSEC_SA_CIPHER_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_cipher_information0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)