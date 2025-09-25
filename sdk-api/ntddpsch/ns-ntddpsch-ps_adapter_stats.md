# PS_ADAPTER_STATS structure

## Description

The
**PS_ADAPTER_STATS** structure provides statistical packet shaper information about a specified adapter. Note that the
**PS_ADAPTER_STATS** structure is used in conjunction with the
[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats) structure.

## Members

### `OutOfPackets`

Number of instances in which the adapter had no packets to transmit on the specified adapter.

### `FlowsOpened`

Number of flows opened on the adapter.

### `FlowsClosed`

Number of flows closed on the adapter.

### `FlowsRejected`

Number of flows that were rejected due to packet shaper constraints on the adapter.

### `FlowsModified`

Number of flows that were modified on the adapter.

### `FlowModsRejected`

Number of flow modifications that were rejected on the adapter due to packet shaper constraints.

### `MaxSimultaneousFlows`

Maximum number of simultaneous flows.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats)