# RtmBlockMethods function

## Description

The
**RtmBlockMethods** function blocks or unblocks the execution of methods for a specified destination, route, or next hop, or for all destinations, routes, and next hops.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `TargetHandle` [in]

Handle to a destination, route, or next hop for which to block methods. This parameter is optional and can be set to **NULL** to block methods for all targets.

### `TargetType` [in]

Specifies the type of the handle in *TargetHandle*. This parameter is optional and can be set to **NULL** to block methods for all targets. The following flags are used.

| Type | Meaning |
| --- | --- |
| **DEST_TYPE** | *TargetHandle* is a destination. |
| **NEXTHOP_TYPE** | *TargetHandle* is a next hop. |
| **ROUTE_TYPE** | *TargetHandle* is a route. |

### `BlockingFlag` [in]

Specifies whether to block or unblock methods. The following flags are used.

| Constant | Meaning |
| --- | --- |
| **RTM_BLOCK_METHODS** | Block methods for the specified target. |
| **RTM_RESUME_METHODS** | Unblock methods for the specified target. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is the following error code.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

Currently, this function does not support blocking methods for a specific destination, route, or next hop.

Methods are typically blocked when client-specific data in the route is being changed; a client blocks methods, rearranges data, and then unblocks methods.

Clients should only block methods for a short period of time. If a second client calls
[RtmInvokeMethod](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminvokemethod) and the first client's methods are blocked,
**RtmInvokeMethod** does not return until methods are unblocked and the function call is completed.

## See also

[RtmGetEntityMethods](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetentitymethods)

[RtmInvokeMethod](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminvokemethod)