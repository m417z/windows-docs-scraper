# IPSEC_TUNNEL_POLICY0 structure

## Description

The **IPSEC_TUNNEL_POLICY0** structure stores the quick mode negotiation policy for tunnel mode IPsec.
[IPSEC_TUNNEL_POLICY2](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy2) is available.

## Members

### `flags`

A combination of the following values.

| IPsec policy flag | Meaning |
| --- | --- |
| **IPSEC_POLICY_FLAG_ND_SECURE** | Do negotiation discovery in secure ring. |
| **IPSEC_POLICY_FLAG_ND_BOUNDARY** | Do negotiation discovery in the untrusted perimeter zone. |
| **IPSEC_POLICY_FLAG_CLEAR_DF_ON_TUNNEL** | Clear the "DontFragment" bit on the outer IP header of an IPsec tunneled packet. |
| **IPSEC_POLICY_FLAG_DONT_NEGOTIATE_SECOND_LIFETIME** | If set, Internet Key Exchange (IKE) will not send the ISAKMP attribute for 'seconds' lifetime during quick mode negotiation. |
| **IPSEC_POLICY_FLAG_DONT_NEGOTIATE_BYTE_LIFETIME** | If set, IKE will not send the ISAKMP attribute for 'byte' lifetime during quick mode negotiation. |

### `numIpsecProposals`

Number of quick mode proposals in the policy.

### `ipsecProposals`

Array of quick mode proposals.

See [IPSEC_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_proposal0) for more information.

### `tunnelEndpoints`

Tunnel endpoints of the IPsec security association (SA) generated from this policy.

See [IPSEC_TUNNEL_ENDPOINTS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints0) for more information.

### `saIdleTimeout`

An [IPSEC_SA_IDLE_TIMEOUT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_idle_timeout0) structure that specifies the SA idle timeout in IPsec policy.

### `emPolicy`

The AuthIP extended mode authentication policy.

See [IKEEXT_EM_POLICY0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy0) for more information.

## See also

[IKEEXT_EM_POLICY0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy0)

[IPSEC_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_proposal0)

[IPSEC_SA_IDLE_TIMEOUT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_idle_timeout0)

[IPSEC_TUNNEL_ENDPOINTS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)