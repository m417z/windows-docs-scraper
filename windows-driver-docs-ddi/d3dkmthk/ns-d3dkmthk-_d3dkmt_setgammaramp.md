# _D3DKMT_SETGAMMARAMP structure

## Description

The D3DKMT_SETGAMMARAMP structure describes parameters for setting the gamma ramp.

## Members

### `hDevice` [in]

A handle to the device.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology for the VidPN source.

### `Type` [in]

A [D3DDDI_GAMMARAMP_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_gammaramp_type)-typed value. This member can be one of the following: D3DDDI_GAMMARAMP_UNINITIALIZED (0), D3DDDI_GAMMARAMP_DEFAULT (1), D3DDDI_GAMMARAMP_RGB256x3x16 (2), or D3DDDI_GAMMARAMP_DXGI_1 (3).

### `pGammaRampRgb256x3x16` [in]

A pointer to a [D3DDDI_GAMMA_RAMP_RGB256x3x16](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_rgb256x3x16) structure. The union that is contained in D3DKMT_SETGAMMARAMP holds a structure of this type if the **Type** member is D3DDDI_GAMMARAMP_RGB256x3x16.

### `pGammaRampDXGI1` [in]

A pointer to a [D3DDDI_GAMMA_RAMP_DXGI_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_dxgi_1) structure. The union that is contained in D3DKMT_SETGAMMARAMP holds a structure of this type if the **Type** member is D3DDDI_GAMMARAMP_DXGI_1.

### `Size` [in]

The size of the D3DDDI_GAMMA_RAMP_RGB256x3x16 or D3DDDI_GAMMA_RAMP_DXGI_1 structure that [D3DDDI_GAMMA_RAMP_RGB256x3x16](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_rgb256x3x16) or [D3DDDI_GAMMA_RAMP_DXGI_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_dxgi_1) points to.

## See also

[D3DDDI_GAMMARAMP_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_gammaramp_type)

[D3DDDI_GAMMA_RAMP_DXGI_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_dxgi_1)

[D3DDDI_GAMMA_RAMP_RGB256x3x16](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_gamma_ramp_rgb256x3x16)

[D3DKMTSetGammaRamp](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetgammaramp)