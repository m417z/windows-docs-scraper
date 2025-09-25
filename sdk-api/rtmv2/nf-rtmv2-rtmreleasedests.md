# RtmReleaseDests function

## Description

The
**RtmReleaseDests** function releases the destination handles.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NumDests` [in]

Specifies the number of destinations in *DestInfos*.

### `DestInfos` [in]

Pointer to an array of
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structures to release. The destinations were obtained from a previous call to
[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests).

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

Do not use this function to release
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structures obtained from a call to
[RtmGetChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetchangeddests). Use
[RtmReleaseChangedDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasechangeddests) instead.

The
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure is a variable-sized structure. If a destination contains information for more than one view, the size of
**RTM_DEST_INFO** increases for each view. Use the
[RTM_SIZE_OF_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_size_of_dest_info) macro to determine how large a *DestInfos* buffer to allocate before calling this function.

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RtmCreateDestEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatedestenum)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmGetEnumDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumdests)