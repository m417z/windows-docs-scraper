# IPSEC_SA_BUNDLE0 structure

## Description

The **IPSEC_SA_BUNDLE0** structure is used to store information about an IPsec security association (SA) bundle.
[IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) is available.

## Members

### `flags`

A combination of the following values.

| IPsec SA bundle flag | Meaning |
| --- | --- |
| **IPSEC_SA_BUNDLE_FLAG_ND_SECURE** | Negotiation discovery is enabled in secure ring. |
| **IPSEC_SA_BUNDLE_FLAG_ND_BOUNDARY** | Negotiation discovery in enabled in the untrusted perimeter zone. |
| **IPSEC_SA_BUNDLE_FLAG_ND_PEER_NAT_BOUNDARY** | Peer is in untrusted perimeter zone ring and a NAT is in the way. Used with negotiation discovery. |
| **IPSEC_SA_BUNDLE_FLAG_GUARANTEE_ENCRYPTION** | Indicates that this is an SA for connections that require guaranteed encryption. |
| **IPSEC_SA_BUNDLE_FLAG_NLB** | Indicates that this is an SA to an NLB server. |
| **IPSEC_SA_BUNDLE_FLAG_NO_MACHINE_LUID_VERIFY** | Indicates that this SA should bypass machine LUID verification. |
| **IPSEC_SA_BUNDLE_FLAG_NO_IMPERSONATION_LUID_VERIFY** | Indicates that this SA should bypass impersonation LUID verification. |
| **IPSEC_SA_BUNDLE_FLAG_NO_EXPLICIT_CRED_MATCH** | Indicates that this SA should bypass explicit credential handle matching. |
| **IPSEC_SA_BUNDLE_FLAG_ALLOW_NULL_TARGET_NAME_MATCH** | Allows an SA formed with a peer name to carry traffic that does not have an associated peer target. |
| **IPSEC_SA_BUNDLE_FLAG_CLEAR_DF_ON_TUNNEL** | Clears the **DontFragment** bit on the outer IP header of an IPsec-tunneled packet. This flag is applicable only to tunnel mode SAs. |
| **IPSEC_SA_BUNDLE_FLAG_ASSUME_UDP_CONTEXT_OUTBOUND** | Default encapsulation ports (4500 and 4000) can be used when matching this SA with packets on outbound connections that do not have an associated IPsec-NAT-shim context. |
| **IPSEC_SA_BUNDLE_FLAG_ND_PEER_BOUNDARY** | Peer has negotiation discovery enabled, and is on a perimeter network. |

### `lifetime`

Lifetime of all the SAs in the bundle as specified by [IPSEC_SA_LIFETIME0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_lifetime0).

### `idleTimeoutSeconds`

Timeout in seconds after which the SAs in the bundle will idle out (due to traffic inactivity) and expire.

### `ndAllowClearTimeoutSeconds`

Timeout in seconds, after which the IPsec SA should stop accepting
packets coming in the clear.

Used for negotiation discovery.

### `ipsecId`

Pointer to an [IPSEC_ID0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_id0) structure that contains optional IPsec identity info.

### `napContext`

Network Access Protection (NAP) peer credentials information.

### `qmSaId`

SA identifier used by IPsec when choosing the SA to expire. For an IPsec SA pair, the **qmSaId** must be the same between the initiating and responding machines and across inbound and outbound SA bundles. For different IPsec pairs, the **qmSaId** must be different.

### `numSAs`

Number of SAs in the bundle. The only possible values are 1 and 2. Use 2 only when specifying AH + ESP SAs.

### `saList`

Array of IPsec SAs in the bundle. For AH + ESP SAs, use index [0] for ESP SA and index [1] for AH SA.

See [IPSEC_SA0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa0) for more information.

### `keyModuleState`

Optional keying module specific information as specified by [IPSEC_KEYMODULE_STATE0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_keymodule_state0).

### `ipVersion`

IP version as specified by [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version).

### `peerV4PrivateAddress`

Available when **ipVersion** is **FWP_IP_VERSION_V4**. If peer is behind a network address translation (NAT) device, this member stores the peer's
private address.

### `mmSaId`

Use this ID to correlate this IPsec SA with the IKE SA that generated it.

### `pfsGroup`

 Specifies whether Quick Mode perfect forward secrecy (PFS) was enabled for
this SA, and if so, contains the Diffie-Hellman group that was used for
PFS.

See [IPSEC_PFS_GROUP](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_pfs_group) for more information.

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[IPSEC_KEYMODULE_STATE0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_keymodule_state0)

[IPSEC_PFS_GROUP](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_pfs_group)

[IPSEC_SA0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa0)

[IPSEC_SA_LIFETIME0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_lifetime0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)