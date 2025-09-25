# IKEEXT_POLICY0 structure

## Description

The **IKEEXT_POLICY0** structure is used to store the IKE/AuthIP main mode negotiation policy.
[IKEEXT_POLICY1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_policy1) is available. For Windows 8, [IKEEXT_POLICY2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_policy2) is available.

## Members

### `softExpirationTime`

Unused parameter, always set this to 0.

### `numAuthenticationMethods`

Number of authentication methods.

### `authenticationMethods`

Array of acceptable authentication methods.

See [IKEEXT_AUTHENTICATION_METHOD0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method0) for more information.

### `initiatorImpersonationType`

Type of impersonation. Applies only to AuthIP.

See [IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type) for more information.

### `numIkeProposals`

Number of main mode proposals.

### `ikeProposals`

Array of main mode proposals.

See [IKEEXT_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_proposal0) for more information.

### `flags`

A combination of the following values.

| IKE/AuthIP policy flag | Meaning |
| --- | --- |
| **IKEEXT_POLICY_FLAG_DISABLE_DIAGNOSTICS** | Disable special diagnostics mode for IKE/Authip. This will prevent IKE/AuthIp from accepting unauthenticated notifications from peer, or sending MS_STATUS notifications to peer. |
| **IKEEXT_POLICY_FLAG_NO_MACHINE_LUID_VERIFY** | Disable SA verification of machine LUID. |
| **IKEEXT_POLICY_FLAG_NO_IMPERSONATION_LUID_VERIFY** | Disable SA verification of machine impersonation LUID.<br><br>Applicable only to AuthIP. |
| **IKEEXT_POLICY_FLAG_ENABLE_OPTIONAL_DH** | Allow the responder to accept any DH proposal, including no DH, regardless of what is configured in policy.<br><br>Applicable only to AuthIP. |

### `maxDynamicFilters`

Maximum number of dynamic IPsec filters per remote IP address and per
transport layer that is allowed to be added for any SA negotiated using
this policy.

Set this to 0 to disable dynamic filter addition. Dynamic filters are added by IKE/AuthIP on responder, when the QM traffic proposed by initiator is a subset of responder's traffic configuration.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)