# WDSTRANSPORT_NETWORK_PROFILE_TYPE enumeration

## Description

Defines settings that are used by WDS transport protocols to optimize data transfer on the network. The network profile setting values are optimized for different network speeds and in most cases should not be changed. A custom network profile is included to enable administrators to try different values and find what suits their network best.

## Constants

### `WdsTptNetworkProfileUnknown:0`

Default value that indicates that the network profile is not known.

### `WdsTptNetworkProfileCustom:1`

Indicates that the server should use the custom network profile. This is a profile whose settings can be directly modified by administrators if they need to further customize their settings rather than use one of the fixed, inbox profiles. Note that settings for this profile start with values identical to those of the 100-Mbps profile.

### `WdsTptNetworkProfile10Mbps:2`

Indicates that the server should use the 10-Mbps network profile, which is optimized for slow 10-Mbps networks.

### `WdsTptNetworkProfile100Mbps:3`

Indicates that the server should use the 100-Mbps network profile, which is optimized for mainstream 100-Mbps networks. This is the default profile selected for use on a freshly installed WDS server.

### `WdsTptNetworkProfile1Gbps:4`

Indicates that the server should use the 1-Gbps network profile, which is optimized for fast 1-Gbps or higher networks, such as those used in high-end data centers.