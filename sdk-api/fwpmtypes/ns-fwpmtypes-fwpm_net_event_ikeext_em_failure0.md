# FWPM_NET_EVENT_IKEEXT_EM_FAILURE0 structure

## Description

The **FWPM_NET_EVENT_IKEEXT_EM_FAILURE0** structure contains information that describes an IKE Extended Mode (EM) failure.
[FWPM_NET_EVENT_IKEEXT_EM_FAILURE1](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_em_failure1) is available.

## Members

### `failureErrorCode`

Windows error code for the failure.

### `failurePoint`

An [IPSEC_FAILURE_POINT](https://learn.microsoft.com/windows/win32/api/ipsectypes/ne-ipsectypes-ipsec_failure_point) value that indicates the IPsec state when the failure occurred.

### `flags`

Flags for the failure event.

| Value | Meaning |
| ----- | ------- |
| FWPM_NET_EVENT_IKEEXT_EM_FAILURE_FLAG_MULTIPLE | Indicates that multiple IKE EM failure events have been reported. |

### `emState`

An [IKEEXT_EM_SA_STATE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_em_sa_state) value that indicates the EM state when the failure occurred.

### `saRole`

An [IKEEXT_SA_ROLE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_sa_role) value that specifies the SA role when the failure occurred.

### `emAuthMethod`

An [IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type) value that specifies the authentication method.

### `endCertHash`

SHA thumbprint hash of the end certificate corresponding to the failures that happen during building or validating certificate chains.

**IKEEXT_CERT_HASH_LEN** maps to 20.

### `mmId`

LUID for the Main Mode (MM) SA.

### `qmFilterId`

Quick Mode (QM) filter ID associated with this failure.

## See also

[IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type)

[IKEEXT_EM_SA_STATE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_em_sa_state)

[IKEEXT_SA_ROLE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_sa_role)

[IPSEC_FAILURE_POINT](https://learn.microsoft.com/windows/win32/api/ipsectypes/ne-ipsectypes-ipsec_failure_point)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)