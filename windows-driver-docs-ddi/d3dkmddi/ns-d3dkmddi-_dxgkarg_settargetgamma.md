# _DXGKARG_SETTARGETGAMMA structure

## Description

Used to hold the arguments for [DXGKDDI_SETTARGETGAMMA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settargetgamma).

## Members

### `TargetId`

The identifier of a display adapter's video present target.

### `GammaRamp`

A [D3DKMDT_GAMMA_RAMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_gamma_ramp) struct which describes the type of gamma ramp to set and the buffer containing the ramp data.