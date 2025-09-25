# DD_FLIPVPORTDATA structure

## Description

The DD_FLIPVPORTDATA structure contains the information necessary for the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object to perform a flip.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_local) structure that is relevant to the current Microsoft DirectDraw process only.

### `lpVideoPort`

Points to a [DD_VIDEOPORT_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoport_local) structure that represents this VPE object.

### `lpSurfCurr`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure for the current surface; that is, the surface on which data is currently being written.

### `lpSurfTarg`

Points to a DD_SURFACE_LOCAL structure for the target surface; that is, the surface to which the driver should flip.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdVideoPortFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_flip) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `FlipVideoPort`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdVideoPortFlip](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_vportcb_flip)