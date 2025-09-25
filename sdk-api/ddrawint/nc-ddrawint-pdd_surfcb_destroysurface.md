## Description

The **DdDestroySurface** callback function destroys a DirectDraw surface.

## Parameters

### `unnamedParam1`

Points to a [DD_DESTROYSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_destroysurfacedata) structure that contains the information needed to destroy a surface.

## Return value

**DdDestroySurface** returns one of the following callback codes:

## Remarks

If DirectDraw did the memory allocation at surface creation time and the driver was not involved in the allocation, DirectDraw does not call the driver's **DdDestroySurface** function to destroy the surface.

If the driver is performing the surface memory management itself, **DdDestroySurface** should free the surface memory and perform any other cleanup, such as freeing private data stored in the **dwReserved1** members of the [DD_SURFACE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_global) and [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structures.

For a driver-managed surface, if the surface is persistent (that is, the DDSCAPS2_DONOTPERSIST flag in the **dwCaps2** member of the [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure for the surface is not set), **DdDestroySurface** can be called with the purpose of evicting the surface from video memory. In this case, the display driver can continue to keep any private data in the **dwReserved1** members until **DdDestroySurface** is called to actually destroy the surface.

**DdDestroySurface** can be called with a disabled [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). PDEV is disabled or enabled by calling the display driver's [DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode) function. See [Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs) for more information.

## See also

[DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85))

[DD_DESTROYSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_destroysurfacedata)

[DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85))