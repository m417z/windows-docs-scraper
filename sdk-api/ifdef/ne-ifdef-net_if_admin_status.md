# NET_IF_ADMIN_STATUS enumeration

## Description

The NET_IF_ADMIN_STATUS enumeration type specifies the
[NDIS network interface](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-network-interfaces2) administrative
status, as described in RFC 2863.

## Constants

### `NET_IF_ADMIN_STATUS_UP:1`

Specifies that the interface is initialized and enabled, but the interface is not necessarily
ready to transmit and receive network data because that depends on the operational status of the
interface. For more information about the operational status of an interface, see
[OID_GEN_OPERATIONAL_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-operational-status).

### `NET_IF_ADMIN_STATUS_DOWN:2`

Specifies that the interface is down, and this interface cannot be used to transmit or receive
network data.

### `NET_IF_ADMIN_STATUS_TESTING:3`

Specifies that the interface is in a test mode, and no network data can be transmitted or
received.

## Remarks

For more information on RFC 2863, see
["The Interfaces Group MIB"](https://www.ietf.org/rfc/rfc2863.txt).

## See also

[OID_GEN_ADMIN_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-admin-status)