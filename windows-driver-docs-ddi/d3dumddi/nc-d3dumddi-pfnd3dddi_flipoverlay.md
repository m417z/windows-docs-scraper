# PFND3DDDI_FLIPOVERLAY callback function

## Description

The *FlipOverlay* function causes the overlay hardware to start displaying the given new allocation.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_flipoverlay) structure that describes the new allocation to display by using the overlay.

## Return value

*FlipOverlay* returns S_OK or an appropriate error result if the new allocation is not successfully displayed.

## Remarks

Overlays are independent from the resources that are displayed by using the overlays.

## See also

[D3DDDIARG_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_flipoverlay)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)