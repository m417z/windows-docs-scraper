# DD_QUERYMOCOMPSTATUSDATA structure

## Description

The DD_QUERYMOCOMPSTATUSDATA structure contains information required to query the status of the previous frame.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpMoComp`

Points to a [DD_MOTIONCOMP_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncomp_local) structure that contains a description of the motion compensation being requested.

### `lpSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that contains the surface being queried.

### `dwFlags`

Indicates the type of surface access.

#### DDMCQUERY_READ

Indicates that the surface can only be tested for read or display access. If this flag is not set, the surface can be tested for write access.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdMoCompQueryStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_querystatus) callback. A return code of DD_OK indicates the hardware has finished processing the [DdMoCompRender](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_render) request. Otherwise the return value must be DDERR_WASSTILLDRAWING. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## See also

[DdMoCompQueryStatus](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_querystatus)

[DdMoCompRender](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_mocompcb_render)