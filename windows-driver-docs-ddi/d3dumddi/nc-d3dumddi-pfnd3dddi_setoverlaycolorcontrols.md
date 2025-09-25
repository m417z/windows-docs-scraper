# PFND3DDDI_SETOVERLAYCOLORCONTROLS callback function

## Description

The *SetOverlayColorControls* function changes color-control settings for the given overlay.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setoverlaycolorcontrols) structure that describes parameters for changing an overlay's color-control settings.

## Return value

*SetOverlayColorControls* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The color-control settings were successfully changed.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|
|E_OUTOFMEMORY|SetOverlayColorControls could not allocate the required memory for it to complete.|

## Remarks

The Microsoft Direct3D runtime calls the *SetOverlayColorControls* function to change the brightness, contrast, hue, saturation, sharpness, gamma, and color-enable settings that are associated with a specific overlay.

The runtime can also call *SetOverlayColorControls* for an overlay that is not yet visible. In this situation, when the **hOverlay** member of the [D3DDDIARG_SETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setoverlaycolorcontrols) structure pointed to by *pData* is set to **NULL**, the driver should store the supplied color-control settings and use them when an overlay that references the specified resource is created.

## See also

[D3DDDIARG_SETOVERLAYCOLORCONTROLS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setoverlaycolorcontrols)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)