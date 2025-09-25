# QOS_PACKET_PRIORITY structure

## Description

The **QOS_PACKET_PRIORITY** structure that indicates the priority of the flow traffic.

## Members

### `ConformantDSCPValue`

Differential Services Code Point (DSCP) mark used for flow traffic that conforms to the specified flow rate.

### `NonConformantDSCPValue`

DSCP marking used for flow traffic that exceeds the specified flow rate. Non-conformant DSCP values are only applicable only if [QOS_SHAPING](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_shaping) has a value of **QOSUseNonConformantMarkings**.

### `ConformantL2Value`

Layer-2 (L2) tag used for flow traffic that conforms to the specified flow rate. L2 tags will not be added to packets if the end-to-end path between source and sink does not support them.

### `NonConformantL2Value`

L2 tag used for flow traffic that exceeds the specified flow rate. Non-conformant L2 values are only applicable if [QOS_SHAPING](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_shaping) has a value of **QOSUseNonConformantMarkings**.

## See also

[QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)