# _D3DDDIARG_CHECKMULTIPLANEOVERLAYSUPPORT structure

## Description

Used in a call to the [pfnCheckMultiPlaneOverlaySupport (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkmultiplaneoverlaysupport) function to check details on hardware support for multiplane overlays.

## Members

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input for which the hardware support is queried.

### `NumPlanes` [out]

The number of overlay planes that the hardware supports.

### `pPlanes` [out]

A pointer to a [D3DDDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO](https://learn.microsoft.com/windows-hardware/drivers/display/d3dddi-check-multiplane-overlay-support-plane-info) structure that specifies support attributes that the hardware provides for multiplane overlays.

### `Supported` [out]

**TRUE** if the hardware supports multiplane overlays, otherwise **FALSE**.

## See also

[D3DDDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO](https://learn.microsoft.com/windows-hardware/drivers/display/d3dddi-check-multiplane-overlay-support-plane-info)

[pfnCheckMultiPlaneOverlaySupport (D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkmultiplaneoverlaysupport)