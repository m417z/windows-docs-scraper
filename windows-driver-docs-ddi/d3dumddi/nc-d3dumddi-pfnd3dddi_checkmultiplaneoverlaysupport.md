# PFND3DDDI_CHECKMULTIPLANEOVERLAYSUPPORT callback function

## Description

Called by the Microsoft Direct3D runtime to check the details on hardware support for multiplane overlays.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pSupport* [in, out]

A pointer to a [D3DDDIARG_CHECKMULTIPLANEOVERLAYSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_checkmultiplaneoverlaysupport) structure that provides details on hardware support for multiplane overlays.

## Return value

If this routine succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[D3DDDIARG_CHECKMULTIPLANEOVERLAYSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_checkmultiplaneoverlaysupport)