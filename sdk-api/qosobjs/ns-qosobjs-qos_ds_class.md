# QOS_DS_CLASS structure

## Description

The traffic control object
**QOS_DS_CLASS** enables application developers to override the default Diffserv code point (DSCP) value for the IP packets associated with a given flow. By default, the DSCP value is derived from the flow's ServiceType.

## Members

### `ObjectHdr`

The QOS object
[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr). The object type for this traffic control object should be
**QOS_OBJECT_DS_CLASS**.

### `DSField`

User priority value for the flow. The valid range is 0x00 through 0x3F. The following settings are chosen (by default) when the
**QOS_DS_CLASS** traffic control object is not used.

| Value | Meaning |
| --- | --- |
| 0 | ServiceTypeBestEffort, ServiceTypeQualitative |
| 0x18 | ServiceTypeControlledLoad |
| 0x28 | ServiceTypeGuaranteed |
| 0x30 | ServiceTypeNetworkControl |
| 0x00 | Non-conformant traffic |

## See also

[QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv)

[QOS_DIFFSERV_RULE](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv_rule)

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)

[QOS_TRAFFIC_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_traffic_class)