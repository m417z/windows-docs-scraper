# PFND3DDDI_CREATEOVERLAY callback function

## Description

The **CreateOverlay** function allocates overlay hardware and makes the overlay visible.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createoverlay) structure that describes the overlay.

## Return value

**CreateOverlay** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The overlay is successfully created. |
| **E_OUTOFMEMORY** | [CreateOverlay]() could not complete because of insufficient memory. |
| **D3DDDIERR_NOTAVAILABLE** | [CreateOverlay]() could not complete because insufficient bandwidth was available or the requested overlay hardware was unavailable. |
| **D3DDDIERR_UNSUPPORTEDOVERLAYFORMAT** | The specified overlay format is not supported by the overlay hardware. |
| **D3DDDIERR_UNSUPPORTEDOVERLAY** | The overlay hardware is not supported for the specified size and display mode. |

## Remarks

Overlays are independent from the resources that are displayed by using the overlays.

## See also

[D3DDDIARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createoverlay)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)