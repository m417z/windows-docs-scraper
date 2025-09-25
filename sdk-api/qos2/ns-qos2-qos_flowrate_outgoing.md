# QOS_FLOWRATE_OUTGOING structure

## Description

The **QOS_FLOWRATE_OUTGOING** structure is used to set flow rate information in the [QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow) function.

## Members

### `Bandwidth`

The rate at which data should be sent, in units of bits per second.

**Note** Traffic on the network is measured at the IP level, and not at the application level. The rate that is specified should account for the IP and protocol headers.

### `ShapingBehavior`

A [QOS_SHAPING](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_shaping) constant that defines the shaping behavior of the flow.

### `Reason`

A [QOS_FLOWRATE_REASON](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_flowrate_reason) constant that indicates the reason for a flow rate change.

## See also

[QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)