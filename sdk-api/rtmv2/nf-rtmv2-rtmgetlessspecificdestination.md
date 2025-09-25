# RtmGetLessSpecificDestination function

## Description

The
**RtmGetLessSpecificDestination** function searches the routing table for a destination with the next-best-match (longest) prefix, given a destination prefix. The requested destination information is returned.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestHandle` [in]

Handle to the destination.

### `ProtocolId` [in]

Specifies the protocol identifier. The *ProtocolID* is not part of the search criteria. The routing table manager uses this identifier to determine which route information to return. For example, if a client specifies the RIP protocol identifier, the best RIP route is returned, even if a non-RIP route is the best route to the destination.

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
| **ERROR_INVALID_PARAMETER** | A parameter contains incorrect information. |
| **ERROR_NOT_FOUND** | The next best destination cannot be found. |

## Remarks

The *DestInfo* parameter is a variable-sized
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure. If the client specifies more than one view using *TargetViews*, the size of *DestInfo* increases for each view. Use the
[RTM_SIZE_OF_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_size_of_dest_info) macro to determine how much memory to allocate for the *DestInfo* structure before calling this function. Use the value specified for *TargetViews* as a parameter to
**RTM_SIZE_OF_DEST_INFO**.

The
**RtmGetLessSpecificDestination** function is used after a call to
[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination) to return the next-best match for a destination. This call is also used after a prior call to
**RtmGetLessSpecificDestination** to return the next successive less-specific match. Clients can use this function to "walk up" the prefix tree for a destination.

This call is also used after calls to functions that return an
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure, such as
[RtmGetDestInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetdestinfo) and
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests).

The
**RtmGetLessSpecificDestination** function returns matches until it reaches the default route, if it exists. Once the default route is found,
**RtmGetLessSpecificDestination** returns ERROR_NOT_FOUND.

One common use for the
**RtmGetLessSpecificDestination** and
[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination) functions, is to retrieve each of the matching destinations.

For sample code using this function, see
[Search for Routes Using a Prefix Tree](https://learn.microsoft.com/windows/desktop/RRAS/search-for-routes-using-rtmgetmostspecificdestination-and-rtmgetlessspecificdestination).

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RtmGetExactMatchDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchdestination)

[RtmGetExactMatchRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetexactmatchroute)

[RtmGetMostSpecificDestination](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetmostspecificdestination)

[RtmIsBestRoute](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmisbestroute)