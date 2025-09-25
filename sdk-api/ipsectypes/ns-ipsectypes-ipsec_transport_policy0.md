# IPSEC_TRANSPORT_POLICY0 structure

## Description

The **IPSEC_TRANSPORT_POLICY0** structure stores the quick mode negotiation policy for transport mode IPsec.
[IPSEC_TRANSPORT_POLICY2](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_transport_policy2) is available.

## Members

### `numIpsecProposals`

Number of quick mode proposals in the policy.

### `ipsecProposals`

Array of quick mode proposals.

See [IPSEC_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_proposal0) for more information.

### `flags`

A combination of the following values.

| IPsec policy flag | Meaning |
| --- | --- |
| **IPSEC_POLICY_FLAG_ND_SECURE** | Do negotiation discovery in secure ring. |
| **IPSEC_POLICY_FLAG_ND_BOUNDARY** | Do negotiation discovery in the untrusted perimeter zone. |
| **IPSEC_POLICY_FLAG_NAT_ENCAP_ALLOW_PEER_BEHIND_NAT** | If set, IPsec expects that either the local or remote machine is behind a network address translation (NAT) device, but not both. This allows for less secure, but more flexible behavior. |
| **IPSEC_POLICY_FLAG_NAT_ENCAP_ALLOW_GENERAL_NAT_TRAVERSAL** | If set, IPsec expects default ports when either the local, the remote, or both machines are behind a NAT device. |
| **IPSEC_POLICY_FLAG_DONT_NEGOTIATE_SECOND_LIFETIME** | If set, Internet Key Exchange (IKE) will not send the ISAKMP attribute for 'seconds' lifetime during quick mode negotiation. |
| **IPSEC_POLICY_FLAG_DONT_NEGOTIATE_BYTE_LIFETIME** | If set, IKE will not send the ISAKMP attribute for 'byte' lifetime during quick mode negotiation. |

### `ndAllowClearTimeoutSeconds`

Timeout in seconds, after which the IPsec security association (SA) should stop accepting
packets coming in the clear. Used for negotiation discovery.

### `saIdleTimeout`

An [IPSEC_SA_IDLE_TIMEOUT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_idle_timeout0) structure that specifies the SA idle timeout in IPsec policy.

### `emPolicy`

The AuthIP extended mode authentication policy.

See [IKEEXT_EM_POLICY0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy0) for more information.

## See also

[IKEEXT_EM_POLICY0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy0)

[IPSEC_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_proposal0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)