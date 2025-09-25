# IKEEXT_POLICY1 structure

## Description

The **IKEEXT_POLICY1** structure is used to store the IKE/AuthIP main mode negotiation policy.
[IKEEXT_POLICY0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_policy0) is available.

## Members

### `softExpirationTime`

Lifetime of the IPsec soft SA, in seconds. The caller must set this to 0.

### `numAuthenticationMethods`

Number of authentication methods.

### `authenticationMethods`

Array of acceptable authentication methods.

See [IKEEXT_AUTHENTICATION_METHOD1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method1) for more information.

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
| **IKEEXT_POLICY_FLAG_NO_IMPERSONATION_LUID_VERIFY** | Disable SA verification of machine impersonation LUID. |
| **IKEEXT_POLICY_FLAG_ENABLE_OPTIONAL_DH** | Allow the responder to accept any DH proposal, including no DH, regardless of what is configured in policy. This flag is valid only if AuthIP is used. |

### `maxDynamicFilters`

Maximum number of dynamic IPsec filters per remote IP address and per
transport layer that is allowed to be added for any SA negotiated using
this policy.

Set this to 0 to disable dynamic filter addition. Dynamic filters are added by IKE/AuthIP on responder, when the QM traffic proposed by initiator is a subset of responder's traffic configuration.

### `retransmitDurationSecs`

The number of seconds for which IKEv2 SA negotiation packets will be retransmitted before the SA times out. The caller must set this to at least 120 seconds.

## See also

[IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type)

[IKEEXT_AUTHENTICATION_METHOD1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method1)

[IKEEXT_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_proposal0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)