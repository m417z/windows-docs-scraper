# _DDICHECKOVERLAYSUPPORTINPUT structure

## Description

The DDICHECKOVERLAYSUPPORTINPUT structure describes an overlay display mode that the user-mode display driver uses to verify overlay support.

## Members

### `OverlayWidth` [in]

The width of the overlay in pixels.

### `OverlayHeight` [in]

The height of the overlay in pixels.

### `OverlayFormat`

 [in] A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the overlay.

### `DisplayWidth` [in]

The screen width of the display in pixels.

### `DisplayHeight` [in]

The screen height of the display in pixels.

### `DisplayRefreshRate` [in]

The refresh rate of the display.

### `DisplayFormat` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the display.

### `DisplayScanLineOrdering` [in]

A [D3DDDI_SCANLINEORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_scanlineordering)-typed value that indicates how the scan lines are drawn on the display.

### `DisplayRotation` [in]

A [D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)-typed value that indicates how the display is oriented.

## Remarks

The runtime specifies a pointer to a DDICHECKOVERLAYSUPPORTINPUT structure in the **pInfo** member of the [D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) structure. The runtime also specifies the D3DDDICAPS_CHECKOVERLAYSUPPORT value in the **Type** member of D3DDDIARG_GETCAPS. The runtime specifies these values in a call to the user-mode display driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function to determine if the driver supports the overlay that DDICHECKOVERLAYSUPPORTINPUT describes. The driver's *GetCaps* returns a pointer to a D3DOVERLAYCAPS structure that contains information about the capabilities of the overlay through the **pData** member of D3DDDIARG_GETCAPS if the driver supports the overlay.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[D3DDDI_SCANLINEORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_scanlineordering)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)