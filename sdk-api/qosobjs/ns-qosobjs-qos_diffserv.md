# QOS_DIFFSERV structure

## Description

The
**QOS_DIFFSERV** traffic control object is used to specify filters for the packet scheduler when it operates in Differentiated Services Mode.

## Members

### `ObjectHdr`

The QOS object
**QOS_OBJECT_HDR**. The object type for this traffic control object should be
QOS_OBJECT_DIFFSERV.

### `DSFieldCount`

Number of Diffserv Rules in this object.

### `DiffservRule`

Array of
[QOS_DIFFSERV_RULE](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv_rule) structures.

## Remarks

The
**QOS_DIFFSERV** object is used to specify the set of Diffserv rules that apply to the specified flow, all of which are specified in the **DiffservRule** member. Each Diffserv rule has an InboundDSField value, which signifies the DSCP on the Inbound packet. The Diffserv Rules also have OutboundDSCP and UserPriority values for conforming and nonconforming packets. These indicate the DSCP and 802.1p values that go out on the forwarded packet. Note that the DSCP or UserPriority mapping based on ServiceType or
**QOS_DS_CLASS** or
**QOS_TRAFFIC_CLASS** is not used in this mode.

## See also

[QOS_DIFFSERV_RULE](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv_rule)

[QOS_DS_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_ds_class)

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)

[QOS_TRAFFIC_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_traffic_class)