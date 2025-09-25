# RtmReleaseEntityInfo function

## Description

The
**RtmReleaseEntityInfo** function releases a client structure.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EntityInfo` [in]

Pointer to the handle to release. The handle was obtained with a previous call to
[RtmGetEntityInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetentityinfo).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info)

[RtmGetEntityInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetentityinfo)