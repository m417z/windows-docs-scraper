# DXGI_DDI_MODE_DESC structure

## Description

The DXGI_DDI_MODE_DESC structure describes a display mode.

## Members

### `Width` [out]

The screen width of the display mode, in pixels.

### `Height` [out]

The screen height of the display mode, in pixels.

### `Format` [out]

A DXGI_FORMAT-typed value that indicates the pixel format of the display mode.

### `RefreshRate` [out]

A [DXGI_DDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_rational) structure that indicates the refresh rate of the display mode.

### `ScanlineOrdering` [out]

A [DXGI_DDI_MODE_SCANLINE_ORDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_scanline_order)-typed value that indicates how scan lines are ordered in the display mode.

### `Rotation` [out]

A [DXGI_DDI_MODE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_rotation)-typed value that identifies the orientation of the display mode.

### `Scaling` [out]

A [DXGI_DDI_MODE_SCALING](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_scaling)-typed value that identifies the scaling of the display mode.

## See also

[DXGI_DDI_MODE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_rotation)

[DXGI_DDI_MODE_SCALING](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_scaling)

[DXGI_DDI_MODE_SCANLINE_ORDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_mode_scanline_order)

[DXGI_DDI_PRIMARY_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_primary_desc)

[DXGI_DDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_rational)