# IF_OPER_STATUS enumeration

## Description

The **IF_OPER_STATUS** enumeration specifies the operational status of an interface.

## Constants

### `IfOperStatusUp:1`

The interface is up and operational. The interface is able to pass packets.

### `IfOperStatusDown`

The interface is not down and not operational. The interface is unable to pass packets.

### `IfOperStatusTesting`

The interface is being tested.

### `IfOperStatusUnknown`

The interface status is unknown.

### `IfOperStatusDormant`

The interface is not
in a condition to pass packets. The interface is not up, but is
in a pending state, waiting for some external event. This state identifies the situation where the
interface is waiting for events to place it in the up state.

### `IfOperStatusNotPresent`

This state is a refinement on the down state which
indicates that the interface is down specifically because
some component (for example, a hardware component) is not present in
the system.

### `IfOperStatusLowerLayerDown`

This state is a refinement on the down state.
The interface is operational, but a networking layer below the interface is not operational.

## Remarks

The **IF_OPER_STATUS** enumeration is used in the **OperStatus** member of the [IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh) structure.

## See also

[IP_ADAPTER_ADDRESSES](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_addresses_lh)