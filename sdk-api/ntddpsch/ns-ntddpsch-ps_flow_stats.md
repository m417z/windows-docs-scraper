# PS_FLOW_STATS structure

## Description

The
**PS_FLOW_STATS** structure provides statistical packet shaper information about a particular flow. Note that the
**PS_FLOW_STATS** structure is used in conjunction with the
[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats) structure.

## Members

### `DroppedPackets`

Number of packets that have been dropped from the flow.

### `PacketsScheduled`

Number of packets that have been scheduled for transmission on the flow.

### `PacketsTransmitted`

Number of packets that have been transmitted on the flow.

### `BytesScheduled`

Number of bytes that have been scheduled for transmission on the flow.

### `BytesTransmitted`

Number of bytes that have been transmitted on the flow.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats)