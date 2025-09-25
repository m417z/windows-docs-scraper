# IPSEC_KEYING_POLICY1 structure

## Description

The structure defines an unordered set of keying modules that will be tried for IPsec.[IPSEC_KEYING_POLICY0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_keying_policy0) is available.

## Members

### `numKeyMods`

Type: **UINT32**

Number of keying modules in the array.

### `keyModKeys`

Type: **GUID***

Array of distinct keying modules.

### `flags`

Type: **UINT32**

Possible values:

| Value | Meaning |
| --- | --- |
| **IPSEC_KEYING_POLICY_FLAG_TERMINATING_MATCH** | Forces the use of a Kerberos proxy server when acting as initiator. |

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)