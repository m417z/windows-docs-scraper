# RtmGetEnumDests function

## Description

The
**RtmGetEnumDests** function retrieves the next set of destinations in the specified enumeration.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EnumHandle` [in]

Handle to the destination enumeration.

### `NumDests` [in, out]

On input, *NumDests* is a pointer to a **UINT** value specifying the maximum number of destinations that can be received by *DestInfos*. On output, *NumDests* receives the actual number of destinations received by *DestInfos*.

### `DestInfos` [out]

On input, *DestInfos* is a pointer to an
[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info) structure.

On output, *DestInfos* receives an array of handles to destinations.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The value pointed to by *NumRoutes* is larger than the maximum number of routes a client is allowed to retrieve with one call. Check [RTM_REGN_PROFILE](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_regn_profile) for the maximum number of destinations that the client is allowed to retrieve with one call. |
| **ERROR_NO_MORE_ITEMS** | There are no more destinations to enumerate. |

## Remarks

The structure pointed to by *DestInfos* is a variable-sized structure. If the client specifies more than one view with *TargetViews*, the size of *DestInfos* increases for each view. Use the
[RTM_SIZE_OF_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtm_size_of_dest_info) macro to determine how large a *DestInfos* structure to allocate before calling this function. Use the value specified for *TargetViews* as a parameter to
**RTM_SIZE_OF_DEST_INFO**.

When the destinations are no longer required, release them by calling
[RtmReleaseDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedests).

For sample code using this function, see
[Enumerate All Destinations](https://learn.microsoft.com/windows/desktop/RRAS/enumerate-all-destinations).

## See also

[RTM_DEST_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_dest_info)

[RtmCreateDestEnum](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmcreatedestenum)

[RtmDeleteEnumHandle](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmdeleteenumhandle)

[RtmReleaseDests](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmreleasedests)