# PFND3DDDI_GETOVERLAYCOLORCONTROLS callback function

## Description

The *GetOverlayColorControls* function retrieves color-control settings for the given overlay.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_GETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getoverlaycolorcontrols) structure that describes parameters for retrieving an overlay's color-control settings.

## Return value

*GetOverlayColorControls* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The color-control settings were successfully retrieved.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|GetOverlayColorControls could not allocate the required memory for it to complete.|

## Remarks

The Microsoft Direct3D runtime calls the *GetOverlayColorControls* function to return the current brightness, contrast, hue, saturation, sharpness, gamma, and color-enable settings that are associated with a specific overlay.

The runtime can also call *GetOverlayColorControls* for an overlay that is not yet visible. In this situation, when the **hOverlay** member of the [D3DDDIARG_GETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getoverlaycolorcontrols) structure pointed to by *pData* is set to **NULL**, the driver should return the default color-control settings of the overlay hardware.

## See also

[D3DDDIARG_GETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getoverlaycolorcontrols)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)