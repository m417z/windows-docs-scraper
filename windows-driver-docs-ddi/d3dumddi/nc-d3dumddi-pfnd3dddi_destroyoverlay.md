# PFND3DDDI_DESTROYOVERLAY callback function

## Description

The **DestroyOverlay** function disables the overlay hardware and frees the overlay handle.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_DESTROYOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroyoverlay) structure that contains the overlay handle.

## Return value

**DestroyOverlay** returns S_OK or an appropriate error result if the overlay hardware is not disabled.

## Remarks

Overlays are independent from the resources that are displayed by using the overlays.

## See also

[D3DDDIARG_DESTROYOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_destroyoverlay)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)