# IPSEC_TUNNEL_POLICY2 structure

## Description

The **IPSEC_TUNNEL_POLICY2** structure stores the quick mode negotiation policy for tunnel mode IPsec.
[IPSEC_TUNNEL_POLICY1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy1) is available. For Windows Vista, [IPSEC_TUNNEL_POLICY0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy0) is available.

## Members

### `flags`

Type: **UINT32**

A combination of the following values.

| IPsec policy flag | Meaning |
| --- | --- |
| **IPSEC_POLICY_FLAG_ND_SECURE** | Do negotiation discovery in secure ring. |
| **IPSEC_POLICY_FLAG_ND_BOUNDARY** | Do negotiation discovery in the untrusted perimeter zone. |
| **IPSEC_POLICY_FLAG_CLEAR_DF_ON_TUNNEL** | Clear the "DontFragment" bit on the outer IP header of an IPsec tunneled packet. |
| **IPSEC_POLICY_FLAG_DONT_NEGOTIATE_SECOND_LIFETIME** | If set, Internet Key Exchange (IKE) will not send the ISAKMP attribute for 'seconds' lifetime during quick mode negotiation. |
| **IPSEC_POLICY_FLAG_DONT_NEGOTIATE_BYTE_LIFETIME** | If set, IKE will not send the ISAKMP attribute for 'byte' lifetime during quick mode negotiation. |
| **IPSEC_POLICY_FLAG_ENABLE_V6_IN_V4_TUNNELING** | Negotiate IPv6 inside IPv4 IPsec tunneling. Applicable only for tunnel mode policy, and supported only by IKEv2. |
| **IPSEC_POLICY_FLAG_ENABLE_SERVER_ADDR_ASSIGNMENT** | Enable calls to RAS VPN server for address assignment. Applicable only for tunnel mode policy, and supported only by IKEv2. |
| **IPSEC_POLICY_FLAG_TUNNEL_ALLOW_OUTBOUND_CLEAR_CONNECTION** | Allow outbound connections to bypass the tunnel policy. Applicable only for tunnel mode policy on a tunnel gateway. Do not set on a tunnel client. |
| **IPSEC_POLICY_FLAG_TUNNEL_BYPASS_ALREADY_SECURE_CONNECTION** | Allow ESP or UDP 500/4500 traffic to bypass the tunnel. Applicable only for tunnel mode policy. |
| **IPSEC_POLICY_FLAG_TUNNEL_BYPASS_ICMPV6** | Allow ICMPv6 traffic to bypass the tunnel. Applicable only for tunnel mode policy. |
| **IPSEC_POLICY_FLAG_KEY_MANAGER_ALLOW_DICTATE_KEY** | Allow key dictation for quick mode policy. Applicable only for AuthIP policy. |
| **IPSEC_POLICY_FLAG_KEY_MANAGER_ALLOW_NOTIFY_KEY** | Allow key notification for quick mode policy. Applicable for AuthIP/IKE/IKEv2 policy. |
| **IPSEC_POLICY_FLAG_POINT_TO_SITE_TUNNEL** | Specifies that the IPsec policy is for Point-to-Site VPN tunnels, used by individual clients connecting to a virtual network. |

### `numIpsecProposals`

Type: **UINT32**

 Number of quick mode proposals in the policy.

### `ipsecProposals`

Type: [IPSEC_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_proposal0)*

Array of quick mode proposals.

### `tunnelEndpoints`

Type: [IPSEC_TUNNEL_ENDPOINTS2](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints2)

Tunnel endpoints of the IPsec security association (SA) generated from this policy.

### `saIdleTimeout`

Type: [IPSEC_SA_IDLE_TIMEOUT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_idle_timeout0)

Specifies the SA idle timeout in IPsec policy.

### `emPolicy`

Type: [IKEEXT_EM_POLICY2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy2)*

The AuthIP extended mode authentication policy.

### `fwdPathSaLifetime`

Type: **UINT32**

The forward path SA lifetime indicating the length of time for this connection.

## See also

[IKEEXT_EM_POLICY2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy2)

[IPSEC_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_proposal0)

[IPSEC_SA_IDLE_TIMEOUT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_idle_timeout0)

[IPSEC_TUNNEL_ENDPOINTS2](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints2)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)