# QOS_QUERY_FLOW enumeration

## Description

The **QOS_QUERY_FLOW** enumeration indicates the type of information a [QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow) function will request.

## Constants

### `QOSQueryFlowFundamentals:0`

Indicates an information request for the flow fundamentals. This information includes bottleneck bandwidth, available bandwidth, and the average Round Trip Time (RTT)

### `QOSQueryPacketPriority:1`

Indicates a request for information detailing the QoS priority being added to flow packets.

### `QOSQueryOutgoingRate:2`

Indicates a request for the flow rate specified during the creation of an agreement with the QoS subsystem via the [QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow) function.

## See also

[QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)