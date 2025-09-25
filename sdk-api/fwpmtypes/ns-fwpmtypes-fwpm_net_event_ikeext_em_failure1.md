# FWPM_NET_EVENT_IKEEXT_EM_FAILURE1 structure

## Description

The **FWPM_NET_EVENT_IKEEXT_EM_FAILURE1** structure contains information that describes an IKE Extended mode (EM) failure.
[FWPM_NET_EVENT_IKEEXT_EM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_em_failure0) is available.

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
| FWPM_NET_EVENT_IKEEXT_EM_FAILURE_FLAG_BENIGN | Indicates that IKE EM failure events have been reported, but that the events are benign. |

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

### `localPrincipalNameForAuth`

Name of the EM local security principal.

### `remotePrincipalNameForAuth`

Name of the EM remote security principal.

### `numLocalPrincipalGroupSids`

Number of groups in the local security principal's token.

### `localPrincipalGroupSids`

Groups in the local security principal's token.

### `numRemotePrincipalGroupSids`

Number of groups in the remote security principal's token.

### `remotePrincipalGroupSids`

Groups in the remote security principal's token.

### `saTrafficType`

Type of traffic for which the embedded quick mode was being negotiated.

## See also

[IKEEXT_AUTHENTICATION_METHOD_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_method_type)

[IKEEXT_EM_SA_STATE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_em_sa_state)

[IKEEXT_SA_ROLE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_sa_role)

[IPSEC_FAILURE_POINT](https://learn.microsoft.com/windows/win32/api/ipsectypes/ne-ipsectypes-ipsec_failure_point)

[IPSEC_TRAFFIC_TYPE](https://learn.microsoft.com/windows/win32/api/ipsectypes/ne-ipsectypes-ipsec_traffic_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)