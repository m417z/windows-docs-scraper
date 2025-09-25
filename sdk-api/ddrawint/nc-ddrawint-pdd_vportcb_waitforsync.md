## Description

The *DdVideoPortWaitForSync* callback function waits until the next vertical synch occurs.

## Parameters

### `unnamedParam1`

Points to a [DD_WAITFORVPORTSYNCDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_waitforvportsyncdata) structure that contains the information required for the driver to synchronize the VPE object.

## Return value

*DdVideoPortWaitForSync* returns one of the following callback codes:

## Remarks

If the condition on which the driver is waiting does not occur before the number of milliseconds specified in the **dwTimeOut** member of the DD_WAITFORVPORTSYNCDATA structure at *lpWaitForSync* has elapsed, the driver should set the **ddRVal** member of [DD_WAITFORVPORTSYNCDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_waitforvportsyncdata) to DDERR_VIDEONOTACTIVE and return DDHAL_DRIVER_HANDLED.

The driver must specify its own time-out criteria when **dwTimeOut** is zero.

## See also

[DD_WAITFORVPORTSYNCDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_waitforvportsyncdata)