# RtmGetDestInfo function

## Description

The
**RtmGetDestInfo** function returns information about a destination.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestHandle` [in]

Handle to the destination for which to return information.

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
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

The structure pointed to by *DestInfo* is a variable-sized structure. If the client specifies more than one view with *TargetViews*, the size of *DestInfo* increases for each view. Use the
[RTM_SIZE_OF_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_size_of_dest_info) macro to determine how large a *DestInfo* structure to allocate before calling this function. Use the value specified for *TargetViews* as a parameter to
**RTM_SIZE_OF_DEST_INFO**.

Use
[RtmReleaseDestInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedestinfo) to release the *DestInfo* buffer.

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RtmReleaseDestInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedestinfo)