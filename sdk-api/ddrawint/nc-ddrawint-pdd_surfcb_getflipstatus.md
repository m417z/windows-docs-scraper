## Description

The **DdGetFlipStatus** callback function determines whether the most recently requested flip on a surface has occurred.

## Parameters

### `unnamedParam1`

Points to a [DD_GETFLIPSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getflipstatusdata) structure that contains the information required to perform the flip status query.

## Return value

**DdGetFlipStatus** returns one of the following callback codes:

## Remarks

The driver should report its flip status based on the flag set in the **dwFlags** member of the structure that **lpGetFlipStatus** points to as follows:

* If the flag is DDGFS_CANFLIP, the driver should determine whether the surface is currently involved in a flip. If a flip or a blit is not in progress and if the hardware is otherwise capable of currently accepting a flip request, the driver should return DD_OK in **ddRVal**. If a flip is in progress or if the hardware cannot currently accept a flip request, the driver should set **ddRVal** to DDERR_WASSTILLDRAWING.
* If the flag is DDGFS_ISFLIPDONE, the driver should set **ddRVal** to DDERR_WASSTILLDRAWING if a flip is currently in progress; otherwise it should return DD_OK.

## See also

[DD_GETFLIPSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getflipstatusdata)