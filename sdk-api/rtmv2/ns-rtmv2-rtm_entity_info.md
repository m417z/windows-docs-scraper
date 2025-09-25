# RTM_ENTITY_INFO structure

## Description

The
**RTM_ENTITY_INFO** structure is used to exchange client information with the routing table manager.

## Members

### `RtmInstanceId`

Specifies the instance of the routing table manager with which the client registered.

### `AddressFamily`

Specifies the address family to which the client belongs.

### `EntityId`

Specifies the identifier that uniquely identifies a client.

## See also

[RTM_ENTITY_ID](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_id)

[RtmGetEntityInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetentityinfo)

[RtmGetRegisteredEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetregisteredentities)

[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity)

[RtmReleaseEntityInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseentityinfo)