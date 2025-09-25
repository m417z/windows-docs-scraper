# PGET_MFE_STATUS callback function

## Description

The router manager calls the
**GetMfeStatus** function to obtain the status of the multicast forwarding entry (MFE) for the specified interface, group address, and source address.

The [PGET_MFE_STATUS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *GetMfeStatus* is a placeholder for the application-defined function name.

## Parameters

### `InterfaceIndex` [in]

Specifies the index of the interface for this MFE.

### `GroupAddress` [in]

Specifies the multicast group address for this MFE.

### `SourceAddress` [in]

Specifies the multicast source address for this MFE.

### `StatusCode` [out]

Pointer to a **BYTE** variable. The routing protocol should fill in this variable with one of the following values. The routing protocol should select the highest-valued code that applies.

| Value | Meaning |
| --- | --- |
| **MFE_NO_ERROR** | None of the following values apply. |
| **MFE_REACHED_CORE** | The local computer on this router is a rendezvous point (RP)/core router for the multicast group. |
| **MFE_OIF_PRUNED** | This value should be set only by the owner of the outgoing interface. The value indicates that no downstream receivers exist on the outgoing interface. |
| **MFE_PRUNED_UPSTREAM** | This value should be set only by the owner of the incoming interface. The value indicates that a prune message was sent upstream. |
| **MFE_OLD_ROUTER** | This value should be set only by the owner of the incoming interface. The value indicates that the upstream neighbor doesn't support mtrace. |

## Return value

If the function succeeds, the return value should be NO_ERROR.

If the function fails, the return value should be one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The routing protocol could not complete the request. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, no interface exists with that index), or the group or source address is invalid. |

## Remarks

Only multicast routing protocols need implement this function. Non-multicast routing protocols should pass **NULL** as the pointer value for this function in
[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics)

## See also

[GetNeighbors](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_neighbors)