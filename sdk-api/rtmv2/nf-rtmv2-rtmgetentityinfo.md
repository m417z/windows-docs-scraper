# RtmGetEntityInfo function

## Description

The
**RtmGetEntityInfo** function returns information about a previously registered client.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EntityHandle` [in]

Handle to the client for which to return information.

### `EntityInfo` [out]

On input, *EntityInfo* is a pointer to an
[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info) structure.

On output, *EntityInfo* receives the requested information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info)

[RtmReleaseEntityInfo](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleaseentityinfo)