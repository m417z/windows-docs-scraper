# PS_DRRSEQ_STATS structure

## Description

The
**PS_DRRSEQ_STATS** structure provides network interface card (NIC) and packet sequencer–packet shaper statistics. Note that the
**PS_DRRSEQ_STATS** structure is used in conjunction with the
[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats) structure.

## Members

### `MaxPacketsInNetcard`

Maximum number of packets that have been queued in the network interface card for the flow or interface.

### `AveragePacketsInNetcard`

Average number of packets queued in the network interface card for the flow or interface.

### `MaxPacketsInSequencer`

Maximum number of packets that have been queued in the packet sequencer for the flow or interface.

### `AveragePacketsInSequencer`

Average number of packets that have been queued in the packet sequencer for the flow or interface.

### `NonconformingPacketsTransmitted`

Number of nonconforming packets that have been transmitted for the flow or interface.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[PS_COMPONENT_STATS](https://learn.microsoft.com/windows/desktop/api/ntddpsch/ns-ntddpsch-ps_component_stats)