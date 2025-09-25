# DD_NTPRIVATEDRIVERCAPS structure

## Description

The DD_NTPRIVATEDRIVERCAPS structure enables the driver to change the behavior of Microsoft DirectDraw when DirectDraw is creating surfaces.

## Members

### `dwSize`

Specifies the size in bytes of this DD_NTPRIVATEDRIVERCAPS structure.

### `dwPrivateCaps`

Indicates how DirectDraw should create the surface.

#### DDHAL_PRIVATECAP_AUTOMICSURFACECREATION

When this flag is set, it indicates that the driver requests [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) to be called only once when the application creates a complex flipping chain using a single **CreateSurface** call. In this case, the **lplpSList** member of the [DD_CREATESURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createsurfacedata) structure points to a list of surfaces to create (rather than a single surface) and **dwSCnt** contains the number of surfaces in the list.

#### DDHAL_PRIVATECAP_NOTIFYPRIMARYCREATION

When this flag is set, the driver's [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) function is called when creating a primary surface. If this flag is not set, the driver's *DdCreateSurface* function is not called.

## Remarks

The behavior of DirectDraw emulates the surface creation techniques employed by DirectDraw when creating surfaces for Microsoft Windows 98/Me.

When the DDHAL_PRIVATECAP_AUTOMICSURFACECREATION flag is not set, DirectDraw performs surface creation using the original method, that is, it calls the driver's [DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85)) function once for each surface being created.

When the DDHAL_PRIVATECAP_NOTIFYPRIMARYCREATION flag is not set, DirectDraw performs primary surface creation using the original method, that is, it does not call the driver when creating a primary surface.

## See also

[DD_CREATESURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createsurfacedata)

[DdCreateSurface](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff549263(v=vs.85))