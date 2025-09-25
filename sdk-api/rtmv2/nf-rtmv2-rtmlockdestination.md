# RtmLockDestination function

## Description

The
**RtmLockDestination** function locks or unlocks a destination in the routing table. Use this function to protect a destination while changing opaque pointers.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `DestHandle` [in]

Handle to the destination to lock.

### `Exclusive` [in]

Specifies whether to lock or unlock the destination in an exclusive (**TRUE**) or shared (**FALSE**) mode.

### `LockDest` [in]

Specifies whether to lock or unlock the destination. Specify **TRUE** to lock the destination; specify **FALSE** to unlock it.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling client does not own this destination. |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

This function also locks the associated routes. Avoid locking destinations for long periods of time, because no other client can access the destination and associated routes until the lock is released.

A client can also use this function when reading information for a destination, while preventing changes during the client's read operation. In this case, consider using
[RtmGetDestInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetdestinfo) instead.

For sample code using this function, see
[Update a Route In Place Using RtmUpdateAndUnlockRoute](https://learn.microsoft.com/windows/desktop/RRAS/update-a-route-in-place-using-rtmupdateandunlockroute).

## See also

[RtmGetOpaqueInformationPointer](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetopaqueinformationpointer)