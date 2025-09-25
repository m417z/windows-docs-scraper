# RtmReleaseEntities function

## Description

The
**RtmReleaseEntities** function releases the client handles returned by
[RtmGetRegisteredEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetregisteredentities).

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NumEntities` [in]

Specifies the number of clients in *EntityHandles*.

### `EntityHandles` [in]

Pointer to an array of client handles to release. The handles were obtained from a previous call to
[RtmGetRegisteredEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetregisteredentities).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RtmGetRegisteredEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetregisteredentities)