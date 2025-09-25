# NL_ROUTER_DISCOVERY_BEHAVIOR enumeration

## Description

The NL_ROUTER_DISCOVERY_BEHAVIOR enumeration type defines the router discovery behavior, as described
in RFC 2461.

## Constants

### `RouterDiscoveryDisabled:0`

Router discovery is disabled.

### `RouterDiscoveryEnabled`

Router discovery is enabled. This setting is the default value for IPv6.

### `RouterDiscoveryDhcp`

Router discovery is configured based on DHCP. This setting is the default value for IPv4.

### `RouterDiscoveryUnchanged:-1`

When the properties of an IP interface are being set, the value for router discovery should be
unchanged.

## Remarks

For more information about RFC 2461, see the
[Neighbor Discovery for IP Version 6
(IPv6)](https://www.ietf.org/rfc/rfc2461.txt) memo by the Network Working Group.