# IPSEC_DOSP_STATISTICS0 structure

## Description

The **IPSEC_DOSP_STATISTICS0** structure is used to store statistics for IPsec DoS Protection.

## Members

### `totalStateEntriesCreated`

The total number of state entries that have been created since the computer was last started.

### `currentStateEntries`

The current number of state entries in the table.

### `totalInboundAllowedIPv6IPsecUnauthPkts`

The total number of inbound IPv6 IPsec unauthenticated packets that have been allowed since the computer was last started.

### `totalInboundRatelimitDiscardedIPv6IPsecUnauthPkts`

The total number of inbound IPv6 IPsec unauthenticated packets that have been discarded due to rate limiting since the computer was last started.

### `totalInboundPerIPRatelimitDiscardedIPv6IPsecUnauthPkts`

The total number of inbound IPv6 IPsec unauthenticated packets that have been discarded due to per internal IP address rate limiting since the computer was last started.

### `totalInboundOtherDiscardedIPv6IPsecUnauthPkts`

The total number of inbound IPV6 IPsec unauthenticated packets that have been discarded due to all other reasons since the computer was last started.

### `totalInboundAllowedIPv6IPsecAuthPkts`

The total number of inbound IPv6 IPsec authenticated packets that have been allowed since the computer was last started.

### `totalInboundRatelimitDiscardedIPv6IPsecAuthPkts`

The total number of inbound IPv6 IPsec authenticated packets that have been discarded due to rate limiting since the computer was last started.

### `totalInboundOtherDiscardedIPv6IPsecAuthPkts`

The total number of inbound IPV6 IPsec authenticated packets that have been discarded due to all other reasons since the computer was last started.

### `totalInboundAllowedICMPv6Pkts`

The total number of inbound ICMPv6 packets that have been allowed since the computer was last started.

### `totalInboundRatelimitDiscardedICMPv6Pkts`

The total number of inbound ICMPv6 packets that have been discarded due to rate limiting since the computer was last started.

### `totalInboundAllowedIPv6FilterExemptPkts`

The total number of inbound IPv6 filter exempted packets that have been allowed since the computer was last started.

### `totalInboundRatelimitDiscardedIPv6FilterExemptPkts`

The total number of inbound IPv6 filter exempted packets that have been discarded due to rate limiting since the computer was last started.

### `totalInboundDiscardedIPv6FilterBlockPkts`

The total number of inbound IPv6 filter blocked packets that have been discarded since the computer was last started.

### `totalInboundAllowedDefBlockExemptPkts`

The total number of inbound default-block exempted packets that have been allowed since the computer was last started.

### `totalInboundRatelimitDiscardedDefBlockExemptPkts`

The total number of inbound default-block exempted packets that have been discarded due to rate limiting since the computer was last started.

### `totalInboundDiscardedDefBlockPkts`

The total number of inbound default-block packets that have been discarded since the computer was last started.

### `currentInboundIPv6IPsecUnauthPerIPRateLimitQueues`

The current number of per internal IP address rate limit queues for inbound IPv6 unauthenticated IPsec traffic.

## Remarks

**IPSEC_DOSP_STATISTICS0** is a specific implementation of IPSEC_DOSP_STATISTICS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)