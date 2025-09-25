# RtmReferenceHandles function

## Description

The
**RtmReferenceHandles** function increases the reference count for objects pointed to by one or more handles that the routing manager used to access those objects. A client should use this function when the client must keep a handle but release the rest of the information structure associated with the handle.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NumHandles` [in]

Specifies the number of handles in *RtmHandles*.

### `RtmHandles` [in]

Array of handles to increase the reference count for.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

A client must always call this function when caching a handle returned by the routing table manager. This notifies the routing table manager that it should not destroy the object the handle refers to until the handle is released by the client.

When a client must release the handle, the client must call the appropriate release function, based on the type of handle. For example, to release a route, call
[RtmReleaseRoutes](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseroutes).

## See also

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests)

[RtmReleaseDestInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedestinfo)

[RtmReleaseEntityInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseentityinfo)

[RtmReleaseNextHopInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasenexthopinfo)

[RtmReleaseRouteInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaserouteinfo)