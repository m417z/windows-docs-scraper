# QOS_SD_MODE structure

## Description

The QOS object
**QOS_SD_MODE** defines the behavior of the traffic control-packet shaper component.

## Members

### `ObjectHdr`

The QOS object
[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr). The object type for this QOS object should be
**QOS_SD_MODE**.

### `ShapeDiscardMode`

Specifies the requested behavior of the packet shaper. Note that there are elements of packet handling within these predefined behaviors that depend on the flow settings specified within
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec).

| Value | Meaning |
| --- | --- |
| **TC_NONCONF_BORROW** | This mode is currently only available to the TC API. It is not available to users of the QOS API. <br><br>Instructs the packet shaper to borrow remaining available resources after all higher priority flows have been serviced. If the **TokenRate** member of [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) is specified for this flow, packets that exceed the value of **TokenRate** will have their priority demoted to less than SERVICETYPE_BESTEFFORT, as defined in the **ServiceType** member of the **FLOWSPEC** structure. |
| **TC_NONCONF_SHAPE** | Instructs the packet shaper to retain packets until network resources are available to the flow in sufficient quantity to make such packets conforming. (For example, a 100K packet will be retained in the packet shaper until 100K worth of credit is accrued for the flow, allowing the packet to be transmitted as conforming). Note that TokenRate must be specified if using TC_NONCONF_SHAPE. |
| **TC_NONCONF_DISCARD** | Instructs the packet shaper to discard all nonconforming packets. TC_NONCONF_DISCARD should be used with care. |

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)