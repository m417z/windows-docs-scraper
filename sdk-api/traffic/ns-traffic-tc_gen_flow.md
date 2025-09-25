# TC_GEN_FLOW structure

## Description

The
**TC_GEN_FLOW** structure creates a generic flow for use with the traffic control interface. The flow is customized through the members of this structure.

## Members

### `SendingFlowspec`

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure for the sending direction of the flow.

### `ReceivingFlowspec`

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure for the receiving direction of the flow.

### `TcObjectsLength`

Length of **TcObjects**, in bytes.

### `TcObjects`

Buffer that contains an array of traffic control objects specific to the given flow. The **TcObjects** member can contain objects from the list of currently supported objects. Definitions of these objects can be found in Qos.h and Traffic.h:

[QOS_DS_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_ds_class)

[QOS_TRAFFIC_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_traffic_class)

[QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv)

[QOS_SD_MODE](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-qos_sd_mode)

[QOS_SHAPING_RATE](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-qos_shaping_rate)

QOS_OBJECT_END_OF_LIST

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv)

[QOS_DS_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_ds_class)

[QOS_SD_MODE](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-qos_sd_mode)

[QOS_SHAPING_RATE](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-qos_shaping_rate)

[QOS_TRAFFIC_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_traffic_class)