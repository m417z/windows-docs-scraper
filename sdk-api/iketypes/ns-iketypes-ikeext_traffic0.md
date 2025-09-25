# IKEEXT_TRAFFIC0 structure

## Description

The **IKEEXT_TRAFFIC0** structure specifies the IKE/Authip traffic.

## Members

### `ipVersion`

IP version specified by [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version).

### `localV4Address`

The local address of the traffic.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `localV6Address`

The local address of the traffic.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `remoteV4Address`

The remote address of the traffic.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `remoteV6Address`

The remote address of the traffic.

Available when **ipVersion** is **FWP_IP_VERSION_V6**.

### `authIpFilterId`

 Filter ID from quick mode (QM) policy of matching extended mode (EM) filter.

## Remarks

**IKEEXT_TRAFFIC0** is a specific implementation of IKEEXT_TRAFFIC. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)