# QOS_SHAPING_RATE structure

## Description

The QOS object
**QOS_SHAPING_RATE** specifies the uniform traffic shaping rate be applied to a given flow.

## Members

### `ObjectHdr`

The QOS object
[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr). The object type for this QOS object should be
**QOS_SHAPING_RATE**.

### `ShapingRate`

Unsigned 32-bit integer that specifies the uniform traffic shaping rate in bytes per second.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[QOS_OBJECT_HDR](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos/ns-qos-qos_object_hdr)