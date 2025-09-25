# NL_LINK_LOCAL_ADDRESS_BEHAVIOR enumeration

## Description

The NL_LINK_LOCAL_ADDRESS_BEHAVIOR enumeration type defines the link local address behavior.

## Constants

### `LinkLocalAlwaysOff:0`

A link local IP address should never be used.

### `LinkLocalDelayed`

A link local IP address should be used only if no other address is available. This setting is the
default setting for an IPv4 interface.

### `LinkLocalAlwaysOn`

A link local IP address should always be used. This setting is the default setting for an IPv6
interface.

### `LinkLocalUnchanged:-1`

When the properties of an IP interface are being set, the value for link local address behavior
should be unchanged.