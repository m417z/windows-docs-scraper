# RtmRegisterEntity function

## Description

The
**RtmRegisterEntity** function registers a client with an instance of the routing table manager for a specific address family. The routing table manager returns a registration handle and a profile of the instance. The profile contains a list of values that are used when calling other functions. Values include the maximum number of destinations returned in a buffer by a single call.

Registration is the first action a client should take.

## Parameters

### `RtmEntityInfo` [in]

Pointer to an
[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info) structure. This structure contains information that identifies the client to the routing table manager, such as the routing table manager instance and address family with which to register.

### `ExportMethods` [in]

Pointer to a [RTM_ENTITY_EXPORT_METHODS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_export_methods) structure that contains a list of methods exported by the client. This parameter is optional and can be set to **NULL** if the calling client has no methods to export.

### `EventCallback` [in]

A **RTM_EVENT_CALLBACK** structure that specifies the callback the routing table manager uses to notify the client of events. The events are when a client registers and unregisters, when routes expire, and when changes to the best route to a destination have occurred. Only those changes specified when the client called
[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification).

### `ReserveOpaquePointer` [in]

Specifies whether to reserve an opaque pointer in each destination for this instance of the protocol. Specify **TRUE** to reserve an opaque pointer in each destination. Specify **FALSE** to skip this action. These opaque pointers can be used to point to a private, protocol-specific context for each destination.

### `RtmRegProfile` [out]

On input, *RtmRegProfile* is a pointer to an
[RTM_REGN_PROFILE](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_regn_profile) structure.

On output, *RtmRegProfile* is filled with the requested registration profile structure. The client must use the information returned in other function calls (information returned includes the number of equal-cost next hops and the maximum number of items returned by an enumeration function call).

### `RtmRegHandle` [out]

Receives a registration handle for the client. This handle must be used in all subsequent calls to the routing table manager.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ALREADY_EXISTS** | The specified client has already registered with the routing table manager. |
| **ERROR_BAD_CONFIGURATION** | Registry information for the routing table manager is corrupt. |
| **ERROR_FILE_NOT_FOUND** | Registry information for the routing table manager was not found. |
| **ERROR_INVALID_DATA** | A parameter contains incorrect information. |
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are not enough available system resources to complete this operation. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory to complete this operation. |

## Remarks

For sample code using this function, see
[Register With the Routing Table Manager](https://learn.microsoft.com/windows/desktop/RRAS/register-with-the-routing-table-manager).

## See also

[RTM_ENTITY_EXPORT_METHODS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_export_methods)

[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info)

[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback)

[RTM_REGN_PROFILE](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_regn_profile)

[RtmDeregisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmderegisterentity)

[RtmGetRegisteredEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetregisteredentities)

[RtmReleaseEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseentities)