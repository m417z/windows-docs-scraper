# QOS_TRAFFIC_CLASS structure

## Description

The traffic control object
**QOS_TRAFFIC_CLASS** is used to override the default UserPriority value ascribed to packets that classify the traffic of a given flow.

By default, the UserPriority value of a flow is derived from the ServiceType (see: [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)). Therefore, it is often necessary to override the default UserPriority because packets can be tagged in their Layer 2 headers (such as an 802.1p header) to specify their priority to Layer-2 devices. Using
**QOS_TRAFFIC_CLASS** enables application developers to override the default UserPriority setting.

## Members

### `ObjectHdr`

The QOS object
[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr). The object type for this traffic control object should be
**QOS_OBJECT_TRAFFIC_CLASS**.

### `TrafficClass`

User priority value of the flow. The valid range is zero through seven. The following settings are chosen (by default) when the
**QOS_TRAFFIC_CLASS** traffic control object is not used.

**Note** This parameter specifies an 802.1 TrafficClass parameter which has been provided to the host by a layer 2 network
in an 802.1 extended RSVP RESV message. If this object is obtained
from the network, hosts will stamp the MAC headers of corresponding
transmitted packets, with the value in the object. Otherwise, hosts
can select a value based on the standard Intserv mapping of
ServiceType to 802.1 TrafficClass.

#### SERVICETYPE_BESTEFFORT (0x00000001)

#### SERVICETYPE_CONTROLLEDLOAD (0x00000002)

#### SERVICETYPE_GUARANTEED (0x00000003)

#### SERVICETYPE_NONCONFORMING (0x00000009)

#### SERVICETYPE_NETWORK_CONTROL (0x0000000A)

#### SERVICETYPE_QUALITATIVE (0x0000000D)

## Remarks

**Traffic Control:** The following **ServiceType** enumeration values are invalid when specifically working with Traffic Control.

SERVICE_NO_TRAFFIC_CONTROL

SERVICE_NO_QOS_SIGNALING

SERVICETYPE_GENERAL_INFORMATION

SERVICETYPE_NETWORK_UNAVAILABLE

SERVICETYPE_NOCHANGE

SERVICETYPE_NOTRAFFIC

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv)

[QOS_DIFFSERV_RULE](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv_rule)

[QOS_DS_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_ds_class)

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)