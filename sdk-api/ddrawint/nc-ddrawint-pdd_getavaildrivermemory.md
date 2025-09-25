## Description

The **DdGetAvailDriverMemory** callback function queries the amount of free memory in the driver-managed memory heap.

## Parameters

### `unnamedParam1`

Points to a [DD_GETAVAILDRIVERMEMORYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getavaildrivermemorydata) structure that contains the information required to perform the query.

## Return value

**DdGetAvailDriverMemory** returns one of the following callback codes:

## Remarks

This function does not need to be implemented if the memory will be managed by DirectDraw.

**DdGetAvailDriverMemory** determines how much free memory is in the driver's private heaps for the specified surface type. The driver should check the surface capabilities specified in the **DDSCaps** member of the following structure against the heaps it is maintaining internally, to determine what heap size to query. For example, if DDSCAPS_NONLOCALVIDMEM is set, the driver should return only contributions from the AGP heaps.

The driver indicates its support of **DdGetAvailDriverMemory** by implementing a response to GUID_MiscellaneousCallbacks in [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo).

## See also

[DD_GETAVAILDRIVERMEMORYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getavaildrivermemorydata)

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)