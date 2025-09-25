# RtmGetRegisteredEntities function

## Description

The
**RtmGetRegisteredEntities** function returns information about all clients that have registered with the specified instance of the routing table manager and specified address family.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NumEntities` [in, out]

On input, *NumEntities* is a pointer to a **UINT** value, which specifies the maximum number of clients that can be received by *EntityInfos*. On output, *NumEntities* receives the actual number of clients received by *EntityInfos*.

### `EntityHandles` [out]

If handles must be returned: On input, *EntityHandles* is a pointer to **NULL**. On output, *EntityHandles* receives a pointer to an array of entity handle; otherwise, *EntityHandles* remains unchanged.

If handles do not need to be returned: On input, *EntityHandles* is **NULL**.

### `EntityInfos` [out]

If a pointer must be returned: On input, *EntityInfos* is a pointer to **NULL**. On output, *EntityInfos* receives a pointer to an array of
[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info) structures; otherwise, *EntityInfos* remains unchanged.

If a pointer does not need to be returned: On input, *EntityInfos* is **NULL**.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer supplied is not large enough to hold all the requested information. |

## Remarks

If **ERROR_INSUFFICIENT_BUFFER** is returned, there may be some data in *EntityHandles*. The *NumEntities* parameter specifies how many entities were actually returned.

The
**RtmGetRegisteredEntities** function can be used by routing protocols to verify which other protocols are running for that address family and routing table manager instance. Based on the information returned, a client can then perform protocol-specific processing.

The RTMv2 API supports only one instance of the routing table manager.

When the entities are no longer required, release them by calling
[RtmReleaseEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseentities).

For sample code using this function, see
[Enumerate the Registered Entities](https://learn.microsoft.com/windows/desktop/RRAS/enumerate-the-registered-entities).

## See also

[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info)

[RtmReleaseEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseentities)