# IPSEC_DOSP_OPTIONS0 structure

## Description

The **IPSEC_DOSP_OPTIONS0** structure is used to store configuration parameters for IPsec DoS Protection.

## Members

### `stateIdleTimeoutSeconds`

The number of seconds before idle timeout. This value must be greater than 0.

### `perIPRateLimitQueueIdleTimeoutSeconds`

The idle timeout for the per IP rate limit queue object. This value must be greater than 0.

### `ipV6IPsecUnauthDscp`

The DSCP marking for unauthenticated inbound IPv6 IPsec traffic. This value must be less than or equal to 63. Specify IPSEC_DOSP_DSCP_DISABLE_VALUE to disable DSCP marking for this category.

### `ipV6IPsecUnauthRateLimitBytesPerSec`

The rate limit for unauthenticated inbound IPv6 IPsec traffic. Specify IPSEC_DOSP_RATE_LIMIT_DISABLE_VALUE to disable rate limiting for this category.

### `ipV6IPsecUnauthPerIPRateLimitBytesPerSec`

The rate limit for unauthenticated inbound IPv6 IPsec traffic per internal IP address. Specify IPSEC_DOSP_RATE_LIMIT_DISABLE_VALUE to disable rate limiting for this category.

### `ipV6IPsecAuthDscp`

The DSCP marking for authenticated inbound IPv6 IPsec traffic. The value must be less than or equal to 63. Specify IPSEC_DOSP_DSCP_DISABLE_VALUE to disable DSCP marking for this category.

### `ipV6IPsecAuthRateLimitBytesPerSec`

The rate limit for authenticated inbound IPv6 IPsec traffic. Specify IPSEC_DOSP_RATE_LIMIT_DISABLE_VALUE to disable rate limiting for this category..

### `icmpV6Dscp`

The DSCP marking for inbound ICMPv6 traffic. The value must be less than or equal to 63. Specify IPSEC_DOSP_DSCP_DISABLE_VALUE to disable DSCP marking for this category.

### `icmpV6RateLimitBytesPerSec`

The rate limit for inbound ICMPv6 traffic. Specify IPSEC_DOSP_RATE_LIMIT_DISABLE_VALUE to disable rate limiting for this category.

### `ipV6FilterExemptDscp`

The DSCP marking for inbound IPv6 filter exempted traffic. The value must be less than or equal to 63. Specify IPSEC_DOSP_DSCP_DISABLE_VALUE to disable DSCP marking for this category.

### `ipV6FilterExemptRateLimitBytesPerSec`

The rate limit for inbound IPV6 filter exempted traffic. Specify IPSEC_DOSP_RATE_LIMIT_DISABLE_VALUE to disable rate limiting for this category.

### `defBlockExemptDscp`

The DSCP marking for inbound default-block exempted traffic. The value must be less than or equal to 63. Specify IPSEC_DOSP_DSCP_DISABLE_VALUE to disable DSCP marking for this category.

### `defBlockExemptRateLimitBytesPerSec`

The rate limit for inbound default-block exempted traffic. Specify IPSEC_DOSP_RATE_LIMIT_DISABLE_VALUE to disable rate limiting for this category.

### `maxStateEntries`

The maximum number of state entries in the table. The value must be greater than 0.

### `maxPerIPRateLimitQueues`

The maximum number of rate limit queues for inbound unauthenticated IPv6 IPsec traffic per internal IP address. The value must be greater than 0.

### `flags`

A combination of the following values.

| IPsec DoS Protection options flag | Meaning |
| --- | --- |
| **IPSEC_DOSP_FLAG_ENABLE_IKEV1** | Allows the IKEv1 keying module. By default, it is blocked. |
| **IPSEC_DOSP_FLAG_ENABLE_IKEV2** | Allows the IKEv2 keying module. By default, it is blocked. |
| **IPSEC_DOSP_FLAG_DISABLE_AUTHIP** | Blocks the AuthIP keying module. By default, it is allowed. |
| **IPSEC_DOSP_FLAG_DISABLE_DEFAULT_BLOCK** | Allows all matching IPv4 traffic and non-IPsec IPv6 traffic. By default, all IPv4 traffic and non-IPsecIPv6 traffic, except IPv6 ICMP, will be blocked. |
| **IPSEC_DOSP_FLAG_FILTER_BLOCK** | Blocks all matching IPv6 traffic. |
| **IPSEC_DOSP_FLAG_FILTER_EXEMPT** | Allows all matching IPv6 traffic. |

### `numPublicIFLuids`

The number of public Internet facing interface identifiers for which DOS protection should be enabled.

### `publicIFLuids`

Pointer to an array of public Internet facing interface identifiers for which DOS protection should be enabled.

### `numInternalIFLuids`

The number of internal network facing interface identifiers for which DOS protection should be enabled.

### `internalIFLuids`

Pointer to an array of internal network facing interface identifiers for which DOS protection should be enabled.

### `publicV6AddrMask`

Optional public IPv6 address or subnet for this policy, as specified in [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask).

### `internalV6AddrMask`

Optional internal IPv6 address or subnet for this policy, as specified in [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask).

## Remarks

**IPSEC_DOSP_OPTIONS0** is a specific implementation of IPSEC_DOSP_OPTIONS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)