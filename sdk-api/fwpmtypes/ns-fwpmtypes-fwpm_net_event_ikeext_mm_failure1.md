# FWPM_NET_EVENT_IKEEXT_MM_FAILURE1 structure

## Description

The **FWPM_NET_EVENT_IKEEXT_MM_FAILURE1** structure contains information that describes an IKE/AuthIP Main Mode (MM) failure.
[FWPM_NET_EVENT_IKEEXT_MM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_mm_failure0) is available.

## Members

### `failureErrorCode`

Windows error code for the failure.

### `failurePoint`

An [IPSEC_FAILURE_POINT](https://learn.microsoft.com/windows/win32/api/ipsectypes/ne-ipsectypes-ipsec_failure_point) value that indicates the IPsec state when the failure occurred.

### `flags`

Flags for the failure event.

| Value | Meaning |
| ----- | ------- |
| FWPM_NET_EVENT_IKEEXT_MM_FAILURE_FLAG_BENIGN | Indicates that the failure was benign or expected. |
| FWPM_NET_EVENT_IKEEXT_MM_FAILURE_FLAG_MULTIPLE | Indicates that multiple failure events have been reported. |

### `keyingModuleType`

An [IKEEXT_KEY_MODULE_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_key_module_type) value that specifies the type of keying module.

### `mmState`

An [IKEEXT_MM_SA_STATE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_mm_sa_state) value that indicates the Main Mode state when the failure occurred.

### `saRole`

An [IKEEXT_SA_ROLE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_sa_role) value that specifies the security association (SA) role when the failure occurred.

### `mmAuthMethod`

An [IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type) value that specifies the authentication method.

### `endCertHash`

SHA thumbprint hash of the end certificate corresponding to the failures that happen during building or validating certificate chains.

**IKEEXT_CERT_HASH_LEN** maps to 20.

### `mmId`

LUID for the MM SA.

### `mmFilterId`

Main mode filter ID.

### `localPrincipalNameForAuth`

Name of the MM local security principal.

### `remotePrincipalNameForAuth`

Name of the MM remote security principal.

### `numLocalPrincipalGroupSids`

Number of groups in the local security principal's token.

### `localPrincipalGroupSids`

Groups in the local security principal's token.

### `numRemotePrincipalGroupSids`

Number of groups in the remote security principal's token.

### `remotePrincipalGroupSids`

Groups in the remote security principal's token.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)