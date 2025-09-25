# QOS_FLOW_FUNDAMENTALS structure

## Description

The **QOS_FLOW_FUNDAMENTALS** structure contains basic information about a flow.

## Members

### `BottleneckBandwidthSet`

This Boolean value is set to **TRUE** if the **BottleneckBandwidth** field contains a value.

### `BottleneckBandwidth`

Indicates the maximum end-to-end link capacity between the source and sink device, in bits.

### `AvailableBandwidthSet`

Set to **TRUE** if the **AvailableBandwidth** field contains a value.

### `AvailableBandwidth`

Indicates how much bandwidth is available for submitting traffic on the end-to-end network path between the source and sink device, in bits.

### `RTTSet`

Set to **TRUE** if the **RTT** field contains a value.

### `RTT`

Measures the round-trip time between the source and sink device, in microseconds.

## See also

[QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)