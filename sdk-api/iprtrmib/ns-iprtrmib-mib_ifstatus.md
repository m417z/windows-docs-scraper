# MIB_IFSTATUS structure

## Description

The
**MIB_IFSTATUS** structure stores status information for a particular interface.

## Members

### `dwIfIndex`

The index that identifies the interface.

### `dwAdminStatus`

The administrative status of the interface, that is, whether the interface is administratively enabled or disabled.

### `dwOperationalStatus`

The operational status of the interface. This member can be one of the values defined in the [ROUTER_CONNECTION_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_connection_state) enumeration defined in the *Mprapip.h* header file. See
the **ROUTER_CONNECTION_STATE** enumeration for a list amd description of the possible operational states.

### `bMHbeatActive`

Specifies whether multicast heartbeat detection is enabled. A value of **TRUE** indicates that heartbeat detection is enabled. A value of **FALSE** indicates that heartbeat detection is disabled.

### `bMHbeatAlive`

Specifies whether the multicast heartbeat dead interval has been exceeded. A value of **FALSE** indicates that the interval has been exceeded. A value of **TRUE** indicates that the interval has not been exceeded.

## Remarks

Note that the *Iprtrmib.h* header file is automatically included in the *Iphlpapi.h* header file. The *Iprtrmib.h* header file should never be used directly.

## See also

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)

[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1)