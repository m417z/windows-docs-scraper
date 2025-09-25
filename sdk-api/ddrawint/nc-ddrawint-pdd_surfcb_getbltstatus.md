## Description

The **DdGetBltStatus** callback function queries the blit status of the specified surface.

## Parameters

### `unnamedParam1`

Points to a [DD_GETBLTSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getbltstatusdata) structure that contains the information required to perform the blit status query.

## Return value

**DdGetBltStatus** returns one of the following callback codes:

## Remarks

The blit status that the driver returns is based on the **dwFlags** member of the structure that *lpGetBltStatus* points to, as follows:

* If the flag is DDGBS_CANBLT, the driver should determine whether the surface is currently involved in a flip. If a flip is not in progress and if the hardware is otherwise capable of currently accepting a blit request, the driver should return DD_OK in the **ddRVal** member of the structure that *lpGetBltStatus* points to. If a flip is in progress or if the hardware cannot currently accept another blit request, the driver should set the **ddRVal** member to DDERR_WASSTILLDRAWING.
* If the flag is DDGBS_ISBLTDONE, the driver should set **ddRVal** to DDERR_WASSTILLDRAWING if a blit is currently in progress; otherwise it should return DD_OK.

## See also

[DD_GETBLTSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getbltstatusdata)

[DdBlt](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_blt)