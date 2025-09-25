# RtmReleaseNextHops function

## Description

The
**RtmReleaseNextHops** function releases the next-hop handles.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `NumNextHops` [in]

Specifies the number of next hops in *NextHopHandles*.

### `NextHopHandles` [in]

Pointer to an array of next-hop handles to release. The handles were obtained with a previous call to
[RtmGetEnumNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumnexthops).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## See also

[RtmCreateNextHopEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatenexthopenum)

[RtmGetEnumNextHops](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetenumnexthops)