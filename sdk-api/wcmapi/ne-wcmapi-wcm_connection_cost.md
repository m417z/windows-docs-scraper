# WCM_CONNECTION_COST enumeration

## Description

The **WCM_CONNECTION_COST** enumerated type determines the connection cost type and flags.

## Constants

### `WCM_CONNECTION_COST_UNKNOWN:0x0`

Connection cost information is not available.

### `WCM_CONNECTION_COST_UNRESTRICTED:0x1`

The connection is unlimited and has unrestricted usage constraints.

### `WCM_CONNECTION_COST_FIXED:0x2`

Usage counts toward a fixed allotment of data which the user has already paid for (or agreed to pay for).

### `WCM_CONNECTION_COST_VARIABLE:0x4`

The connection cost is on a per-byte basis.

### `WCM_CONNECTION_COST_OVERDATALIMIT:0x10000`

The connection has exceeded its data limit.

### `WCM_CONNECTION_COST_CONGESTED:0x20000`

The connection is throttled due to high traffic.

### `WCM_CONNECTION_COST_ROAMING:0x40000`

The connection is outside of the home network.

**Note** The **WCM_CONNECTION_COST_ROAMING** value comes directly from the connection source. Attempts to set it directly will fail.

### `WCM_CONNECTION_COST_APPROACHINGDATALIMIT:0x80000`

The connection is approaching its data limit.