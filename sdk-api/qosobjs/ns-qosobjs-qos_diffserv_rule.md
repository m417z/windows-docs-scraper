# QOS_DIFFSERV_RULE structure

## Description

The
**QOS_DIFFSERV_RULE** structure is used in conjunction with the traffic control object
[QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv) to provide Diffserv rules for a given flow.

## Members

### `InboundDSField`

Diffserv code point (DSCP) on the inbound packet. **InboundDSField** must be unique for the interface, otherwise the flow addition will fail.

Valid range is 0x00 - 0x3F.

### `ConformingOutboundDSField`

Diffserv code point (DSCP) marked on all conforming packets on the flow. This member can be used to remark the packet before it is forwarded.

Valid range is 0x00 - 0x3F.

### `NonConformingOutboundDSField`

Diffserv code point (DSCP) marked on all nonconforming packets on the flow. This member can be used to remark the packet before it is forwarded.

Valid range is 0x00 - 0x3F.

### `ConformingUserPriority`

UserPriority value marked on all conforming packets on the flow. This member can be used to remark the packet before it is forwarded.

Valid range is 0-7

### `NonConformingUserPriority`

UserPriority value marked on all nonconforming packets on the flow. This member can be used to remark the packet before it is forwarded.

Valid range is 0-7

## See also

[QOS_DIFFSERV](https://learn.microsoft.com/windows/desktop/api/qosobjs/ns-qosobjs-qos_diffserv)