# _DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT structure

## Description

Used in a call to the [pfnCheckMultiPlaneOverlaySupport (DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions) function to check details on hardware support for multiplane overlays.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver performs the presentation. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input for which the hardware support is queried.

### `NumPlaneInfo` [out]

The number of overlay planes that the hardware supports.

### `pPlaneInfo` [out]

A pointer to a [DXGI_DDI_CHECK_MULTIPLANEOVERLAYSUPPORT_PLANE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_check_multiplaneoverlaysupport_plane_info) structure that specifies support attributes that the hardware provides for multiplane overlays.

### `Supported` [out]

**TRUE** if the hardware supports multiplane overlays, otherwise **FALSE**.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[DXGI_DDI_CHECK_MULTIPLANEOVERLAYSUPPORT_PLANE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_check_multiplaneoverlaysupport_plane_info)

[pfnCheckMultiPlaneOverlaySupport (DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_2_ddi_base_functions)