# QOS_TCP_TRAFFIC structure

## Description

The **QOS_TCP_TRAFFIC** structure is used to indicate that IP Precedence and UserPriority mappings for a given flow must be set to system defaults for TCP traffic.

## Members

### `ObjectHdr`

A QOS object header.

## Remarks

When the **QOS_TCP_TRAFFIC** object is passed, the **DSField** mapping and **UserPriorityMapping** of **ServiceType** are ignored, as are QOS_OBJECT_DS_CLASS and QOS_OBJECT_TRAFFIC_CLASS.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)