# PFND3DDDI_UPDATEOVERLAY callback function

## Description

The *UpdateOverlay* function reconfigures or moves an overlay that is being displayed.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_updateoverlay) structure that describes how to reconfigure the overlay.

## Return value

*UpdateOverlay* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The overlay is successfully modified.|
|E_OUTOFMEMORY|UpdateOverlay could not complete because of insufficient memory.|
|D3DDDIERR_NOTAVAILABLE|UpdateOverlay could not complete because insufficient bandwidth was available or the requested overlay hardware was unavailable.|
|D3DDDIERR_UNSUPPORTEDOVERLAYFORMAT|The specified overlay format is not supported by the overlay hardware.|
|D3DDDIERR_UNSUPPORTEDOVERLAY|The overlay hardware is not supported for the specified size and display mode.|

## Remarks

Overlays are independent from the resources that are displayed by using the overlays.

## See also

[D3DDDIARG_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_updateoverlay)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)