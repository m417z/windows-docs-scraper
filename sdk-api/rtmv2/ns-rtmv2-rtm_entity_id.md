# RTM_ENTITY_ID structure

## Description

The
**RTM_ENTITY_ID** structure is used to uniquely identify a client to the routing table manager. The protocol identifier and the instance identifier are the values that are used to uniquely identify a client.

## Members

### `EntityProtocolId`

Specifies a client's protocol identifier (such as RIP or OSPF).

### `EntityInstanceId`

Specifies a client's protocol instance (such as RIPv1 or RIPv2).

### `EntityId`

Specifies a client's identifier, which is a combination of the **EntityProtocolId** and the **EntityInstanceId**.

## See also

[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info)