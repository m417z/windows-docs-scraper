# QOS_FRIENDLY_NAME structure

## Description

The
**QOS_FRIENDLY_NAME** traffic control object associates a friendly name with flow.

## Members

### `ObjectHdr`

The QOS object
[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr). The object type for this traffic control object should be
**QOS_OBJECT_FRIENDLY_NAME**.

### `FriendlyName`

Name to be associated with the flow.

## Remarks

Programmers are encouraged to use the
**QOS_FRIENDLY_NAME** traffic control object to associate flows with their applications. This approach enables management applications to identify and associate enumerated flows with corresponding applications.

## See also

[QOS_DIFFSERV_RULE](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv_rule)

[QOS_DS_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_ds_class)

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)

[QOS_TRAFFIC_CLASS](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_traffic_class)