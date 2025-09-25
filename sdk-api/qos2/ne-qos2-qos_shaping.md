# QOS_SHAPING enumeration

## Description

The **QOS_SHAPING** enumeration defines the shaping behavior of a flow.

## Constants

### `QOSShapeOnly:0`

Indicates that the Windows packet scheduler (Pacer) will be used to enforce the requested flow rate. Data packets that exceed the rate are delayed until appropriate in order to maintain the specified flow rate. If the network supports prioritization, packets will always receive conformant priority values when QOSShapeFlow is specified.

### `QOSShapeAndMark:1`

Indicates that the Windows Scheduler will be used to enforce the requested flow rate. Data packets exceeding the rate are delayed accordingly. Packets receive conformant priority values.

### `QOSUseNonConformantMarkings:2`

Indicates that the flow rate requested will not be enforced. Data packets that would exceed the flow rate will receive a priority that indicates they are non-conformant. This may lead to lost and reordered packets.

## See also

[QOS_FLOWRATE_OUTGOING](https://learn.microsoft.com/windows/desktop/api/qos2/ns-qos2-qos_flowrate_outgoing)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)