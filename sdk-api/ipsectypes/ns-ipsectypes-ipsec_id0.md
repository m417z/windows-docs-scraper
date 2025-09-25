# IPSEC_ID0 structure

## Description

The **IPSEC_ID0** structure contains information corresponding to identities that are authenticated by IPsec.

## Members

### `mmTargetName`

Optional main mode target service principal name (SPN). This is often the machine name.

### `emTargetName`

Optional extended mode target SPN.

### `numTokens`

Optional. Number of [IPSEC_TOKEN0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_token0) structures present in the **tokens** member.

### `tokens`

Optional array of [IPSEC_TOKEN0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_token0) structures.

### `explicitCredentials`

Optional handle to explicit credentials.

### `logonId`

Unused parameter. This should always be 0.

## Remarks

**IPSEC_ID0** is a specific implementation of IPSEC_ID. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)