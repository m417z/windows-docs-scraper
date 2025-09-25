## Description

Stores a type and value pair for a connection policy setting. You use this structure with [FwpmConnectionPolicyAdd0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmconnectionpolicyadd0).

## Members

### `type`

A type of connection policy setting. See [FWP_NETWORK_CONNECTION_POLICY_SETTING_TYPE](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_network_connection_policy_setting_type).

### `value`

The value of a connection policy setting.

**FWP_NETWORK_CONNECTION_POLICY_SOURCE_ADDRESS**. The source address to use for the connection. The value should be a **FWP_UINT32** for an IPv4 address, and a **FWP_BYTE_ARRAY16_TYPE** for an IPv6 address.
**FWP_NETWORK_CONNECTION_POLICY_NEXT_HOP_INTERFACE**. The LUID of the outgoing interface to use for the connection. The value should be a **FWP_UINT64**.
**FWP_NETWORK_CONNECTION_POLICY_NEXT_HOP**. The nexthop address (or gateway) to use for the connection. The value should be a **FWP_UINT32** for an IPv4 address, and a **FWP_BYTE_ARRAY16_TYPE** for an IPv6 address.

## Remarks

## See also