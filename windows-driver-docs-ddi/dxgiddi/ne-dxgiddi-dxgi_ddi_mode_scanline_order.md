# DXGI_DDI_MODE_SCANLINE_ORDER enumeration

## Description

The DXGI_DDI_MODE_SCANLINE_ORDER enumeration type contains values that identify how scan lines are ordered in a display mode.

## Constants

### `DXGI_DDI_MODE_SCANLINE_ORDER_UNSPECIFIED`

A DXGI_DDI_MODE_SCANLINE_ORDER-typed variable has not yet been assigned a meaningful value.

### `DXGI_DDI_MODE_SCANLINE_ORDER_PROGRESSIVE`

Each field contains an entire frame.

### `DXGI_DDI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST`

Each field contains half of a frame, and the odd scan lines are displayed first.

### `DXGI_DDI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST`

Each field contains half of a frame, and the even scan lines are displayed first.

## Remarks

The values of the DXGI_DDI_MODE_SCANLINE_ORDER enumeration type indicate whether the image that is displayed on the monitor contains the entire content of a video frame or only half of the content (that is, either the even or odd scan lines, which occur interchangeably). The values also indicate which field comes first in the order.

## See also

[DXGI_DDI_MODE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_mode_desc)