# RtmGetExactMatchDestination function

## Description

The
**RtmGetExactMatchDestination** function searches the routing table for a destination that exactly matches the specified network address and subnet mask. If an exact match is found, the information for that destination is returned.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestAddress` [in]

Pointer to the destination network address.

### `ProtocolId` [in]

Specifies the protocol identifier. The *ProtocolID* is not part of the search criteria. The routing table manager uses this identifier to determine which destination and route information to return. For example, if a client specifies the RIP protocol identifier, the best RIP route is returned, even if a non-RIP route is the best route to the destination.

Specify RTM_BEST_PROTOCOL to return a route regardless of which protocol owns it. Specify RTM_THIS_PROTOCOL to return the best route for the calling protocol.

### `TargetViews` [in]

Specifies the views from which to return information. If the client specifies RTM_VIEW_MASK_ANY, destination information is returned from all views; however, no view-specific information is returned.

### `DestInfo` [out]

On input, *DestInfo* is a pointer to an
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure.

On output, *DestInfo* is filled with the requested destination information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_FOUND** | The specified destination was not found. |

## Remarks

The *DestInfo* structure is a variable-sized structure. If the client specifies more than one view with *TargetViews*, the size of *DestInfo* increases for each view. Use the
[RTM_SIZE_OF_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_size_of_dest_info) macro to determine how large a *DestInfo* structure to allocate before calling this function. Use the value specified for *TargetViews* as a parameter to
**RTM_SIZE_OF_DEST_INFO**.

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RTM_NET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_net_address)

[RtmGetExactMatchRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchroute)

[RtmGetLessSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetlessspecificdestination)

[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination)

[RtmIsBestRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmisbestroute)