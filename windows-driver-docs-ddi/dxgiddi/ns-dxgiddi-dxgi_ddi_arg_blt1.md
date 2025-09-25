# DXGI_DDI_ARG_BLT1 structure

## Description

Describes the parameters of a bit-block transfer (bitblt) that include specifications for a source rectangle. Used by Windows Display Driver Model (WDDM) 1.2 and later user-mode display drivers.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver performs the bitblt. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `hDstResource` [in]

A handle to the destination resource.

### `DstSubresource` [in]

The index to the destination surface within the resource.

### `DstLeft` [in]

The *x*-coordinate of the upper-left corner of the destination rectangle.

### `DstTop` [in]

The *y*-coordinate of the upper-left corner of the destination rectangle.

### `DstRight` [in]

The *x*-coordinate of the lower-right corner of the destination rectangle.

### `DstBottom` [in]

The *y*-coordinate of the lower-right corner of the destination rectangle.

### `hSrcResource` [in]

A handle to the source resource.

### `SrcSubresource` [in]

The index to the source surface within the resource.

### `SrcLeft` [in]

The *x*-coordinate of the upper-left corner of the source rectangle.

### `SrcTop` [in]

The *y*-coordinate of the upper-left corner of the source rectangle.

### `SrcRight` [in]

The *x*-coordinate of the lower-right corner of the source rectangle.

### `SrcBottom` [in]

The *y*-coordinate of the lower-right corner of the destination rectangle.

### `Flags` [in]

A [DXGI_DDI_ARG_BLT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt_flags) structure that identifies the type of bitblt to perform.

### `Rotate` [in]

A value of type [DXGI_DDI_MODE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_rotation) that identifies the orientation of the display mode.

## Remarks

The source rectangle specified by the members **SrcLeft**, **SrcTop**, **SrcRight**, and **SrcBottom** is typically a dirty subrectangle.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[DXGI_DDI_ARG_BLT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_blt_flags)

[DXGI_DDI_MODE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_rotation)